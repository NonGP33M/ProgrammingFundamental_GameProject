#include "Player.h"

Player::Player()
{
	playerTexture.loadFromFile("Texture/Sprite/Player.png");
	currentFrame = { 0,0,32,32 };
	playerSprite.setTexture(&playerTexture);
	playerSprite.setSize({ 192.f, 192.f });
	playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2,
		playerSprite.getLocalBounds().height / 2);
	playerSprite.setPosition(720.f, 450.f);
	playerSprite.setTextureRect(currentFrame);

	playerHitBox.setSize({ 96.f, 96.f });
	playerHitBox.setOrigin(playerHitBox.getLocalBounds().width / 2,
		playerHitBox.getGlobalBounds().height / 2);
}

void Player::knockBack(sf::Vector2f knockBackDir)
{
	playerSprite.move(50 * knockBackDir.x, 50 * knockBackDir.y);
		if (knockbackTimer.getElapsedTime().asSeconds() >= 0.2)
		{
			ableToMove = true;
			knockbackTimer.restart();
		}
}

void Player::movement()
{
	if (ableToMove)
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
	if (isMoving)
	{
		if (animStates == DOWN)
		{
			currentFrame.top = 0;
			if (animationTimer.getElapsedTime().asSeconds() >= 0.1f)
			{
				currentFrame.left += 32;
				if (currentFrame.left >= 192)
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
				if (currentFrame.left >= 192)
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
				if (currentFrame.left >= 192)
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
				if (currentFrame.left >= 192)
					currentFrame.left = 0;
				playerSprite.setTextureRect(currentFrame);
				animationTimer.restart();
			}
		}
	}
	else
	{
		currentFrame.left = 0;
		playerSprite.setTextureRect(currentFrame);
		animationTimer.restart();
	}
}

void Player::update()
{
	movement();
	animation();
}

void Player::render(sf::RenderTarget& other)
{
	other.draw(playerSprite);
}

void Player::reset()
{
	playerSprite.setPosition(720.f, 450.f);
}
