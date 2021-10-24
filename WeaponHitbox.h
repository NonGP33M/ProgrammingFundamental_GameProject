#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class WeaponHitbox
{
private:
	sf::RectangleShape Hitbox;
	float size;
public:
	WeaponHitbox();
	inline const sf::FloatRect getBound() { return Hitbox.getGlobalBounds(); }
	inline const float knifeDamage(float level) { return 2 + level; }
	void setHitbox(float posX, float posY, int type);
	void render(sf::RenderTarget& other);
};

