#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class GUI
{
private:
	sf::Font font;
	sf::Text exp;
	sf::Text wave;
public:
	GUI();
	void expUI(int currentEXP, int maxEXP, float posX, float posY);
	void waveUI(int wave, float posX, float posY);
	void render(sf::RenderTarget& other);
};

