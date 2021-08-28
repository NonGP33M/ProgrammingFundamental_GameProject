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

void Game::enemyUIUpdate(int index)
{
	font.loadFromFile("Font/dogica.ttf");
	enemyHp.setFont(font);
	enemyHp.setFillColor(sf::Color::White);
	enemyHp.setCharacterSize(16);
	enemyHp.setString(std::to_string(enemies_1[index]->getHp()) + "/" + std::to_string(enemies_1[index]->getMaxHp()));
	enemyHp.setPosition(enemies_1[index]->getPos().x, enemies_1[index]->getPos().y - 50);
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
	if (killCount >= spawnCount)
	{
		spawnCount = 0;
	}
	if (exp >= expMax)
	{
		exp = 0;
		playerLevel++;
	}
	std::cout << exp << " / " << expMax << std::endl;
}

void Game::enemyUpdate()
{
	spawnTimer += 0.5f;
	if (spawnTimer >= spawnTimerMax && spawnCount < 8)
	{
		enemies_1.push_back(new Enemy_1(rand() % 600, rand() % 600, playerLevel));
		spawnTimer = 0.f;
		spawnCount++;
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
	std::cout << "Damage : " << knife.knifeDamage(playerLevel) << " // ";
	std::cout << "Level : " << playerLevel << " // ";
	std::cout << "Kill-count" << killCount << std::endl;
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
		enemyUIUpdate(i);
		enemies_1[i]->render(*window);
		window->draw(enemyHp);
		
	}

	window->display();
}
