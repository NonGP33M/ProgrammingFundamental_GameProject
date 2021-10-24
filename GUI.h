#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class GUI
{
private:
	sf::Font font;
	sf::Text exp;
	sf::Text wave;
	sf::Text enemyHp;
public:
	GUI();
	void enemyUI(int currentHp, int maxHp, sf::Vector2f pos, sf::Vector2f size, sf::RenderTarget& other);
	void expUI(int currentEXP, int maxEXP, float posX, float posY);
	void waveUI(int wave, float posX, float posY);
	void render(sf::RenderTarget& other);
};

