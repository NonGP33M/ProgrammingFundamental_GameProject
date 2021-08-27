#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Knife
{
private:
	float baseDamage = 2;
	sf::RectangleShape KnifeBox;
public:
	Knife();
	bool knifeHolding = false;
	inline const sf::FloatRect getBound() { return KnifeBox.getGlobalBounds(); }
	inline const float knifeDamage(float level) { return baseDamage + (baseDamage * level); }
	void setPosition(float posX, float posY);
	void render(sf::RenderTarget& other);
};

