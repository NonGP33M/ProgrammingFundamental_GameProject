#include "Enemy_1.h"

Enemy_1::Enemy_1(float posX, float posY, float wave)
{
	enemy_1.setSize(sf::Vector2f(50.f, 50.f));
	enemy_1.setPosition(posX, posY);
	enemy_1.setFillColor(sf::Color::Green);
	movementSpeed = 0.4f;
	MaxHp = 10 * wave;
	currentHp = MaxHp;
	exp = 2.f;
}

void Enemy_1::movement(sf::Vector2f playerPos)
{
	if(position.x < playerPos.x || position.y > playerPos.y)
		enemy_1.move(movementSpeed * 1.f, movementSpeed * -1.f);
	if(position.x < playerPos.x || position.y < playerPos.y)
		enemy_1.move(movementSpeed * 1.f, movementSpeed * 1.f);
	if (position.x > playerPos.x || position.y < playerPos.y)
		enemy_1.move(movementSpeed * -1.f, movementSpeed * 1.f);
	if (position.x > playerPos.x || position.y > playerPos.y)
		enemy_1.move(movementSpeed * -1.f, movementSpeed * -1.f);
}

void Enemy_1::update()
{
	position = getPos();
}

void Enemy_1::takeDamage(float damage)
{
	currentHp -= damage;
}

void Enemy_1::render(sf::RenderTarget& other)
{
	other.draw(enemy_1);
}

