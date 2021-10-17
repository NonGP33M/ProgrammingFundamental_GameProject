#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Knife
{
private:
	float baseDamage;
	sf::RectangleShape KnifeBox;
public:
	Knife();
	inline const sf::FloatRect getBound() { return KnifeBox.getGlobalBounds(); }
	inline const float knifeDamage(float level) { baseDamage = level * 2; return baseDamage; }
	void setPosition(float posX, float posY);
	void render(sf::RenderTarget& other);
};

