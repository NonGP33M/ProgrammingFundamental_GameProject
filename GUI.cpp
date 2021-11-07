#include "GUI.h"

GUI::GUI()
{
	font.loadFromFile("Font/Retro Gaming.ttf");

	exp.setFont(font);
	exp.setFillColor(sf::Color::White);
	exp.setCharacterSize(24);

	wave.setFont(font);
	wave.setFillColor(sf::Color::White);
	wave.setCharacterSize(24);

	enemyHp.setFont(font);
	enemyHp.setFillColor(sf::Color::White);
	enemyHp.setCharacterSize(16);

	weapon.setFont(font);
	weapon.setFillColor(sf::Color::White);
	weapon.setCharacterSize(24);
	weapon.setLineSpacing(2);

	maxHpBar.setSize({ 400.f,40.f });
	maxHpBar.setFillColor(sf::Color(90.f, 90.f, 90.f, 255.f));

	currentHpBar.setFillColor(sf::Color(255.f, 40.f, 80.f, 255.f));
}

void GUI::enemyUI(int currentHp, int maxHp, sf::Vector2f pos, sf::Vector2f size, sf::RenderTarget& other)
{
	enemyHp.setString(std::to_string(currentHp) + "/" + std::to_string(maxHp));
	enemyHp.setPosition(pos.x - enemyHp.getLocalBounds().width/2, pos.y - size.y / 2 - 35.f);
	other.draw(enemyHp);
}

void GUI::screenUI(sf::Vector2f pos, int currentEXP, int maxEXP, int wave, int currentWeapon, int weaponDamage, int baseDamage, float currentPlayerHp, float maxPlayerHp)
{
	exp.setString("EXP:" + std::to_string(currentEXP) + "/" + std::to_string(maxEXP));
	exp.setPosition(pos.x - 700, pos.y - 330);

	this->wave.setString("Waves : " + std::to_string(wave));
	this->wave.setPosition(pos.x + 475, pos.y - 430);

	maxHpBar.setPosition(pos.x - 700, pos.y - 430);

	currentHpBar.setPosition(pos.x - 700, pos.y - 430);
	currentHpBar.setSize({ 400.f * (currentPlayerHp / maxPlayerHp),40.f });

	if (currentWeapon == 0)
		weapon.setString("WeaponUsing : Nothing (NO DAMAGE)");
	else if (currentWeapon == 1)
		weapon.setString("WeaponUsing : Dagger (" + std::to_string(weaponDamage) + "+" + std::to_string(baseDamage) + ")");
	else if (currentWeapon == 2)
		weapon.setString("WeaponUsing : Sword (" + std::to_string(weaponDamage) + "+" + std::to_string(baseDamage) + ")");
	weapon.setPosition(pos.x - 700, pos.y + 400);
}

void GUI::render(sf::RenderTarget& other)
{ 
	other.draw(exp);
	other.draw(this->wave);
	other.draw(weapon);
	other.draw(maxHpBar);
	other.draw(currentHpBar);
}