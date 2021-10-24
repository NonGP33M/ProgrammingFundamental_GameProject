#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Player
{
private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
	float movementSpeed = 2.f;
public:
	Player();
	inline const sf::FloatRect getBound() { return playerSprite.getGlobalBounds(); }
	inline const sf::Vector2f getPos() { return playerSprite.getPosition(); }
	inline const sf::Vector2u getSize() { return playerTexture.getSize(); }
	void movement();
	void update();
	void render(sf::RenderTarget& other);
};

