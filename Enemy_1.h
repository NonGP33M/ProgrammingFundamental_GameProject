#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Enemy_1
{
private:
	sf::RectangleShape enemy_1;
	float MaxHp;
	float currentHp;
	float exp;
public:
	Enemy_1(float posX, float posY, float level);
	inline const sf::FloatRect getBound() { return enemy_1.getGlobalBounds(); }
	inline const sf::Vector2f getPos() { return enemy_1.getPosition(); }
	inline const int getHp() { return currentHp; }
	inline const int getMaxHp() { return MaxHp; }
	inline const int getEXP() { return exp; }
	void takeDamage(float damage);
	void update();
	void render(sf::RenderTarget& other);
};

