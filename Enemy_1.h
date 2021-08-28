#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Enemy_1
{
private:
	sf::RectangleShape enemy_1;
	float MaxHp;
	float currentHp;
	bool status;
public:
	Enemy_1(float posX, float posY, float level);
	inline const sf::FloatRect getBound() { return enemy_1.getGlobalBounds(); }
	inline const float hpLeft() { return currentHp; }
	inline const bool alive() { return status; }
	void takeDamage(float damage);
	void update();
	void render(sf::RenderTarget& other);
};

