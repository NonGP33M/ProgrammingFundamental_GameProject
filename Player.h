#pragma once
#include "Enemy_1.h"
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
	void movement();
	void update();
	void render(sf::RenderTarget& other);
};

