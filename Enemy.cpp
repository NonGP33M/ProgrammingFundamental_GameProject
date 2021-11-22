#include "Enemy.h"

Enemy::Enemy(char type, float posX, float posY, float wave)
{
	enemy.setTexture(&enemyTexture);
	currentFrame = { 0,0,16,16 };
	enemy.setTextureRect(currentFrame);
	if (type != 50)
	{
		size = { 96.f, 96.f };
		enemy.setOrigin(size.x/2,size.y/2);
		enemy.setSize(size);

		enemyHitBox.setSize(size);
		isBoss = false;

		if (type == 48)
		{
			movementSpeed = 0.3f + 0.1 * wave;
			MaxHp = 10 * wave;
			exp = 2.f + wave * 2;
			damage = MaxHp / 5;
			this->type = 0;
			enemyTexture.loadFromFile("Texture/Egg.png");
		}
		else
		{
			movementSpeed = 0.5f + 0.1 * wave;
			MaxHp = 10 * wave;
			exp = 2.f + wave * 2;
			damage = MaxHp / 5;
			this->type = 1;
			enemyTexture.loadFromFile("Texture/Chicken.png");
		}
	}
	else
	{
		size = { 128.f, 128.f };
		enemy.setOrigin(64.f, 64.f);
		enemy.setSize(size);
		enemy.setFillColor(sf::Color(204.f,204.f,204.f,255.f));

		enemyHitBox.setSize(size);

		movementSpeed = 0.1f + 0.1 * wave;
		MaxHp = 20 * wave;
		exp = 20.f * wave;
		damage = MaxHp / 4;
		isBoss = true;
		this->type = rand() % 2;
		if (this->type == 0)
			enemyTexture.loadFromFile("Texture/Egg.png");
		else
			enemyTexture.loadFromFile("Texture/Chicken.png");
	}

	enemy.setPosition(posX, posY);
	enemyHitBox.setOutlineThickness(1.f);
	enemyHitBox.setOutlineColor(sf::Color::Green);
	enemyHitBox.setFillColor(sf::Color::Transparent);
	enemyHitBox.setOutlineThickness(1.f);
	enemyHitBox.setOutlineColor(sf::Color::Blue);

	enemySight.setFillColor(sf::Color::Transparent);
	enemySight.setOutlineThickness(1.f);
	enemySight.setOutlineColor(sf::Color::Red);

	waveMultiply = (wave * 0.1) + 10;

	enemySight.setSize({ enemy.getSize().x * waveMultiply, enemy.getSize().y * waveMultiply });
	enemySight.setOrigin(enemySight.getLocalBounds().width / 2,
		enemySight.getLocalBounds().height / 2);

	currentHp = MaxHp;
	dir = { 1.f,1.f };

	randomX = randomAngle() / 1000;
	randomY = randomAngle() / 1000;

	timeBefore = randomTime(3, 0);
	timeAfter = randomTime(4, 3);
}

void Enemy::timeTicking(float deltatime)
{
	attackTimer += deltatime;
	movingTimer += deltatime;
	animationTimer += deltatime;
	if (isKilled)
		deadTimer += deltatime;
}

void Enemy::movement(sf::Vector2f playerPos, sf::Vector2f playerHitBoxPos, sf::FloatRect playerBound, bool isAlive)
{
	position = enemy.getPosition();
	dir = playerPos - enemy.getPosition();
	normalizedDir = dir / sqrt(dir.x * dir.x + dir.y * dir.y);
	enemyHitBox.setPosition(nextPos.left, nextPos.top);
	enemySight.setPosition(position);

	if (!knockingBack && !isKilled)
	{
		//TAXIS MOVEMENT
		if (enemySight.getGlobalBounds().intersects(playerBound) && isAlive)
		{
			enemy.move(movementSpeed * 2 * normalizedDir.x, movementSpeed * 2 * normalizedDir.y);
			enemyHitBox.move(movementSpeed * normalizedDir.x * 35, movementSpeed * normalizedDir.y * 35);
			isMoving = true;
			tracking = true;
			if (normalizedDir.x >= 0)
				dirState = 1;
			else
				dirState = 0;
		}
		//RANDOM MOVEMENT
		else
		{
			randomDir = { randomX, randomY };
			if (movingTimer > timeBefore && movingTimer < timeAfter)
			{
				isMoving = true;
				enemy.move(movementSpeed * randomDir.x, movementSpeed * randomDir.y);
				enemyHitBox.move(movementSpeed * randomDir.x * 35, movementSpeed * randomDir.y * 35);
				tracking = false;
				if (randomX >= 0)
					dirState = 1;
				else
					dirState = 0;
			}
			else if (movingTimer >= timeAfter)
				{
					std::cout << "???" << std::endl;
					isMoving = false;
					movingTimer = 0;
					randomX = randomAngle() / 1000;
					randomY = randomAngle() / 1000;
					timeBefore = randomTime(3, 0);
					timeAfter = randomTime(4, 3);
				}
		}
	}
	//MAP COLLISION
	if (enemy.getPosition().x <= -318 + enemy.getSize().x / 2)
	{
		enemy.setPosition(-317 + enemy.getSize().x / 2, enemy.getPosition().y);
	}
	if (enemy.getPosition().x >= 1758 - enemy.getSize().x / 2)
	{
		enemy.setPosition(1757 - enemy.getSize().x / 2, enemy.getPosition().y);
	}
	if (enemy.getPosition().y <= -700 + enemy.getSize().y / 2)
	{
		enemy.setPosition(enemy.getPosition().x, -699 + enemy.getSize().y / 2);
	}
	if (enemy.getPosition().y >= 1694 - enemy.getSize().y / 2)
	{
		enemy.setPosition(enemy.getPosition().x, 1694 - enemy.getSize().y / 2);
	}
	knockbackDir = playerHitBoxPos - enemy.getPosition();
	normalizedKnockbackDir = knockbackDir / sqrt(knockbackDir.x * knockbackDir.x + knockbackDir.y * knockbackDir.y);
}

