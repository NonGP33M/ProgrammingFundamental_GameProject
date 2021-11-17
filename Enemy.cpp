#include "Enemy.h"

Enemy::Enemy(char type, float posX, float posY, float wave)
{
	if (type != 50)
	{
		size = { 64.f, 64.f };
		enemy.setOrigin(32.f, 32.f);
		enemy.setSize(size);
		enemy.setFillColor(sf::Color::Green);

		enemyHitBox.setSize(size);
		isBoss = false;

		if (type == 48)
		{
			movementSpeed = 0.3f + 0.1 * wave;
			MaxHp = 10 * wave;
			exp = 2.f;
			damage = MaxHp / 5;
			this->type = 0;
		}
		else
		{
			movementSpeed = 0.5f + 0.1 * wave;
			MaxHp = 10 * wave;
			exp = 2.f;
			damage = MaxHp / 5;
			this->type = 1;
		}
	}
	else
	{
		size = { 128.f, 128.f };
		enemy.setOrigin(64.f, 64.f);
		enemy.setSize(size);
		enemy.setFillColor(sf::Color::Blue);

		enemyHitBox.setSize(size);

		movementSpeed = 0.1f + 0.1 * wave;
		MaxHp = 20 * wave;
		exp = 20.f;
		damage = MaxHp / 4;
		isBoss = true;
		this->type = rand() % 2;
	}

	enemy.setPosition(posX, posY);
	enemyHitBox.setFillColor(sf::Color::Transparent);
	enemyHitBox.setOutlineThickness(1.f);
	enemyHitBox.setOutlineColor(sf::Color::Red);
	currentHp = MaxHp;
	dir = { 1.f,1.f };
}

void Enemy::movement(sf::Vector2f playerPos, sf::Vector2f playerHitBoxPos)
{
	position = enemy.getPosition();
	dir = playerPos - enemy.getPosition();
	normalizedDir = dir / sqrt(dir.x * dir.x + dir.y * dir.y);
	enemy.move(movementSpeed * normalizedDir.x, movementSpeed * normalizedDir.y);

	enemyHitBox.setPosition(nextPos.left, nextPos.top);
	enemyHitBox.move(movementSpeed * normalizedDir.x * 25, movementSpeed * normalizedDir.y * 25);

	knockbackDir = playerHitBoxPos - enemy.getPosition();
	normalizedKnockbackDir = knockbackDir / sqrt(knockbackDir.x * knockbackDir.x + knockbackDir.y * knockbackDir.y);
}

void Enemy::checkObstruct(sf::FloatRect thisPos, sf::FloatRect otherPos)
{
	nextPos = thisPos;
	nextPos.left += 1.f;
	nextPos.top += 1.f;

	if (nextPos.intersects(otherPos))
	{
		//right
		if (thisPos.left < otherPos.left &&
			thisPos.left + thisPos.width < otherPos.left + otherPos.width &&
			thisPos.top + thisPos.height > otherPos.top &&
			thisPos.top < otherPos.top + otherPos.height)
		{
			enemy.setPosition(enemy.getPosition().x - 1.f, enemy.getPosition().y);
			dir.x = 0;
		}
		//left
		else if (thisPos.left > otherPos.left &&
			thisPos.left + thisPos.width > otherPos.left + otherPos.width &&
			thisPos.top + thisPos.height > otherPos.top &&
			thisPos.top < otherPos.top + otherPos.height)
		{
			enemy.setPosition(enemy.getPosition().x + 1.f, enemy.getPosition().y);
			dir.x = 0;
		}
		//top
		else if (thisPos.top > otherPos.top &&
			thisPos.top + thisPos.height > otherPos.top + otherPos.height &&
			thisPos.left + thisPos.width > otherPos.left &&
			thisPos.left < otherPos.left + otherPos.width)
		{
			enemy.setPosition(enemy.getPosition().x, enemy.getPosition().y + 1.f);
			dir.y = 0;
		}
		//bottom
		else if (thisPos.top < otherPos.top &&
			thisPos.top + thisPos.height < otherPos.top + otherPos.height &&
			thisPos.left + thisPos.width > otherPos.left &&
			thisPos.left < otherPos.left + otherPos.width)
		{
			enemy.setPosition(enemy.getPosition().x, enemy.getPosition().y - 1.f);
			dir.y = 0;
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
	attackCooldown();
}

void Enemy::attackCooldown()
{
	attackTimer = attackClock.getElapsedTime().asSeconds();
	enableToAttack = false;
	if (attackTimer >= 2.f)
	{
		cooldown = false;
	}
	else
	{
		cooldown = true;
	}
	if (!cooldown)
	{
		enableToAttack = true;
	}
}

void Enemy::doDamage(int& playerHp)
{
	if (enableToAttack)
	{
		playerHp -= damage;
		attackClock.restart();
	}
}

void Enemy::takeDamage(float damage,int weapon)
{
	if (type == 0)
	{
		if (weapon == 1)
			currentHp -= damage / 2;
		else if (weapon == 2)
			currentHp -= damage;
	}

	else
	{
		if (weapon == 1)
			currentHp -= damage;
		else if (weapon == 2)
			currentHp -= damage / 2;
	}
	
	knockBack();
}

void Enemy::knockBack()
{
	enemy.move(0.4f * 250.f * -normalizedKnockbackDir.x, 0.4f * 250.f * -normalizedKnockbackDir.y);
}

void Enemy::render(sf::RenderTarget& other)
{
	other.draw(enemy);
	other.draw(enemyHitBox);
}