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
		dir = { 1.f,1.f };
		MaxHp = 10 * wave;
		currentHp = MaxHp;
		exp = 2.f;
		damage = MaxHp / 5;
	}
	else if (type == 2)
	{
		size = { 75.f, 75.f };
		enemy.setOrigin(37.5f, 37.5f);
		enemy.setSize(size);
		enemy.setPosition(posX, posY);
		enemy.setFillColor(sf::Color::Blue);
		movementSpeed = 0.3f;
		dir = { 1.f,1.f };
		MaxHp = 15 * wave;
		currentHp = MaxHp;
		exp = 5.f;
		damage = MaxHp / 3;
	}
}

void Enemy::movement(sf::Vector2f playerPos)
{
	if (position.x < playerPos.x || position.y > playerPos.y)
		enemy.move(movementSpeed * dir.x, movementSpeed * -dir.y);
	if (position.x < playerPos.x || position.y < playerPos.y)
		enemy.move(movementSpeed * dir.x, movementSpeed * dir.y);
	if (position.x > playerPos.x || position.y < playerPos.y)
		enemy.move(movementSpeed * -dir.x, movementSpeed * dir.y);
	if (position.x > playerPos.x || position.y > playerPos.y)
		enemy.move(movementSpeed * -dir.x, movementSpeed * -dir.y);
}

void Enemy::checkObstruct(sf::FloatRect thisPos, sf::FloatRect otherPos)
{
	nextPos = thisPos;
	nextPos.left += 1.f;
	nextPos.top += 1.f;
	if (nextPos.intersects(otherPos))
	{
		//right
		if (thisPos.left + thisPos.width < otherPos.left + otherPos.width &&
			thisPos.top + thisPos.height > otherPos.top &&
			thisPos.top < otherPos.top + otherPos.height)
		{
			enemy.setPosition(thisPos.left + thisPos.width/2, enemy.getPosition().y);
			dir.x = 0;
		}
		//left
		if (thisPos.left + thisPos.width > otherPos.left + otherPos.width &&
			thisPos.top + thisPos.height > otherPos.top &&
			thisPos.top < otherPos.top + otherPos.height)
		{
			enemy.setPosition(enemy.getPosition().x + 1.f, enemy.getPosition().y);
			dir.x = 0;
		}
	}
	else
	{
		dir.x = 1.f;
		dir.y = 1.f;
	}
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