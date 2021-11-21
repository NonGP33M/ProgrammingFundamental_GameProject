#include "Player.h"

Player::Player()
{
	playerTexture.loadFromFile("Texture/Player.png");
	currentFrame = { 0,64,32,32 };
	playerSprite.setTexture(&playerTexture);
	playerSprite.setSize({ 192.f, 192.f });
	playerSprite.setPosition(720.f, 450.f);
	playerSprite.setTextureRect(currentFrame);
	playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2,
		playerSprite.getLocalBounds().height / 2);

	playerHitBox.setSize({ 96.f, 96.f });
	playerHitBox.setFillColor(sf::Color::Transparent);
	playerHitBox.setOutlineThickness(1.f);
	playerHitBox.setOutlineColor(sf::Color::Green);
	playerHitBox.setOrigin(playerHitBox.getLocalBounds().width / 2,
		playerHitBox.getGlobalBounds().height / 2);
}

void Player::mapCollisionUpdate()
{
	//MAP COLLISION
	if (playerSprite.getPosition().x <= -318 + playerSprite.getSize().x / 2 - 48)
	{
		playerSprite.setPosition(-317 + playerSprite.getSize().x / 2 - 48, playerSprite.getPosition().y);
	}
	if (playerSprite.getPosition().x >= 1758 - playerSprite.getSize().x / 2 + 48)
	{
		playerSprite.setPosition(1757 - playerSprite.getSize().x / 2 + 48, playerSprite.getPosition().y);
	}
	if (playerSprite.getPosition().y <= -700 + playerSprite.getSize().y / 2 - 48)
	{
		playerSprite.setPosition(playerSprite.getPosition().x, -699 + playerSprite.getSize().y / 2 - 48);
	}
	if (playerSprite.getPosition().y >= 1694 - playerSprite.getSize().y / 2 + 48)
	{
		playerSprite.setPosition(playerSprite.getPosition().x, 1693 - playerSprite.getSize().y / 2 + 48);
	}
}

void Player::enemyCollisionUpdate(sf::FloatRect enemy)
{
	nextPos = playerHitBox.getGlobalBounds();
	if (nextPos.intersects(enemy))
	{
		//right
		if (nextPos.left < enemy.left &&
			nextPos.left + nextPos.width < enemy.left + enemy.width &&
			nextPos.top + nextPos.height > enemy.top &&
			nextPos.top < enemy.top + enemy.height)
		{
			playerSprite.setPosition(playerSprite.getPosition().x - 1.f, playerSprite.getPosition().y);
		}
		//left
		if (nextPos.left > enemy.left &&
			nextPos.left + nextPos.width > enemy.left + enemy.width &&
			nextPos.top + nextPos.height > enemy.top &&
			nextPos.top < enemy.top + enemy.height)
		{
			playerSprite.setPosition(playerSprite.getPosition().x + 1.f, playerSprite.getPosition().y);
		}
		//top
		if (nextPos.top > enemy.top &&
			nextPos.top + nextPos.height > enemy.top + enemy.height &&
			nextPos.left + nextPos.width > enemy.left &&
			nextPos.left < enemy.left + enemy.width)
		{
			playerSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y + 1.f);
		}
		//bottom
		if (nextPos.top < enemy.top &&
			nextPos.top + nextPos.height < enemy.top + enemy.height &&
			nextPos.left + nextPos.width > enemy.left &&
			nextPos.left < enemy.left + enemy.width)
		{
			playerSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y - 1.f);
		}
	}
}

void Player::timeTicking(float deltatime)
{
	animationTimer += deltatime;
	attackTimer += deltatime;
}

void Player::knockback(sf::Vector2f knockBackDir)
{
	isKnockingBack = true;
	this->knockBackDir = knockBackDir;
}

void Player::knockBackUpdate()
{
	if (isKnockingBack)
	{
		if (knockBackSpeed > 0)
		{
			playerSprite.move(knockBackSpeed * knockBackDir.x, knockBackSpeed * knockBackDir.y);
			knockBackSpeed -= 0.1f;
			if(!isAttacking)
				playerSprite.setFillColor(sf::Color::Red);
			else
				playerSprite.setFillColor(sf::Color::White);
		}
		else
		{
			knockBackSpeed = 5;
			ableToMove = true;
			isKnockingBack = false;
			playerSprite.setFillColor(sf::Color::White);
		}
	}
}

