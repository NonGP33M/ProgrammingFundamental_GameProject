#include "Game.h"

void Game::setting()
{
	this->video.width = 1440.f;
	this->video.height = 900.f;
	this->window = new sf::RenderWindow(video, "Game_2");
	this->window->setFramerateLimit(144.f);
	view.setSize(1440.f, 900.f);

	background.setOrigin(352.f, 160.f);
	background.setPosition(720.f, 450.f);
	background.setScale(4.f, 4.f);
	backgroundTexture.loadFromFile("Texture/Background.png");
	background.setTexture(backgroundTexture);

	spawnTimerMax = 100.f;
	attackTimerMax = 100.f;

	font.loadFromFile("Font/dogica.ttf");
	enemy_1Hp.setFont(font);
	enemy_2Hp.setFont(font);
}

void Game::pollEvent()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			weaponSlot = 1;
			knife.knifeHolding = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			weaponSlot = 2;
			knife.knifeHolding = false;
		}
	}
}

void Game::enemy_1UIUpdate(int index)
{
	enemy_1Hp.setFillColor(sf::Color::White);
	enemy_1Hp.setCharacterSize(16);
	enemy_1Hp.setString(std::to_string(enemies_1[index]->getHp()) + "/" + std::to_string(enemies_1[index]->getMaxHp()));
	enemy_1Hp.setPosition(enemies_1[index]->getPos().x, enemies_1[index]->getPos().y - 50);
}

void Game::enemy_2UIUpdate(int index)
{
	enemy_2Hp.setFillColor(sf::Color::White);
	enemy_2Hp.setCharacterSize(16);
	enemy_2Hp.setString(std::to_string(enemies_2[index]->getHp()) + "/" + std::to_string(enemies_2[index]->getMaxHp()));
	enemy_2Hp.setPosition(enemies_2[index]->getPos().x, enemies_2[index]->getPos().y - 50);
}

void Game::attackUpdate()
{
	enableToAttack = false;
	attackTimer += 0.5f;
	if (attackTimer >= attackTimerMax)
	{
		//std::cout << "Enable to Attack" << std::endl;
		attackCooldown = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			attackCooldown = false;
			attackTimer = 0.f;
		}
		if (!attackCooldown)
		{
			enableToAttack = true;
		}
	}
}

void Game::playerRange()
{
	knife.setPosition(player.getPos().x, player.getPos().y);
	
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
	std::cout << exp << " / " << expMax << std::endl;
}

void Game::enemyUpdate()
{
	
	if (spawnCount < 8 && spawnTimer == 0)
	{
		type = rand() % 2 + 1;
		if (type == 1)
		{
			enemies_1.push_back(new Enemy_1(rand() % 600 + 1,
				rand() % 600 + 1,
				playerLevel));

			spawnCount++;
			enemyLeft++;
		}
		else if (type == 2)
		{
			enemies_2.push_back(new Enemy_2(rand() % 600 + 1,
				rand() % 600 + 1,
				playerLevel));

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
	}
}

void Game::killingUpdate()
{
	for (size_t i = 0; i < enemies_1.size(); i++)
	{
		if (enemies_1[i]->getBound().intersects(knife.getBound()) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
			knife.knifeHolding && enableToAttack)
		{
			if (enemies_1[i]->getHp() > 0)
			{
				enemies_1[i]->takeDamage(knife.knifeDamage(playerLevel));
			}
			if(enemies_1[i]->getHp() <= 0)
			{
				exp += enemies_1[i]->getEXP();
				enemies_1.erase(enemies_1.begin() + i);
				killCount++;
				enemyLeft--;
			}
		}
	}

	for (size_t i = 0; i < enemies_2.size(); i++)
	{
		if (enemies_2[i]->getBound().intersects(knife.getBound()) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
			knife.knifeHolding && enableToAttack)
		{
			if (enemies_2[i]->getHp() > 0)
			{
				enemies_2[i]->takeDamage(knife.knifeDamage(playerLevel));
			}
			if (enemies_2[i]->getHp() <= 0)
			{
				exp += enemies_2[i]->getEXP();
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
	player.update();
	playerRange();
	attackUpdate();
	enemyUpdate();
	levelUpdate();
	killingUpdate();
	gui.expUI(exp, expMax, player.getPos().x - 700, player.getPos().y - 430);
	gui.waveUI(wave, player.getPos().x + 475, player.getPos().y - 430);

	std::cout << "Damage : " << knife.knifeDamage(playerLevel) << " // ";
	std::cout << "Level : " << playerLevel << " // ";
	std::cout << "Kill-count" << killCount << " // ";
	std::cout << killCount << "-" << spawnCount << "-" << enemyLeft << std::endl;
}

void Game::render()
{
	window->clear();

	view.setCenter(player.getPos());
	window->setView(view);

	window->draw(background);
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
