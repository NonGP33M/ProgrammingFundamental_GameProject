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

void Game::timeTicking(float deltatime)
{
	this->deltatime = 0;
	this->deltatime += deltatime;
	attackingTimer += deltatime;
	pickingTime += deltatime;
	spawningTime += deltatime;
	if (player.deadCheck())
		gameOverTime += deltatime;
	player.timeTicking(deltatime);
}

void Game::pollEvent()
{
	if (enableToAttack)
	{
		//WEAPON SWITCH
		if (!player.knockingBackCheck())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
				currentSlot = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) &&
				weaponSlot[1] != 0)
				currentSlot = 1;
		}

		//ATTACK
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
			playerWeapon != NOTHING &&
			!player.attackingCheck())
		{
			player.setMoving(false);
			player.attacking();
		}
	}
	player.changeWeapon(weaponSlot[currentSlot]);

}

void Game::screenUIupdate()
{
	gui.screenUI(player.getPos(), exp, maxExp, wave, weaponSlot[0], weaponSlot[1],
		weaponDamage[currentSlot], playerBaseDamage, currentPlayerHp, maxPlayerHp,
		currentSlot, spawningTime, duringWave, enableToAttack, score,
		player.knockingBackCheck(),enemyLeft);
}

void Game::takeItemUpdate()
{
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
	playerWeapon = weaponSlot[currentSlot];
	if (playerWeapon == SWORD)
		attackTimerMax = 1.f;
	if (playerWeapon == HAMMER)
		attackTimerMax = 1.5f;

	//ATTACK COOLDOWN
	if (attackingTimer >= attackTimerMax)
	{
		enableToAttack = true;
	}
	else
	{
		enableToAttack = false;
	}

	if (weaponSlot[currentSlot] != 0 &&
		sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && enableToAttack)
	{
		attackingTimer = 0;
	}
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
			{
				enemies[i]->takeDamage(weaponDamage[currentSlot] + playerBaseDamage, weaponSlot[currentSlot]);
				enemies[i]->knockBack();
			}
		}
	}
	for (size_t i = 0; i < enemies.size(); i++)
	{
		//IF ENEMIES DIE
		if (enemies[i]->getHp() <= 0)
		{
			enemies[i]->killed();
			if (enemies[i]->deadCheck())
			{
				//DROP
				if (enemies[i]->bossCheck() || rand() % 10 < 1)
					drop.push_back(new ItemDrop(wave, enemies[i]->getDamage(),
						false, enemies[i]->getPos()));
				exp += enemies[i]->getEXP();
				if (!enemies[i]->bossCheck())
					score += 10;
				else
					score += 50;
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
		player.dead();
	}
	if (player.deadCheck())
	{
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
			enemies.push_back(new Enemy(enemyType, rand() % 2000 - 300 ,
				rand() % 2300 - 700, wave));
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

}

void Game::enemyUpdate()
{
	for (size_t i = 0; i < enemies.size(); i++)
	{
		//UPDATE
		enemies[i]->timeTicking(deltatime);
		enemies[i]->movement(player.getPos(), weaponHitbox.getPos(), player.getBound()
			, !player.deadCheck());
		enemies[i]->update();

		//ENEMIES DAMAGE PLAYER
		if (enemies[i]->getHitBoxBound().intersects(player.getBound()))
		{
			if (!enemies[i]->enemyAttackCooldown() && !player.deadCheck()
				&& !enemies[i]->killedCheck())
			{
				enemies[i]->doDamage(currentPlayerHp);
				player.knockback(enemies[i]->getNormalizedDir());
			}
		}

		//ENEMIES COLLISION CHECK
		if (!enemies[i]->killedCheck())
		{
			enemies[i]->checkObstruct(player.getBound());

			for (size_t j = 0; j < i; j++)
			{
				if (i != j && !enemies[i]->killedCheck())
					enemies[i]->checkObstruct(enemies[j]->getBound());
			}
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

void Game::playerUpdate()
{
	playerLevelUpdate();
	playerAttackRange();
	playerAttack();
	attackUpdate();
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (!enemies[i]->killedCheck())
			player.enemyCollisionUpdate(enemies[i]->getBound());
	}
}

void Game::update()
{
	player.update();
	pollEvent();
	playerUpdate();
	takeItemUpdate();
	itemDropUpdate();
	waveUpdate();
	enemyUpdate();
	screenUIupdate();
}

void Game::render()
{
	window->clear();

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
		if (!enemies[i]->killedCheck())
			gui.enemyUI(enemies[i]->getHp(), enemies[i]->getMaxHp(),
				enemies[i]->getPos(), enemies[i]->getSize(), *window);
	}

	//PLAYER
	player.render(*window);

	//VIEW
	view.setCenter(player.getPos());
	window->setView(view);

	//GUI
	gui.render(*window);


	window->display();
}

void Game::gameReset()
{
	player.reset();
	gui.reset();
	player.animationReset();

	currentSlot = 0;
	weaponSlot[0] = 1;
	weaponSlot[1] = 0;
	weaponDamage[0] = 2;
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
	attackingTimer = 3;
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
