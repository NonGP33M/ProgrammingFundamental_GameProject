#include "Player.h"

Player::Player()
{
	playerTexture.loadFromFile("Texture/Player.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setScale(3.f, 3.f);
	playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2,
	playerSprite.getLocalBounds().height / 2);
	playerSprite.setPosition(720.f, 450.f);
	
}

void Player::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		playerSprite.move(-movementSpeed * 1.f, movementSpeed * 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		playerSprite.move(movementSpeed * 1.f, movementSpeed * 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		playerSprite.move(movementSpeed * 0.f, movementSpeed * 1.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		playerSprite.move(movementSpeed * 0.f, -movementSpeed * 1.f);
	}
	else
	{
		playerSprite.move(0.f, 0.f);
	}
}

void Player::update()
{
	movement();
}

void Player::render(sf::RenderTarget& other)
{
	other.draw(playerSprite);
}

void Player::reset()
{
	playerSprite.setPosition(720.f, 450.f);
}
