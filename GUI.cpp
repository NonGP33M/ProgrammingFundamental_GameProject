#include "GUI.h"

GUI::GUI()
{
	font.loadFromFile("Font/Notalot60.ttf");

	exp.setFont(font);
	exp.setFillColor(sf::Color::Black);
	exp.setCharacterSize(24);

	wave.setFont(font);
	wave.setCharacterSize(256);
	wave.setLetterSpacing(3);

	enemyHp.setFont(font);
	enemyHp.setFillColor(sf::Color::White);
	enemyHp.setCharacterSize(16);
	enemyHp.setOutlineThickness(1.f);
	enemyHp.setOutlineColor(sf::Color::Black);

	weapon.setFont(font);
	weapon.setFillColor(sf::Color::White);
	weapon.setCharacterSize(24);
	weapon.setLineSpacing(2);
	weapon.setOutlineThickness(1.f);
	weapon.setOutlineColor(sf::Color::Black);

	currentPlayerHp.setFont(font);
	currentPlayerHp.setFillColor(sf::Color::Black);
	currentPlayerHp.setCharacterSize(24);

	maxHpBar.setSize({ 259.f,22.f });

	maxEXPBar.setSize({ 259.f,5.f });

	currentHpBar.setFillColor(sf::Color(255.f, 40.f, 80.f, 255.f));
	expBar.setFillColor(sf::Color(0.f, 255.f, 155.f, 255.f));

	weaponSlot.setFont(font);
	weaponSlot.setFillColor(sf::Color::White);
	weaponSlot.setCharacterSize(20);
	weaponSlot.setOutlineThickness(1.f);
	weaponSlot.setOutlineColor(sf::Color::Black);
	
	weaponSlot_1.setFont(font);
	weaponSlot_1.setFillColor(sf::Color::White);
	weaponSlot_1.setCharacterSize(20);
	weaponSlot_1.setOutlineThickness(1.f);
	weaponSlot_1.setOutlineColor(sf::Color::Black);

	UIHUD.setSize({ 1440.f,900.f });
	UIHUD.setOrigin(UIHUD.getLocalBounds().width / 2, UIHUD.getLocalBounds().height / 2);
	HUDTexture.loadFromFile("Texture/Sprite/UI.png");
	UIHUD.setTexture(&HUDTexture);
}

void GUI::enemyUI(int currentHp, int maxHp, sf::Vector2f pos, sf::Vector2f size, sf::RenderTarget& other)
{
	enemyHp.setString(std::to_string(currentHp) + "/" + std::to_string(maxHp));
	enemyHp.setPosition(pos.x - enemyHp.getLocalBounds().width/2, pos.y - size.y / 2 - 35.f);
	other.draw(enemyHp);
}

void GUI::screenUI(sf::Vector2f pos, float currentEXP, float maxEXP, int wave, 
	int currentWeapon, int weaponDamage, int baseDamage, float currentPlayerHp, 
	float maxPlayerHp, int slot, float waveTime ,bool duringWave)
{
	time += waveTime;
	UIHUD.setPosition(pos.x, pos.y);

	this->currentPlayerHp.setString("HP: " + std::to_string(static_cast<int>(currentPlayerHp)) + "/" 
		+ std::to_string(static_cast<int>(maxPlayerHp)));
	exp.setString("EXP: " + std::to_string(static_cast<int>(currentEXP)) + "/" 
		+ std::to_string(static_cast<int>(maxEXP)));

	this->currentPlayerHp.setPosition(pos.x - 680, pos.y - 416);
	exp.setPosition(pos.x - 680, pos.y - 386);

	this->wave.setString("Wave  " + std::to_string(wave+1));
	this->wave.setOrigin(this->wave.getLocalBounds().width / 2, this->wave.getLocalBounds().height / 2);
	this->wave.setPosition(pos.x, pos.y);

	if (!duringWave)
	{
		if (waveTime >= 1.5f && waveTime <= 2.5f && opacity <= 252.45f)
			opacity += 2.55f;
		else if (waveTime >= 4.f && opacity >= 2.55f)
			opacity -= 2.55f;
	}
	else
		time = 0;
	this->wave.setFillColor(sf::Color(255, 255, 255, opacity));
	maxHpBar.setPosition(pos.x - 563, pos.y - 416);

	currentHpBar.setPosition(maxHpBar.getPosition());
	currentHpBar.setSize({ maxHpBar.getLocalBounds().width * (currentPlayerHp / maxPlayerHp), maxHpBar.getLocalBounds().height });

	maxEXPBar.setPosition(pos.x - 563, pos.y - 377);

	expBar.setPosition(maxEXPBar.getPosition());
	expBar.setSize({ maxEXPBar.getLocalBounds().width * (currentEXP / maxEXP), maxEXPBar.getLocalBounds().height });

	if (currentWeapon == 0)
		weapon.setString("WeaponUsing : Nothing (NO DAMAGE)");
	else if (currentWeapon == 1)
		weapon.setString("WeaponUsing : Sword (" + std::to_string(weaponDamage) + "+" + std::to_string(baseDamage) + ")");
	else if (currentWeapon == 2)
		weapon.setString("WeaponUsing : Hammer (" + std::to_string(weaponDamage) + "+" + std::to_string(baseDamage) + ")");
	weapon.setPosition(pos.x - 700, pos.y + 400);

	if (slot == 0)
	{
		weaponSlot.setCharacterSize(36);
		weaponSlot.setString(std::to_string(1));
		weaponSlot_1.setCharacterSize(24);
		weaponSlot_1.setString(std::to_string(2));

		weaponSlot.setOrigin(weaponSlot.getLocalBounds().left,
			weaponSlot.getLocalBounds().top + weaponSlot.getLocalBounds().height);
		weaponSlot_1.setOrigin(weaponSlot_1.getLocalBounds().left,
			weaponSlot_1.getLocalBounds().top + weaponSlot_1.getLocalBounds().height);

		weaponSlot.setPosition(pos.x - 700, pos.y + 380);
		weaponSlot_1.setPosition(pos.x - 680, pos.y + 380);
	}
	else if (slot == 1)
	{
		weaponSlot.setCharacterSize(24);
		weaponSlot.setString(std::to_string(1));
		weaponSlot_1.setCharacterSize(36);
		weaponSlot_1.setString(std::to_string(2));

		weaponSlot.setOrigin(weaponSlot.getLocalBounds().left,
			weaponSlot.getLocalBounds().top + weaponSlot.getLocalBounds().height);
		weaponSlot_1.setOrigin(weaponSlot_1.getLocalBounds().left,
			weaponSlot_1.getLocalBounds().top + weaponSlot_1.getLocalBounds().height);

		weaponSlot.setPosition(pos.x - 700, pos.y + 380);
		weaponSlot_1.setPosition(pos.x - 680, pos.y + 380);
	}
	
}

void GUI::render(sf::RenderTarget& other)
{ 
	other.draw(UIHUD);
	other.draw(currentHpBar);
	other.draw(expBar);
	other.draw(exp);
	other.draw(this->wave);
	other.draw(weapon);
	other.draw(currentPlayerHp);
	other.draw(weaponSlot);
	other.draw(weaponSlot_1);
	
}