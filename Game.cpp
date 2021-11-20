#include "Game.h"

Game::Game(sf::RenderWindow* window, sf::View view)
{
	background.setSize({ 4608.f, 4608.f });
	background.setOrigin(background.getSize().x / 2, background.getSize().y / 2);
	background.setPosition(720.f, 450.f);
	backgroundTexture.loadFromFile("Texture/Map/Background.png");
	background.setTexture(&backgroundTexture);

	font.loadFromFile("Font/Notalot60.ttf");

	enemyHp.setFont(font);
	enemyHp.setCharacterSize(16);
	enemyHp.setFillColor(sf::Color::White);

	maxPlayerHp = 100.f;
	currentPlayerHp = maxPlayerHp;

	enableToAttack = true;
	duringWave = false;

	this->window = window;
	this->view = view;
}

void Game::pollEvent()
{
	//WEAPON SWITCH
	if (attackCooldown)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			currentSlot = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) &&
			weaponSlot[1] != 0)
			currentSlot = 1;
	}

	//ATTACK
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
		playerWeapon != NOTHING && enableToAttack &&
		!player.attackingCheck())
	{
		player.setMoving(false);
		player.attacking();
	}
}

void Game::screenUIupdate()
{
	gui.screenUI(player.getPos(), exp, maxExp, wave, weaponSlot[0],weaponSlot[1],
		weaponDamage[currentSlot], playerBaseDamage, currentPlayerHp, maxPlayerHp,
		currentSlot, spawningTime, duringWave, attackCooldown,score);
}

void Game::takeItemUpdate()
{
	pickingTime += deltatime;
	for (size_t i = 0; i < drop.size(); i++)
	{
		//ITEM EXPIRING
		if (drop[i]->getTime() >= 15)
			drop.erase(drop.begin() + i);

		//ITEM PICKING
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)
			&& drop[i]->getBound().intersects(player.getBound()))
		{
			if (pickingTime >= 2.f)
			{
				if (weaponSlot[0] == 0)
				{
					weaponSlot[0] = drop[i]->getWeaponType();
					currentSlot = 0;
					weaponDamage[0] = drop[i]->getDamage();
					pickingTime = 0;
				}
				else if (weaponSlot[1] == 0)
				{
					weaponSlot[1] = drop[i]->getWeaponType();
					currentSlot = 1;
					weaponDamage[1] = drop[i]->getDamage();
					pickingTime = 0;
				}
				else
				{
					drop.push_back(new ItemDrop(weaponSlot[currentSlot],
						weaponDamage[currentSlot], true, player.getPos()));
					weaponSlot[currentSlot] = drop[i]->getWeaponType();
					weaponDamage[currentSlot] = drop[i]->getDamage();
					pickingTime = 0;
				}
				drop.erase(drop.begin() + i);
			}	
		}
	}
}

void Game::attackUpdate()
{
	std::cout << attackingTime << std::endl;
	enableToAttack = false;

	if (playerWeapon == SWORD)
		attackTimerMax = 1.f;
	if (playerWeapon == HAMMER)
		attackTimerMax = 1.5f;

	//ATTACK COOLDOWN
	if (attackingTime >= attackTimerMax)
	{
		attackCooldown = true;
		if (weaponSlot[currentSlot] != 0)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				attackCooldown = false;
				attackingTime = 0;
			}
			if (!attackCooldown)
			{
				enableToAttack = true;
			}
		}

		//SUICIDE DEBUG
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			attackCooldown = false;
			attackingTime = 0;
			currentPlayerHp -= 50;
			drop.push_back(new ItemDrop(weaponSlot[currentSlot],
				weaponDamage[currentSlot], true, player.getPos()));
		}
	}
	else
		attackingTime += deltatime;
}

void Game::playerAttackRange()
{
	weaponHitbox.setHitbox(player.getPos().x,
		player.getPos().y, weaponSlot[currentSlot],
		player.getPlayerState(), player.movingCheck());
}

void Game::playerAttack()
{
	if (player.attackingCheck())
	{
		for (size_t i = 0; i < enemies.size(); i++)
		{
			//IF ENEMIES STILL ALIVE
			if (enemies[i]->getHp() > 0 && enemies[i]->getBound().intersects(weaponHitbox.getBound()))
				enemies[i]->takeDamage(weaponDamage[currentSlot] + playerBaseDamage, weaponSlot[currentSlot]);
			//IF ENEMIES DIE
			if (enemies[i]->getHp() <= 0)
			{
				exp += enemies[i]->getEXP();
				if (!enemies[i]->bossCheck())
					score += 10;
				else
					score += 50;

				//DROP
				if (enemies[i]->bossCheck() || rand() % 10 < 1)
					drop.push_back(new ItemDrop(wave, enemies[i]->getMaxHp(), false, enemies[i]->getPos()));
				enemies.erase(enemies.begin() + i);

				killCount++;
				enemyLeft--;
			}
		}
	}
}

