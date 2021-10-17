#include "Game.h"

void Game::setting()
{
	this->video.width = 1440.f;
	this->video.height = 900.f;
	this->window = new RenderWindow(video, "Game_2");
	this->window->setFramerateLimit(144.f);
	view.setSize(1440.f, 900.f);

	background.setOrigin(352.f, 160.f);
	background.setPosition(720.f, 450.f);
	background.setScale(4.f, 4.f);
	backgroundTexture.loadFromFile("Texture/Background.png");
	background.setTexture(backgroundTexture);

	spawnTimerMax = 100.f;
	attackTimerMax = 50.f;

	font.loadFromFile("Font/dogica.ttf");
	enemy_1Hp.setFont(font);
	enemy_2Hp.setFont(font);
}

void Game::pollEvent()
{
	while (window->pollEvent(event))
	{
		if (event.type == Event::Closed)
			window->close();

		if (Keyboard::isKeyPressed(Keyboard::Num1))
			currentSlot = 0;

		if (Keyboard::isKeyPressed(Keyboard::Num2))
			currentSlot = 1;
	}
}

void Game::UIupdate()
{
	gui.expUI(exp, expMax, player.getPos().x - 700, player.getPos().y - 430);
	gui.waveUI(wave, player.getPos().x + 475, player.getPos().y - 430);
}

void Game::takeItemUpdate()
{
	for (size_t i = 0; i < drop.size(); i++)
	{
		if (Keyboard::isKeyPressed(Keyboard::E)
			&& drop[i]->getBound().intersects(player.getBound()))
		{
			if(weaponSlot[0] == 0)
				weaponSlot[0] = drop[i]->getType();
			else if(weaponSlot[1] == 0)
				weaponSlot[1] = drop[i]->getType();
			else
				weaponSlot[currentSlot] = drop[i]->getType();
			drop.erase(drop.begin() + i);
		}
	}
}

void Game::enemy_1UIUpdate(int index)
{
	enemy_1Hp.setFillColor(Color::White);
	enemy_1Hp.setCharacterSize(16);
	enemy_1Hp.setString(to_string(enemies_1[index]->getHp()) + "/" + to_string(enemies_1[index]->getMaxHp()));
	enemy_1Hp.setPosition(enemies_1[index]->getPos().x, enemies_1[index]->getPos().y - 50);
}

void Game::enemy_2UIUpdate(int index)
{
	enemy_2Hp.setFillColor(Color::White);
	enemy_2Hp.setCharacterSize(16);
	enemy_2Hp.setString(to_string(enemies_2[index]->getHp()) + "/" + to_string(enemies_2[index]->getMaxHp()));
	enemy_2Hp.setPosition(enemies_2[index]->getPos().x, enemies_2[index]->getPos().y - 50);
}

void Game::attackUpdate()
{
	enableToAttack = false;
	if (playerWeapon == DAGGER)
		attackTimer += 0.5f;

	if (attackTimer >= attackTimerMax)
	{
		cout << "Enable to Attack" << endl;
		attackCooldown = true;
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			attackCooldown = false;
			attackTimer = 0.f;
		}
		if (!attackCooldown)
		{
			enableToAttack = true;
		}
	}
	else
	{
		cout << "Unable to Attack" << endl;
	}

	cout << "Current : ";
	if (playerWeapon == NOTHING)
	{
		cout << "Bare hand" << endl;
		cout << "Damage : " << "0" << endl;
	}
	if (playerWeapon == DAGGER)
	{
		cout << "Dagger" << endl;
		cout << "Damage : " << knife.knifeDamage(playerLevel) << "+" << playerBaseDamage << endl;
	}
	if (playerWeapon == SWORD)
	{
		cout << "Sword" << endl;
		cout << "Damage : " << "NULL" << endl;
	}
	cout << endl;
}

void Game::playerAttackRange()
{
	knife.setPosition(player.getPos().x + 8, player.getPos().y + 8);

}

