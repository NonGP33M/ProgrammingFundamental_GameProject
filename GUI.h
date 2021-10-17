#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class GUI
{
private:
	sf::Font font;
	sf::Text exp;
	sf::Text wave;
	sf::Text enemy_1Hp;
	sf::Text enemy_2Hp;
public:
	GUI();
	void expUI(int currentEXP, int maxEXP, float posX, float posY);
	void waveUI(int wave, float posX, float posY);
	void render(sf::RenderTarget& other);
};

