#include "Game.h"

Game::Game(sf::RenderWindow* window, sf::View view)
{
	background.setSize({ 2048.f, 2048.f });
	background.setOrigin(background.getSize().x / 2, background.getSize().y / 2);
	background.setPosition(720.f, 450.f);
	backgroundTexture.loadFromFile("Texture/Map/Background.png");
	background.setTexture(&backgroundTexture);

	spawnTimerMax = 10.f;

	font.loadFromFile("Font/Retro Gaming.ttf");

	enemyHp.setFont(font);
	enemyHp.setCharacterSize(16);
	enemyHp.setFillColor(sf::Color::White);

	maxPlayerHp = 100.f;
	currentPlayerHp = maxPlayerHp;

	duringWave = false;

	this->window = window;
	this->view = view;
}

void Game::pollEvent()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		currentSlot = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		currentSlot = 1;
}

void Game::screenUIupdate()
{
	gui.screenUI(player.getPos(), exp, maxExp, wave, weaponSlot[currentSlot],
		weaponDamage[currentSlot], playerBaseDamage, currentPlayerHp, maxPlayerHp, currentSlot);
}

void Game::takeItemUpdate()
{
	for (size_t i = 0; i < drop.size(); i++)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)
			&& drop[i]->getBound().intersects(player.getBound()))
		{
			if (weaponSlot[0] == 0)
			{
				weaponSlot[0] = drop[i]->getType();
				currentSlot = 0;
				weaponDamage[0] = drop[i]->getDamage();
			}
			else if (weaponSlot[1] == 0)
			{
				weaponSlot[1] = drop[i]->getType();
				currentSlot = 1;
				weaponDamage[1] = drop[i]->getDamage();
			}
			else
			{
				weaponSlot[currentSlot] = drop[i]->getType();
				weaponDamage[currentSlot] = drop[i]->getDamage();
			}
			drop.erase(drop.begin() + i);
		}
	}
}

void Game::attackUpdate()
{
	attackTimer = attackCoolDownClock.getElapsedTime().asSeconds();
	enableToAttack = false;
	if (playerWeapon == DAGGER)
		attackTimerMax = 0.5f;
	if (playerWeapon == SWORD)
		attackTimerMax = 1.f;

	if (attackTimer >= attackTimerMax)
	{
		std::cout << "Enable to Attack" << std::endl;
		attackCooldown = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			attackCooldown = false;
			attackCoolDownClock.restart();
		}
		if (!attackCooldown)
		{
			enableToAttack = true;
		}
		//Suicide debug
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			attackCooldown = false;
			attackCoolDownClock.restart();
			currentPlayerHp -= 5;
		}
	}
	else
	{
		std::cout << "Unable to Attack" << std::endl;
	}
}

void Game::playerAttackRange()
{
	weaponHitbox.setHitbox(player.getPos().x + 8,
		player.getPos().y + 8, weaponSlot[currentSlot], player.getPlayerState());
}

void Game::playerLevelUpdate()
{
	maxExp = 12 * playerLevel;
	playerBaseDamage = 2 + playerLevel;

	if (exp >= maxExp)
	{
		exp = 0;
		playerLevel++;
		maxPlayerHp = 95 + (playerLevel * 5);
		currentPlayerHp = maxPlayerHp;
	}


	if (currentPlayerHp <= 0)
		gameOver = true;

}

void Game::waveUpdate()
{
	spawnTimer = enemySpawningClock.getElapsedTime().asSeconds();

	if (spawnTimer >= 2.f && !duringWave)
	{
		wave++;
		if (wave % 5 != 0)
			spawner = "00000000";
		else
			spawner = "00010000";
		for (size_t i = 0; i < 8; i++)
		{
			enemyType = spawner[i];
			enemies.push_back(new Enemy(enemyType, rand() % 1440 + 1,
				rand() % 900 + 1, wave));
			enemyLeft++;
		}
		duringWave = true;
	}
	else if (enemyLeft == 0 && duringWave == true)
	{
		duringWave = false;
		enemySpawningClock.restart();
	}
}

void Game::enemyUpdate()
{
	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i]->update();
		enemies[i]->movement(player.getPos(), weaponHitbox.getPos());

		//do damage to player
		if (enemies[i]->getHitBoxBound().intersects(player.getBound()))
		{
			enemies[i]->doDamage(currentPlayerHp);
			if(!enemies[i]->enemyAttackCooldown())
				player.knockBack(enemies[i]->getNormalizedDir());
		}

		//collision check
		enemies[i]->checkObstruct(enemies[i]->getBound(), player.getBound());
		for (size_t j = 0; j < i; j++)
		{
			if (i != j)
				enemies[i]->checkObstruct(enemies[i]->getBound(), enemies[j]->getBound());
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
		playerWeapon != NOTHING && enableToAttack)
	{
		for (size_t i = 0; i < enemies.size(); i++)
		{
			if (enemies[i]->getHp() > 0 && enemies[i]->getBound().intersects(weaponHitbox.getBound()))
				enemies[i]->takeDamage(weaponDamage[currentSlot] + playerBaseDamage);
			if (enemies[i]->getHp() <= 0)
			{
				exp += enemies[i]->getEXP();
				if(enemies[i]->getType() == 1)
					drop.push_back(new ItemDrop(enemies[i]->getType(), wave, enemies[i]->getPos()));
				else if (enemies[i]->getType() != 1 && rand() % 10 + 1 == 2)
					drop.push_back(new ItemDrop(enemies[i]->getType(), wave, enemies[i]->getPos()));
				enemies.erase(enemies.begin() + i);
				killCount++;
				enemyLeft--;
			}
		}
	}

}

void Game::update()
{
	player.update();

	pollEvent();
	screenUIupdate();
	takeItemUpdate();
	playerAttackRange();
	playerLevelUpdate();
	attackUpdate();
	waveUpdate();
	enemyUpdate();

	playerWeapon = weaponSlot[currentSlot];

	std::cout << "PlayerLevel : " << playerLevel << " | ";
	std::cout << "KillCount : " << killCount << " | ";
	std::cout << "EnemyLeft : " << enemyLeft << std::endl;
	std::cout << currentPlayerHp << " : " << maxPlayerHp << std::endl;

}

void Game::render()
{
	window->clear();

	view.setCenter(player.getPos());
	window->setView(view);

	window->draw(background);

	for (size_t i = 0; i < drop.size(); i++)
	{
		drop[i]->render(*window);
	}

	player.render(*window);
	weaponHitbox.render(*window);

	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i]->render(*window);
		gui.enemyUI(enemies[i]->getHp(), enemies[i]->getMaxHp(),
			enemies[i]->getPos(), enemies[i]->getSize(), *window);
	}

	gui.render(*window);

	window->display();
}

void Game::gameReset()
{
	player.reset();
	enemySpawningClock.restart();
	spawnTimer = 0;
	spawnTimerMax = 100.f;

	currentSlot = 0;
	weaponSlot[0] = 1;
	weaponSlot[1] = 0;
	weaponDamage[0] = 900;
	weaponDamage[1] = 0;

	playerLevel = 1;
	maxPlayerHp = 100.f;
	currentPlayerHp = maxPlayerHp;
	exp = 0;

	playerWeapon = DAGGER;

	wave = 0;
	enemyLeft = 0;
	killCount = 0;
	spawnCount = 0;

	duringWave = false;
	gameOver = false;

	drop.clear();
	enemies.clear();
}