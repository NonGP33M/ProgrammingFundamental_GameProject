#include "Enemy.h"

Enemy::Enemy(int type, float posX, float posY, float wave)
{
	if (type == 1)
	{
		size = { 50.f, 50.f };
		enemy.setOrigin(25.f, 25.f);
		enemy.setSize(size);
		enemy.setPosition(posX, posY);
		enemy.setFillColor(sf::Color::Green);
		movementSpeed = 0.4f;
		MaxHp = 10 * wave;
		currentHp = MaxHp;
		exp = 2.f;
	}
	else if (type == 2)
	{
		size = { 75.f, 75.f };
		enemy.setOrigin(37.5f, 37.5f);
		enemy.setSize(size);
		enemy.setPosition(posX, posY);
		enemy.setFillColor(sf::Color::Blue);
		movementSpeed = 0.3f;
		MaxHp = 15 * wave;
		currentHp = MaxHp;
		exp = 5.f;
	}
}

void Enemy::movement(sf::Vector2f playerPos)
{
	if (position.x < playerPos.x || position.y > playerPos.y)
		enemy.move(movementSpeed * 1.f, movementSpeed * -1.f);
	if (position.x < playerPos.x || position.y < playerPos.y)
		enemy.move(movementSpeed * 1.f, movementSpeed * 1.f);
	if (position.x > playerPos.x || position.y < playerPos.y)
		enemy.move(movementSpeed * -1.f, movementSpeed * 1.f);
	if (position.x > playerPos.x || position.y > playerPos.y)
		enemy.move(movementSpeed * -1.f, movementSpeed * -1.f);
}

void Enemy::update()
{
	position = getPos();
}

void Enemy::takeDamage(float damage)
{
	currentHp -= damage;
}

void Enemy::render(sf::RenderTarget& other)
{
	other.draw(enemy);
}

