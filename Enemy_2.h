#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Enemy_2
{
private:
	sf::RectangleShape enemy_2;
	sf::Vector2f position;
	float MaxHp;
	float currentHp;
	float exp;
	float movementSpeed;
public:
	Enemy_2(float posX, float posY, float wave);
	inline const sf::FloatRect getBound() { return enemy_2.getGlobalBounds(); }
	inline const sf::Vector2f getPos() { return enemy_2.getPosition(); }
	inline const int getHp() { return currentHp; }
	inline const int getMaxHp() { return MaxHp; }
	inline const int getEXP() { return exp; }
	void takeDamage(float damage);
	void movement(sf::Vector2f playerPos);
	void update();
	void render(sf::RenderTarget& other);
};

