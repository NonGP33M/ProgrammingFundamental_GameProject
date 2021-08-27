#include "Enemy_1.h"

Enemy_1::Enemy_1(float posX, float posY, float level)
{
	enemy_1.setSize(sf::Vector2f(50.f, 50.f));
	enemy_1.setPosition(posX, posY);
	enemy_1.setFillColor(sf::Color::Green);
	MaxHp = 100 * level;
	currentHp = MaxHp;
	status = true;
}

void Enemy_1::takeDamage(float damage)
{
	currentHp -= damage;
}

void Enemy_1::update()
{
	if (currentHp < 0)
		status = false;
}

void Enemy_1::render(sf::RenderTarget& other)
{
	other.draw(enemy_1);
}
