#include "Game.h"

void Game::setting()
{
	this->video.width = 1440.f;
	this->video.height = 900.f;
	this->window = new sf::RenderWindow(video, "Game_2");
	this->window->setFramerateLimit(144.f);
	spawnTimerMax = 100.f;
	attackTimerMax = 100.f;
	enableToAttack = true;
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

void Game::attackUpdate()
{
	attackTimer += 0.5f;
	if (attackTimer >= attackTimerMax)
	{
		//std::cout << "Enable to Attack" << std::endl;
		enableToAttack = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			enableToAttack = false;
			attackTimer = 0.f;
			std::cout << "Unable to Attack" << std::endl;
		}
	}
}

void Game::playerRange()
{
	knife.setPosition(player.getPos().x, player.getPos().y);
	
}

void Game::enemyUpdate()
{
	spawnTimer += 0.5f;
	if (spawnTimer >= spawnTimerMax)
	{
		enemies_1.push_back(new Enemy_1(rand() % 200, rand() % 600, playerLevel));
		spawnTimer = 0.f;
	}
	for (auto* enemy_1 : enemies_1)
	{
		enemy_1->update();
	}
}

void Game::killingUpdate()
{
	for (size_t i = 0; i < enemies_1.size(); i++)
	{
		if (enemies_1[i]->getBound().intersects(knife.getBound()) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
			knife.knifeHolding)
		{
			std::cout << "hit" << std::endl;
			if (enemies_1[i]->alive())
			{
				enemies_1[i]->takeDamage(knife.knifeDamage(playerLevel));
			}
			else
			{
				enemies_1.erase(enemies_1.begin() + i);
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
	killingUpdate();
}

void Game::render()
{
	window->clear();
	player.render(*window);
	knife.render(*window);
	for (auto* enemy_1 : enemies_1)
	{
		enemy_1->render(*window);
	}
	window->display();
}
