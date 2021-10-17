#include "GUI.h"

GUI::GUI()
{
	font.loadFromFile("Font/dogica.ttf");
	exp.setFont(font);
	exp.setFillColor(sf::Color::White);
	exp.setCharacterSize(24);
	this->wave.setFont(font);
	this->wave.setFillColor(sf::Color::White);
	this->wave.setCharacterSize(24);
	enemy_1Hp.setFont(font);
	enemy_1Hp.setFillColor(sf::Color::White);
	enemy_1Hp.setCharacterSize(16);
	enemy_2Hp.setFont(font);
	enemy_2Hp.setFillColor(sf::Color::White);
	enemy_2Hp.setCharacterSize(16);
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
	other.draw(enemy_1Hp);
	other.draw(enemy_2Hp);
}
