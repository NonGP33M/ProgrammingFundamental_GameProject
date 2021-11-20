#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class ItemDrop
{
private:
	sf::RectangleShape drop;
	sf::Texture texture;
	sf::Clock animClock;
	sf::Clock timer;
	sf::IntRect currentFrame;

	int weaponType;
	int damage;
	bool showing = true;
public:
	ItemDrop(int type, int dmg, bool playerDrop, sf::Vector2f pos);
	inline const sf::FloatRect getBound() { return drop.getGlobalBounds(); }
	inline const int getWeaponType() { return weaponType; }
	inline const int getDamage() { return damage; }
	inline const float getTime() { return timer.getElapsedTime().asSeconds(); }
	void warning();
	void animation();
	void update();
	void render(sf::RenderTarget& other);
};

