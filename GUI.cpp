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
	enemyHp.setFont(font);
	enemyHp.setFillColor(sf::Color::White);
	enemyHp.setCharacterSize(16);
	weapon.setFont(font);
	weapon.setFillColor(sf::Color::White);
	weapon.setCharacterSize(24);
	weapon.setLineSpacing(2);
}

void GUI::enemyUI(int currentHp, int maxHp, sf::Vector2f pos, sf::Vector2f size, sf::RenderTarget& other)
{
	enemyHp.setString(std::to_string(currentHp) + "/" + std::to_string(maxHp));
	enemyHp.setPosition(pos.x - enemyHp.getLocalBounds().width/2, pos.y - size.y / 2 - 35.f);
	other.draw(enemyHp);
}

void GUI::expUI(int currentEXP, int maxEXP, float posX, float posY)
{
	exp.setString("EXP:" + std::to_string(currentEXP) + "/" + std::to_string(maxEXP));
	exp.setPosition(posX, posY);
}

void GUI::waveUI(int wave, float posX, float posY)
{
	this->wave.setString("Waves : " + std::to_string(wave));
	this->wave.setPosition(posX, posY);
}

void GUI::weaponSlotUI(int current, float posX, float posY)
{	
	if (current == 0)
		weapon.setString("WeaponUsing : Nothing");
	else if (current == 1)
		weapon.setString("WeaponUsing : Dagger");
	else if (current == 2)
		weapon.setString("WeaponUsing : Sword");
	weapon.setPosition(posX, posY);
}

void GUI::render(sf::RenderTarget& other)
{ 
	other.draw(exp);
	other.draw(this->wave);
	other.draw(weapon);
}
