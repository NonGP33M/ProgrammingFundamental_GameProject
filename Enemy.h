#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Enemy
{
private:
	sf::RectangleShape enemy;
	sf::Vector2f position;
	sf::Vector2f size;
	float MaxHp;
	float currentHp;
	float exp;
	float movementSpeed;
public:
	Enemy(int type, float posX, float posY, float wave);
	inline const sf::FloatRect getBound() { return enemy.getGlobalBounds(); }
	inline const sf::Vector2f getPos() { return enemy.getPosition(); }
	inline const int getHp() { return currentHp; }
	inline const int getMaxHp() { return MaxHp; }
	inline const int getEXP() { return exp; }
	inline const sf::Vector2f getSize() { return size; }
	void takeDamage(float damage);
	void movement(sf::Vector2f playerPos);
	void update();
	void render(sf::RenderTarget& other);
};