void Enemy::checkObstruct(sf::FloatRect otherPos)
{
	nextPos = enemy.getGlobalBounds();

	if (nextPos.intersects(otherPos))
	{
		//right
		if (nextPos.left < otherPos.left &&
			nextPos.left + nextPos.width < otherPos.left + otherPos.width &&
			nextPos.top + nextPos.height > otherPos.top &&
			nextPos.top < otherPos.top + otherPos.height)
		{
			enemy.setPosition(enemy.getPosition().x - 1.f, enemy.getPosition().y);
		}
		//left
		if (nextPos.left > otherPos.left &&
			nextPos.left + nextPos.width > otherPos.left + otherPos.width &&
			nextPos.top + nextPos.height > otherPos.top &&
			nextPos.top < otherPos.top + otherPos.height)
		{
			enemy.setPosition(enemy.getPosition().x + 1.f, enemy.getPosition().y);
		}
		//top
		if (nextPos.top > otherPos.top &&
			nextPos.top + nextPos.height > otherPos.top + otherPos.height &&
			nextPos.left + nextPos.width > otherPos.left &&
			nextPos.left < otherPos.left + otherPos.width)
		{
			enemy.setPosition(enemy.getPosition().x, enemy.getPosition().y + 1.f);
		}
		//bottom
		if (nextPos.top < otherPos.top &&
			nextPos.top + nextPos.height < otherPos.top + otherPos.height &&
			nextPos.left + nextPos.width > otherPos.left &&
			nextPos.left < otherPos.left + otherPos.width)
		{
			enemy.setPosition(enemy.getPosition().x, enemy.getPosition().y - 1.f);
		}
	}
}

void Enemy::attackCooldown()
{
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

void Enemy::animation()
{
	//RIGHT
	if (dirState == 0 && !isKilled)
	{
		currentFrame.top = 16;
		if (animationTimer >= 0.1f)
		{
			currentFrame.left += 16;
			if (currentFrame.left >= 96 || !isMoving || knockingBack)
				currentFrame.left = 0;

			
			enemy.setTextureRect(currentFrame);
			animationTimer = 0;
		}
	}
	//LEFT
	else if (dirState == 1 && !isKilled)
	{
		currentFrame.top = 0;
		if (animationTimer >= 0.1f)
		{
			currentFrame.left += 16;
			if (currentFrame.left >= 96 || !isMoving || knockingBack)
				currentFrame.left = 0;

			enemy.setTextureRect(currentFrame);
			animationTimer = 0;
		}
	}

	//DEAD
	if (dirState == 0 && isKilled)
	{
		currentFrame.top = 48;
		if (deadTimer >= 0.15f)
		{
			if (currentFrame.left < 80)
			{
				currentFrame.left += 16;
				deadTimer = 0;
			}

			enemy.setTextureRect(currentFrame);
			
		}
	}
	else if (dirState == 1 && isKilled)
	{
		currentFrame.top = 32;
		if (deadTimer >= 0.15f)
		{
			if (currentFrame.left < 80)
			{
				currentFrame.left += 16;
				deadTimer = 0;
			}
			enemy.setTextureRect(currentFrame);
			
		}
	}
}

void Enemy::doDamage(int& playerHp)
{
	if (enableToAttack)
	{
		playerHp -= damage;
		attackTimer = 0;
		enableToAttack = false;
	}
}

void Enemy::takeDamage(float damage, int weapon)
{
	if (!knockingBack)
	{
		//SWORD
		if (weapon == 1)
		{
			//EGG
			if (type == 0)
				currentHp -= damage / 1.5;
			//CHICKEN
			else if (type == 1)
				currentHp -= damage;
			hitBy = weapon;
		}

		//HAMMER
		else
		{
			//EGG
			if (type == 0)
				currentHp -= damage;
			//CHICKEN
			else if (type == 1)
				currentHp -= damage / 1.5;
			hitBy = weapon;
		}
	}
}

void Enemy::knockBackUpdate()
{
	if (knockingBack)
	{
		if (hitBy == 1)
			knockBackRate = 0.1;
		else
			knockBackRate = 0.05;
		if (knockbackspeed > 0)
		{
			enemy.move(knockbackspeed * -normalizedKnockbackDir.x, knockbackspeed * -normalizedKnockbackDir.y);
			knockbackspeed -= knockBackRate;
		}
		else
		{
			if (isMoving)
				knockbackspeed = 5;
			knockingBack = false;
		}
	}
}

void Enemy::deadUpdate()
{
	if (isKilled)
	{
		if (deadTimer >= 2.f)
			isDead = true;
	}
}

void Enemy::update()
{
	position = getPos();
	attackCooldown();
	knockBackUpdate();
	deadUpdate();
	animation();
}

void Enemy::render(sf::RenderTarget& other)
{
	other.draw(enemy);
	//other.draw(enemyHitBox);
	//other.draw(enemySight);
}