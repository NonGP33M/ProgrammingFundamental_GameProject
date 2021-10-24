#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class ItemDrop
{
private:
	sf::CircleShape drop;
	int weaponType;
	int damage;
public:
	ItemDrop(int type, int wave, sf::Vector2f enemyPos);
	inline const sf::FloatRect getBound() { return drop.getGlobalBounds(); }
	inline const int getType() { return weaponType; }
	inline const int getDamage() { return damage; }
	void render(sf::RenderTarget& other);
};

