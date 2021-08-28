#include "GUI.h"

GUI::GUI()
{
	font.loadFromFile("Font/dogica.ttf");
	exp.setFont(font);
	exp.setFillColor(sf::Color::Green);
	exp.setCharacterSize(24);
}

void GUI::expUI(int currentEXP, int maxEXP, float posX, float posY)
{
	exp.setString(std::to_string(currentEXP) + "/" + std::to_string(maxEXP));
	exp.setPosition(posX, posY);
}

void GUI::waveUI(int wave, float posX, float posY)
{
	this->wave.setString("Waves : " + std::to_string(wave));
	this->wave.setPosition(posX, posY);
}

void GUI::render(sf::RenderTarget& other)
{ 
	other.draw(exp);
	other.draw(this->wave);
}