void Game::levelUpdate()
{
	expMax = 12 * playerLevel;
	if (exp >= expMax)
	{
		exp = 0;
		playerLevel++;
	}
	if (spawnCount == 0)
	{
		spawnTimer += 0.1f;
		if (spawnTimer >= spawnTimerMax)
		{
			spawnTimer = 0;
			wave++;
		}
	}
}

void Game::enemyUpdate()
{

	if (spawnCount < 8 && spawnTimer == 0)
	{
		enemyType = rand() % 2 + 1;
		if (enemyType == 1)
		{
			enemies_1.push_back(new Enemy_1(rand() % 600 + 1,
				rand() % 600 + 1,
				wave));

			spawnCount++;
			enemyLeft++;
		}
		else if (enemyType == 2)
		{
			enemies_2.push_back(new Enemy_2(rand() % 600 + 1,
				rand() % 600 + 1,
				wave));

			spawnCount++;
			enemyLeft++;
		}
	}

	else if (enemyLeft == 0 && killCount != 0)
	{
		spawnCount = 0;
	}
	for (size_t i = 0; i < enemies_1.size(); i++)
	{
		enemies_1[i]->update();
		enemies_1[i]->movement(player.getPos());
	}
	for (size_t i = 0; i < enemies_2.size(); i++)
	{
		enemies_2[i]->update();
		enemies_2[i]->movement(player.getPos());
	}
}

void Game::killingUpdate()
{
	for (size_t i = 0; i < enemies_1.size(); i++)
	{
		if (enemies_1[i]->getBound().intersects(knife.getBound()) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
			playerWeapon != NOTHING && enableToAttack)
		{
			if (enemies_1[i]->getHp() > 0)
			{
				enemies_1[i]->takeDamage(knife.knifeDamage(playerLevel) + playerBaseDamage);
			}
			if (enemies_1[i]->getHp() <= 0)
			{
				exp += enemies_1[i]->getEXP();
				if (rand() % 10 + 1 == 2)
					drop.push_back(new ItemDrop(1, wave, enemies_1[i]->getPos()));
				enemies_1.erase(enemies_1.begin() + i);
				killCount++;
				enemyLeft--;
			}
		}
	}

	for (size_t i = 0; i < enemies_2.size(); i++)
	{
		if (enemies_2[i]->getBound().intersects(knife.getBound()) &&
			Keyboard::isKeyPressed(Keyboard::Space) &&
			playerWeapon != NOTHING && enableToAttack)
		{
			if (enemies_2[i]->getHp() > 0)
			{
				enemies_2[i]->takeDamage(knife.knifeDamage(playerLevel) + playerBaseDamage);
			}
			if (enemies_2[i]->getHp() <= 0)
			{
				exp += enemies_2[i]->getEXP();
				if (rand() % 10 + 1 == 2)
					drop.push_back(new ItemDrop(2, wave, enemies_2[i]->getPos()));
				enemies_2.erase(enemies_2.begin() + i);
				killCount++;
				enemyLeft--;
			}
		}
	}

}

void Game::update()
{
	pollEvent();
	UIupdate();
	takeItemUpdate();
	player.update();
	playerAttackRange();
	attackUpdate();
	enemyUpdate();
	levelUpdate();
	killingUpdate();

	playerWeapon = weaponSlot[currentSlot];
	playerBaseDamage = 2 + playerLevel;

	cout << "PlayerLevel : " << playerLevel << " | ";
	cout << "KillCount : " << killCount << " | ";
	cout << "SpawnCount : " << spawnCount << " | ";
	cout << "EnemyLeft : " << enemyLeft << endl;

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
	knife.render(*window);

	for (size_t i = 0; i < enemies_1.size(); i++)
	{
		enemy_1UIUpdate(i);
		enemies_1[i]->render(*window);
		window->draw(enemy_1Hp);

	}
	for (size_t i = 0; i < enemies_2.size(); i++)
	{
		enemy_2UIUpdate(i);
		enemies_2[i]->render(*window);
		window->draw(enemy_2Hp);
	}
	gui.render(*window);

	window->display();
}
