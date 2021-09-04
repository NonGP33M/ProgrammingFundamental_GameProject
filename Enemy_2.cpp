#include "Enemy_2.h"

Enemy_2::Enemy_2(float posX, float posY, float level)
{
	enemy_2.setSize(sf::Vector2f(75.f, 75.f));
	enemy_2.setPosition(posX, posY);
	enemy_2.setFillColor(sf::Color::Blue);
	MaxHp = 20 * level;
	currentHp = MaxHp;
	exp = 4.f;
}

void Enemy_2::takeDamage(float damage)
{
	currentHp -= damage;
}

void Enemy_2::update()
{
}

void Enemy_2::render(sf::RenderTarget& other)
{
	other.draw(enemy_2);
}
