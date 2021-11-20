#include "Player.h"

Player::Player()
{
	playerTexture.loadFromFile("Texture/Player.png");
	currentFrame = { 0,0,32,32 };
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

void Player::knockBack(sf::Vector2f knockBackDir)
{
	animCount = 0;
	playerSprite.move(50 * knockBackDir.x, 50 * knockBackDir.y);
	if (knockbackTimer.getElapsedTime().asSeconds() >= 0.2)
	{
		ableToMove = true;
		knockbackTimer.restart();
	}
}

void Player::movement()
{
	//MOVING AND ANIMATION STATE
	if (ableToMove && !isAttacking && !dead)
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

	playerHitBox.setPosition(playerSprite.getPosition());
}

void Player::animation()
{
	//MOVING
	if (ableToMove && !dead)
	{
		if (animStates == DOWN)
		{
			currentFrame.top = 0;
			if (animationTimer.getElapsedTime().asSeconds() >= 0.1f)
			{
				if (isMoving)
					currentFrame.left += 32;
				if (currentFrame.left >= 192 || !isMoving)
					currentFrame.left = 0;
				playerSprite.setTextureRect(currentFrame);
				animationTimer.restart();
			}
		}
		else if (animStates == RIGHT)
		{
			currentFrame.top = 32;
			if (animationTimer.getElapsedTime().asSeconds() >= 0.1f)
			{
				currentFrame.left += 32;
				if (currentFrame.left >= 192 || !isMoving)
					currentFrame.left = 0;
				playerSprite.setTextureRect(currentFrame);
				animationTimer.restart();
			}
		}
		else if (animStates == TOP)
		{
			currentFrame.top = 64;
			if (animationTimer.getElapsedTime().asSeconds() >= 0.1f)
			{
				currentFrame.left += 32;
				if (currentFrame.left >= 192 || !isMoving)
					currentFrame.left = 0;
				playerSprite.setTextureRect(currentFrame);
				animationTimer.restart();
			}
		}
		else if (animStates == LEFT)
		{
			currentFrame.top = 96;
			if (animationTimer.getElapsedTime().asSeconds() >= 0.1f)
			{
				currentFrame.left += 32;
				if (currentFrame.left >= 192 || !isMoving)
					currentFrame.left = 0;
				playerSprite.setTextureRect(currentFrame);
				animationTimer.restart();
			}
		}
	}
	//ATTACKING
	else if (isAttacking && !dead)
	{
		if (animStates == DOWN && isAttacking)
		{
			currentFrame.top = 128;
			if (animationTimer.getElapsedTime().asSeconds() >= 0.05f)
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
				animationTimer.restart();
			}
		}
		else if (animStates == RIGHT && isAttacking)
		{
			currentFrame.top = 160;
			if (animationTimer.getElapsedTime().asSeconds() >= 0.05f)
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
				animationTimer.restart();
			}
		}
		else if (animStates == TOP && isAttacking)
		{
			currentFrame.top = 192;
			if (animationTimer.getElapsedTime().asSeconds() >= 0.05f)
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
				animationTimer.restart();
				animationTimer.restart();
			}
		}
		else if (animStates == LEFT && isAttacking)
		{
			currentFrame.top = 224;
			if (animationTimer.getElapsedTime().asSeconds() >= 0.05f)
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
				animationTimer.restart();
			}
		}
	}
	//DEAD
	else
	{
		if (animStates == DOWN)
		{
			currentFrame.top = 384;
			if (animationTimer.getElapsedTime().asSeconds() >= 0.15f)
			{
				currentFrame.left += 32;
				playerSprite.setTextureRect(currentFrame);
				animationTimer.restart();
			}
		}
		if (animStates == RIGHT)
		{
			currentFrame.top = 416;
			if (animationTimer.getElapsedTime().asSeconds() >= 0.15f)
			{
				currentFrame.left += 32;
				playerSprite.setTextureRect(currentFrame);
				animationTimer.restart();
			}
		}
		else if (animStates == TOP)
		{
			currentFrame.top = 448;
			if (animationTimer.getElapsedTime().asSeconds() >= 0.15f)
			{
				currentFrame.left += 32;
				playerSprite.setTextureRect(currentFrame);
				animationTimer.restart();
			}
		}
		else if (animStates == LEFT)
		{
			currentFrame.top = 480;
			if (animationTimer.getElapsedTime().asSeconds() >= 0.15f)
			{
				currentFrame.left += 32;
				playerSprite.setTextureRect(currentFrame);
				animationTimer.restart();
			}
		}
	}
}

void Player::attack()
{
	if (attackTimer.getElapsedTime().asSeconds() >= 0.35f)
	{
		isAttacking = false;
		ableToMove = true;
	}
}

void Player::update()
{
	attack();
	movement();
	animation();
}

void Player::render(sf::RenderTarget& other)
{
	other.draw(playerSprite);
	other.draw(playerHitBox);
}

void Player::reset()
{
	playerSprite.setPosition(720.f, 450.f);
	animStates = TOP;
	animCount = 0;
	dead = false;
	isMoving = false;
	ableToMove = true;
	isAttacking = false;
}