void Player::movement()
{
	//MOVING AND ANIMATION STATE
	if (ableToMove && !isAttacking && !isDead && !isKnockingBack)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			playerSprite.move(-movementSpeed * 1.f, movementSpeed * 0.f);
			animStates = LEFT;
			isMoving = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			playerSprite.move(movementSpeed * 1.f, movementSpeed * 0.f);
			animStates = RIGHT;
			isMoving = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			playerSprite.move(movementSpeed * 0.f, movementSpeed * 1.f);
			animStates = DOWN;
			isMoving = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			playerSprite.move(movementSpeed * 0.f, -movementSpeed * 1.f);
			animStates = TOP;
			isMoving = true;
		}
		else
		{
			playerSprite.move(0.f, 0.f);
			isMoving = false;
		}
	}

	playerHitBox.setPosition(playerSprite.getPosition());
}

void Player::animation()
{
	//MOVING
	if (ableToMove && !isDead)
	{
		if (animStates == DOWN)
		{
			currentFrame.top = 0;
			if (animationTimer >= 0.1f)
			{
				if (isMoving)
					currentFrame.left += 32;
				if (currentFrame.left >= 192 || !isMoving)
					currentFrame.left = 0;
				playerSprite.setTextureRect(currentFrame);
				animationTimer = 0;
			}
		}
		else if (animStates == RIGHT)
		{
			currentFrame.top = 32;
			if (animationTimer >= 0.1f)
			{
				if (isMoving)
					currentFrame.left += 32;
				if (currentFrame.left >= 192 || !isMoving)
					currentFrame.left = 0;
				playerSprite.setTextureRect(currentFrame);
				animationTimer = 0;
			}
		}
		else if (animStates == TOP)
		{
			currentFrame.top = 64;
			if (animationTimer >= 0.1f)
			{
				if (isMoving)
					currentFrame.left += 32;
				if (currentFrame.left >= 192 || !isMoving)
					currentFrame.left = 0;
				playerSprite.setTextureRect(currentFrame);
				animationTimer = 0;
			}
		}
		else if (animStates == LEFT)
		{
			if (isMoving)
				currentFrame.top = 96;
			if (animationTimer >= 0.1f)
			{
				currentFrame.left += 32;
				if (currentFrame.left >= 192 || !isMoving)
					currentFrame.left = 0;
				playerSprite.setTextureRect(currentFrame);
				animationTimer = 0;
			}
		}
	}
	//ATTACKING
	else if (isAttacking && !isDead)
	{
		//SWORD
		if (currentWeapon == 1)
		{
			if (animStates == DOWN && isAttacking)
			{
				currentFrame.top = 128;
				if (animationTimer >= 0.05f)
				{
					if (animCount != 6)
						currentFrame.left = 32 * animCount;
					if (animCount >= 6)
					{
						animCount = 0;
					}
					else
						animCount++;
					playerSprite.setTextureRect(currentFrame);
					animationTimer = 0;
				}
			}
			else if (animStates == RIGHT && isAttacking)
			{
				currentFrame.top = 160;
				if (animationTimer >= 0.05f)
				{
					if (animCount != 6)
						currentFrame.left = 32 * animCount;
					if (animCount >= 6)
					{
						animCount = 0;
					}
					else
						animCount++;
					playerSprite.setTextureRect(currentFrame);
					animationTimer = 0;
				}
			}
			else if (animStates == TOP && isAttacking)
			{
				currentFrame.top = 192;
				if (animationTimer >= 0.05f)
				{
					if (animCount != 6)
						currentFrame.left = 32 * animCount;
					if (animCount >= 6)
					{
						animCount = 0;
					}
					else
						animCount++;
					playerSprite.setTextureRect(currentFrame);
					animationTimer = 0;
				}
			}
			else if (animStates == LEFT && isAttacking)
			{
				currentFrame.top = 224;
				if (animationTimer >= 0.05f)
				{
					if (animCount != 6)
						currentFrame.left = 32 * animCount;
					if (animCount >= 6)
					{
						animCount = 0;
					}
					else
						animCount++;
					playerSprite.setTextureRect(currentFrame);
					animationTimer = 0;
				}
			}
		}

		//HAMMER
		else if (currentWeapon == 2)
		{
			if (animStates == DOWN && isAttacking)
			{
				currentFrame.top = 256;
				if (animationTimer >= 0.05f)
				{
					if (animCount != 6)
						currentFrame.left = 32 * animCount;
					if (animCount >= 6)
					{
						animCount = 0;
					}
					else
						animCount++;
					playerSprite.setTextureRect(currentFrame);
					animationTimer = 0;
				}
			}
			else if (animStates == RIGHT && isAttacking)
			{
				currentFrame.top = 288;
				if (animationTimer >= 0.05f)
				{
					if (animCount != 6)
						currentFrame.left = 32 * animCount;
					if (animCount >= 6)
					{
						animCount = 0;
					}
					else
						animCount++;
					playerSprite.setTextureRect(currentFrame);
					animationTimer = 0;
				}
			}
			else if (animStates == TOP && isAttacking)
			{
				currentFrame.top = 320;
				if (animationTimer >= 0.05f)
				{
					if (animCount != 6)
						currentFrame.left = 32 * animCount;
					if (animCount >= 6)
					{
						animCount = 0;
					}
					else
						animCount++;
					playerSprite.setTextureRect(currentFrame);
					animationTimer = 0;
				}
			}
			else if (animStates == LEFT && isAttacking)
			{
				currentFrame.top = 352;
				if (animationTimer >= 0.05f)
				{
					if (animCount != 6)
						currentFrame.left = 32 * animCount;
					if (animCount >= 6)
					{
						animCount = 0;
					}
					else
						animCount++;
					playerSprite.setTextureRect(currentFrame);
					animationTimer = 0;
				}
			}
		}
	}
	//DEAD
	else if (isDead)
	{
		if (animStates == DOWN)
		{
			currentFrame.top = 384;
			if (animationTimer >= 0.15f)
			{
				currentFrame.left += 32;
				playerSprite.setTextureRect(currentFrame);
				animationTimer = 0;
			}
		}
		if (animStates == RIGHT)
		{
			currentFrame.top = 416;
			if (animationTimer >= 0.15f)
			{
				currentFrame.left += 32;
				playerSprite.setTextureRect(currentFrame);
				animationTimer = 0;
			}
		}
		else if (animStates == TOP)
		{
			currentFrame.top = 448;
			if (animationTimer >= 0.15f)
			{
				currentFrame.left += 32;
				playerSprite.setTextureRect(currentFrame);
				animationTimer = 0;
			}
		}
		else if (animStates == LEFT)
		{
			currentFrame.top = 480;
			if (animationTimer >= 0.15f)
			{
				currentFrame.left += 32;
				playerSprite.setTextureRect(currentFrame);
				animationTimer = 0;
			}
		}
	}
}

void Player::attack()
{
	if (attackTimer >= 0.35f)
	{
		isAttacking = false;
		ableToMove = true;
	}
	/*else if (attackTimer >= 1.f && currentWeapon == 2)
	{
		isAttacking = false;
		ableToMove = true;
	}*/
}

void Player::update()
{
	attack();
	mapCollisionUpdate();
	movement();
	animation();
	knockBackUpdate();
}

void Player::render(sf::RenderTarget& other)
{
	other.draw(playerSprite);
	other.draw(playerHitBox);
}

void Player::reset()
{
	playerSprite.setPosition(720.f, 450.f);
	playerSprite.setFillColor(sf::Color::White);
	currentFrame = { 0,64,32,32 };
	playerSprite.setTextureRect(currentFrame);
	animStates = TOP;
	animCount = 0;
	isDead = false;
	isMoving = false;
	ableToMove = true;
	isAttacking = false;
	isKnockingBack = false;

	currentWeapon = 0;
	knockBackSpeed = 5;
	animationTimer = 0;
	attackTimer = 0;
}
