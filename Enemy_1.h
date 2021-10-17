#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Enemy_1
{
private:
	sf::RectangleShape enemy_1;
	sf::Vector2f position;
	float MaxHp;
	float currentHp;
	float exp;
	float movementSpeed;
public:
	Enemy_1(float posX, float posY, float wave);
	inline const sf::FloatRect getBound() { return enemy_1.getGlobalBounds(); }
	inline const sf::Vector2f getPos() { return enemy_1.getPosition(); }
	inline const int getHp() { return currentHp; }
	inline const int getMaxHp() { return MaxHp; }
	inline const int getEXP() { return exp; }
	void takeDamage(float damage);
	void movement(sf::Vector2f playerPos);
	void update();
	void render(sf::RenderTarget& other);
};

