#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

enum animationState {LEFT, RIGHT, TOP, DOWN };

class Player
{
private:
	sf::Clock animationTimer;
	sf::Clock knockbackTimer;
	sf::RectangleShape playerSprite;
	sf::RectangleShape playerHitBox;
	sf::Texture playerTexture;
	sf::IntRect currentFrame;
	float movementSpeed = 2.f;
	int animStates = TOP;
	bool isMoving = false;
	bool ableToMove = true;

public:
	Player();
	inline const sf::FloatRect getBound() { return playerHitBox.getGlobalBounds(); }
	inline const sf::Vector2f getPos() { return playerHitBox.getPosition(); }
	inline const sf::Vector2u getSize() { return playerTexture.getSize(); }
	inline const int getPlayerState() { return animStates; }
	inline const bool movingCheck() { return isMoving; }
	inline void animationReset() { animStates = TOP; }
	void knockBack(sf::Vector2f knockBackDir);
	void movement();
	void animation();
	void update();
	void render(sf::RenderTarget& other);
	void reset();
};