void Game::playerLevelUpdate()
{

	maxExp = 12 * playerLevel;
	playerBaseDamage = 5 + playerLevel;

	//LEVEL UP
	if (exp >= maxExp)
	{
		exp = 0;
		playerLevel++;
		maxPlayerHp = 95 + (playerLevel * 5);
		currentPlayerHp = maxPlayerHp;
	}

	//DEAD
	if (currentPlayerHp <= 0 && !player.deadCheck())
	{
		currentPlayerHp = 0;
		player.isDead();
	}
	if (player.deadCheck())
	{
		gameOverTime += deltatime;
		if (gameOverTime >= 3.f)
		{
			gameOver = true;
		}
	}

}

void Game::waveUpdate()
{
	//DURING WAVE
	if (spawningTime >= 6.f && !duringWave)
	{
		wave++;
		if (wave % 5 != 0)
			spawner = "01010101";// 0 = EGG, 1 = CHICKEN
		else
			spawner = "01010102";// 2 = BIG ONE
		for (size_t i = 0; i < 8; i++)
		{
			enemyType = spawner[i];
			enemies.push_back(new Enemy(enemyType, rand() % 1440 + 1,
				rand() % 900 + 1, wave));
			enemyLeft++;
		}
		duringWave = true;
	}

	//AFTER THE WAVE END
	else if (enemyLeft == 0 && duringWave == true)
	{
		duringWave = false;
		deltatime = 0;
	}

	if (duringWave)
		spawningTime = 0;
	else
		spawningTime += deltatime;

}

void Game::enemyUpdate()
{
	for (size_t i = 0; i < enemies.size(); i++)
	{
		//UPDATE
		enemies[i]->update();
		enemies[i]->movement(player.getPos(), weaponHitbox.getPos(), player.getBound());

		//ENEMIES DAMAGE PLAYER
		if (enemies[i]->getHitBoxBound().intersects(player.getBound()))
		{
			if (!enemies[i]->enemyAttackCooldown() && !player.deadCheck())
			{
				enemies[i]->doDamage(currentPlayerHp);
				player.knockBack(enemies[i]->getNormalizedDir());
			}
		}

		//ENEMIES COLLISION CHECK
		enemies[i]->checkObstruct(enemies[i]->getBound(), player.getBound());
		for (size_t j = 0; j < i; j++)
		{
			if (i != j)
				enemies[i]->checkObstruct(enemies[i]->getBound(), enemies[j]->getBound());
		}

	}
}

void Game::itemDropUpdate()
{
	for (size_t i = 0; i < drop.size(); i++)
	{
		drop[i]->update();
	}
}

void Game::update()
{
	player.update();
	pollEvent();
	playerLevelUpdate();
	playerAttackRange();
	playerAttack();
	takeItemUpdate();
	attackUpdate();
	itemDropUpdate();
	waveUpdate();
	enemyUpdate();
	screenUIupdate();
	playerWeapon = weaponSlot[currentSlot];
	deltatime = gameClock.restart().asSeconds();
}

void Game::render()
{
	window->clear();

	//VIEW
	view.setCenter(player.getPos());
	window->setView(view);

	//BACKGROUND
	window->draw(background);

	//DROP
	for (size_t i = 0; i < drop.size(); i++)
	{
		drop[i]->render(*window);
	}

	//HITBOX
	weaponHitbox.render(*window);

	//ENEMIES
	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i]->render(*window);
	}
	for (size_t i = 0; i < enemies.size(); i++)
	{
		gui.enemyUI(enemies[i]->getHp(), enemies[i]->getMaxHp(),
			enemies[i]->getPos(), enemies[i]->getSize(), *window);
	}

	//PLAYER
	player.render(*window);

	gui.render(*window);

	window->display();
}

void Game::gameReset()
{
	player.reset();
	gui.reset();
	gameClock.restart().asSeconds();
	player.animationReset();

	currentSlot = 0;
	weaponSlot[0] = 1;
	weaponSlot[1] = 0;
	weaponDamage[0] = 900;
	weaponDamage[1] = 0;

	playerLevel = 1;
	maxPlayerHp = 100.f;
	currentPlayerHp = maxPlayerHp;
	exp = 0;

	playerWeapon = SWORD;

	wave = 0;
	enemyLeft = 0;
	killCount = 0;
	spawnCount = 0;
	score = 0;

	duringWave = false;
	gameOver = false;

	deltatime = 0;
	pickingTime = 0;
	attackingTime = 0;
	gameOverTime = 0;
	spawningTime = 0;

	drop.clear();
	enemies.clear();
}

void Game::pauseRender()
{
	window->clear();
	//VIEW
	view.setCenter(player.getPos());
	window->setView(view);

	//BACKGROUND
	window->draw(background);

	//DROP
	for (size_t i = 0; i < drop.size(); i++)
	{
		drop[i]->render(*window);
	}

	//HITBOX
	weaponHitbox.render(*window);

	//ENEMIES
	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i]->render(*window);
	}
	for (size_t i = 0; i < enemies.size(); i++)
	{
		gui.enemyUI(enemies[i]->getHp(), enemies[i]->getMaxHp(),
			enemies[i]->getPos(), enemies[i]->getSize(), *window);
	}

	//PLAYER
	player.render(*window);

	gui.render(*window);
}
