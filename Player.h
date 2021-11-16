#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

enum playerState { IDLE, LEFT, RIGHT, TOP, DOWN };

class Player
{
private:
	sf::RectangleShape playerSprite;
	sf::Texture playerTexture;
	float movementSpeed = 2.f;
	int playerStates = 3;

public:
	Player();
	inline const sf::FloatRect getBound() { return playerSprite.getGlobalBounds(); }
	inline const sf::Vector2f getPos() { return playerSprite.getPosition(); }
	inline const sf::Vector2u getSize() { return playerTexture.getSize(); }
	inline const int getPlayerState() { return playerStates; }
	void knockBack(sf::Vector2f knockBackDir);
	void movement();
	void update();
	void render(sf::RenderTarget& other);
	void reset();
};

