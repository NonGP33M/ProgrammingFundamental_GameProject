#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Enemy_2
{
private:
	sf::RectangleShape enemy_2;
	float MaxHp;
	float currentHp;
	float exp;
public:
	Enemy_2(float posX, float posY, float level);
	inline const sf::FloatRect getBound() { return enemy_2.getGlobalBounds(); }
	inline const sf::Vector2f getPos() { return enemy_2.getPosition(); }
	inline const int getHp() { return currentHp; }
	inline const int getMaxHp() { return MaxHp; }
	inline const int getEXP() { return exp; }
	void takeDamage(float damage);
	void update();
	void render(sf::RenderTarget& other);
};

