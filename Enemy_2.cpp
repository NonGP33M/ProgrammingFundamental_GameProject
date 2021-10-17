#include "Enemy_2.h"

Enemy_2::Enemy_2(float posX, float posY, float wave)
{
	enemy_2.setSize(sf::Vector2f(75.f, 75.f));
	enemy_2.setPosition(posX, posY);
	enemy_2.setFillColor(sf::Color::Blue);
	MaxHp = 20 * wave;
	currentHp = MaxHp;
	exp = 4.f;
	movementSpeed = 0.25;
}

void Enemy_2::takeDamage(float damage)
{
	currentHp -= damage;
}

void Enemy_2::movement(sf::Vector2f playerPos)
{
	if (position.x < playerPos.x)
		enemy_2.move(movementSpeed * 1.f, movementSpeed * 0.f);
	if (position.x > playerPos.x)
		enemy_2.move(movementSpeed * -1.f, movementSpeed * 0.f);
	if (position.y < playerPos.y)
		enemy_2.move(movementSpeed * 0.f, movementSpeed * 1.f);
	if (position.y > playerPos.y)
		enemy_2.move(movementSpeed * 0.f, movementSpeed * -1.f);
}

void Enemy_2::update()
{
	position = getPos();
}

void Enemy_2::render(sf::RenderTarget& other)
{
	other.draw(enemy_2);
}
