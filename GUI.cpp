#include "GUI.h"

GUI::GUI()
{
	font.loadFromFile("Font/Notalot60.ttf");

	exp.setFont(font);
	exp.setFillColor(sf::Color::Black);
	exp.setCharacterSize(20);

	wave.setFont(font);
	wave.setCharacterSize(256);
	wave.setLetterSpacing(3);

	enemyHp.setFont(font);
	enemyHp.setFillColor(sf::Color::White);
	enemyHp.setCharacterSize(16);
	enemyHp.setOutlineThickness(1.f);
	enemyHp.setOutlineColor(sf::Color::Black);

	currentPlayerHp.setFont(font);
	currentPlayerHp.setFillColor(sf::Color::Black);
	currentPlayerHp.setCharacterSize(20);

	maxHpBar.setSize({ 259.f,22.f });

	maxEXPBar.setSize({ 259.f,5.f });

	currentHpBar.setFillColor(sf::Color(255.f, 40.f, 80.f, 255.f));
	expBar.setFillColor(sf::Color(0.f, 255.f, 155.f, 255.f));

	level.setFont(font);
	level.setFillColor(sf::Color::Black);
	level.setCharacterSize(48);

	levelLabel.setFont(font);
	levelLabel.setFillColor(sf::Color::Black);
	levelLabel.setCharacterSize(20);

	score.setFont(font);
	score.setFillColor(sf::Color::Black);
	score.setCharacterSize(20);

	scoreLabel.setFont(font);
	scoreLabel.setFillColor(sf::Color::Black);
	scoreLabel.setCharacterSize(20);

	UIHUD.setSize({ 1440.f,900.f });
	UIHUD.setOrigin(UIHUD.getLocalBounds().width / 2, UIHUD.getLocalBounds().height / 2);
	HUDTexture.loadFromFile("Texture/UI.png");
	UIHUD.setTexture(&HUDTexture);

	iconSize_1 = { 90.f,90.f };
	iconSize_2 = { 112.5f,112.5f };

	weaponIcon_1.setSize(iconSize_1);
	weaponIcon_2.setSize(iconSize_1);
	weaponFrame_1.setSize(iconSize_1);
	weaponFrame_2.setSize(iconSize_1);

	lockedFrame = { 0,0,16,16 };
	firstFrame = { 0, 0, 16, 16 };
	secondFrame = { 16,0,16,16 };

	damage.setFont(font);
	damage.setFillColor(sf::Color::Black);
	damage.setCharacterSize(20);
}

void GUI::enemyUI(int currentHp, int maxHp, sf::Vector2f pos, sf::Vector2f size, sf::RenderTarget& other)
{
	enemyHp.setString(std::to_string(currentHp) + "/" + std::to_string(maxHp));
	enemyHp.setPosition(pos.x - enemyHp.getLocalBounds().width / 2, pos.y - size.y / 2 - 35.f);
	other.draw(enemyHp);
}

void GUI::screenUI(sf::Vector2f pos, float currentEXP, float maxEXP, int wave,
	int weapon_1, int weapon_2, int weaponDamage, int baseDamage, float currentPlayerHp,
	float maxPlayerHp, int slot, float waveTime, bool duringWave, bool enableToAttack, int score)
{
	//HP & EXP
	this->currentPlayerHp.setString("HP: " + std::to_string(static_cast<int>(currentPlayerHp)) + "/"
		+ std::to_string(static_cast<int>(maxPlayerHp)));
	exp.setString("EXP: " + std::to_string(static_cast<int>(currentEXP)) + "/"
		+ std::to_string(static_cast<int>(maxEXP)));

	//SCORE
	scoreLabel.setString("SCORE");
	this->score.setString(std::to_string(static_cast<int>((score))));
	scoreLabel.setOrigin(scoreLabel.getLocalBounds().width / 2, scoreLabel.getLocalBounds().top);
	this->score.setOrigin(this->score.getLocalBounds().width / 2, this->score.getLocalBounds().top);

	//LEVEL
	levelLabel.setString("LEVEL");
	level.setString(std::to_string(static_cast<int>((maxPlayerHp - 95)/5)));
	levelLabel.setOrigin(levelLabel.getLocalBounds().width / 2, levelLabel.getLocalBounds().top);
	level.setOrigin(level.getLocalBounds().width / 2, level.getLocalBounds().top);

	//DAMAGE
	damage.setString("DAMAGE : " + std::to_string(static_cast<int>(weaponDamage)) +
		" + " + std::to_string(static_cast<int>(baseDamage)));

	//WEAPON ICON
	if (weapon_1 == 0)
		WICO_1.loadFromFile("Texture/Blank.png");
	else if (weapon_1 == 1)
		WICO_1.loadFromFile("Texture/Sword.png");
	else
		WICO_1.loadFromFile("Texture/Hammer.png");
	if (weapon_2 == 0)
		WICO_2.loadFromFile("Texture/Blank.png");
	else if (weapon_2 == 1)
		WICO_2.loadFromFile("Texture/Sword.png");
	else
		WICO_2.loadFromFile("Texture/Hammer.png");

	WF_1.loadFromFile("Texture/WeaponFrame.png");
	WF_2.loadFromFile("Texture/WeaponFrame.png");

	weaponFrame_1.setTexture(&WF_1);
	weaponFrame_2.setTexture(&WF_2);
	weaponIcon_1.setTexture(&WICO_1);
	weaponIcon_1.setTextureRect(lockedFrame);
	weaponIcon_2.setTexture(&WICO_2);
	weaponIcon_2.setTextureRect(lockedFrame);
	if (slot == 0)
	{
		weaponIcon_1.setSize(iconSize_2);
		weaponIcon_2.setSize(iconSize_1);

		weaponFrame_1.setSize(iconSize_2);
		weaponFrame_2.setSize(iconSize_1);

		weaponFrame_1.setTextureRect(firstFrame);
		weaponFrame_2.setTextureRect(secondFrame);
		if (!enableToAttack)
		{
			weaponFrame_1.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
			weaponFrame_2.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
			weaponIcon_1.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
			weaponIcon_2.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
		}
		else
		{
			weaponFrame_1.setFillColor(sf::Color(255.f,255.f,255.f, 255.f));
			weaponFrame_2.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
			weaponIcon_1.setFillColor(sf::Color(255.f, 255.f, 255.f, 255.f));
			weaponIcon_2.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
		}
	}
	else
	{
		weaponIcon_1.setSize(iconSize_1);
		weaponIcon_2.setSize(iconSize_2);

		weaponFrame_1.setSize(iconSize_1);
		weaponFrame_2.setSize(iconSize_2);

		weaponFrame_1.setTextureRect(secondFrame);
		weaponFrame_2.setTextureRect(firstFrame);
		if (!enableToAttack)
		{
			weaponFrame_1.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
			weaponFrame_2.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
			weaponIcon_1.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
			weaponIcon_2.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
		}
		else
		{
			weaponFrame_1.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
			weaponFrame_2.setFillColor(sf::Color(255.f, 255.f, 255.f, 255.f));
			weaponIcon_1.setFillColor(sf::Color(128.f, 128.f, 128.f, 255.f));
			weaponIcon_2.setFillColor(sf::Color(255.f,255.f,255.f, 255.f));
		}
	}


	//WAVE
	this->wave.setString("Wave  " + std::to_string(wave + 1));
	this->wave.setOrigin(this->wave.getLocalBounds().width / 2, this->wave.getLocalBounds().height / 2);
	

	if (!duringWave)
	{
		if (waveTime >= 1.5f && waveTime <= 2.5f && opacity <= 252.45f)
			opacity += 2.55f;
		else if (waveTime >= 4.f && opacity >= 2.55f)
			opacity -= 2.55f;
	}

	this->wave.setFillColor(sf::Color(255, 255, 255, opacity));
	


	//SET POSITION
	damage.setPosition(pos.x - 380, pos.y + 395);
	damage.setOrigin(damage.getLocalBounds().width / 2, damage.getLocalBounds().top);

	scoreLabel.setPosition(pos.x + 652, pos.y - 416);
	this->score.setPosition(pos.x + 652, pos.y - 387);

	levelLabel.setPosition(pos.x - 657, pos.y - 416);
	level.setPosition(pos.x - 657, pos.y - 377);

	UIHUD.setPosition(pos.x, pos.y);

	this->wave.setPosition(pos.x, pos.y);

	maxHpBar.setPosition(pos.x - 467, pos.y - 416);
	maxEXPBar.setPosition(pos.x - 467, pos.y - 377);

	this->currentPlayerHp.setPosition(pos.x - 594, pos.y - 416);

	currentHpBar.setPosition(maxHpBar.getPosition());
	currentHpBar.setSize({ maxHpBar.getLocalBounds().width * (currentPlayerHp / maxPlayerHp), maxHpBar.getLocalBounds().height });

	exp.setPosition(pos.x - 594, pos.y - 386);

	expBar.setPosition(maxEXPBar.getPosition());
	expBar.setSize({ maxEXPBar.getLocalBounds().width * (currentEXP / maxEXP), maxEXPBar.getLocalBounds().height });

	weaponIcon_1.setPosition(pos.x - 710, pos.y + 330);
	weaponIcon_2.setPosition(weaponIcon_1.getPosition().x + weaponIcon_1.getLocalBounds().width + 7, weaponIcon_1.getPosition().y);

	weaponFrame_1.setPosition(weaponIcon_1.getPosition());
	weaponFrame_2.setPosition(weaponIcon_2.getPosition());
}

void GUI::render(sf::RenderTarget& other)
{
	other.draw(UIHUD);
	other.draw(currentHpBar);
	other.draw(expBar);

	other.draw(currentPlayerHp);
	other.draw(exp);

	other.draw(weaponFrame_1);
	other.draw(weaponFrame_2);

	other.draw(weaponIcon_1);
	other.draw(weaponIcon_2);

	other.draw(levelLabel);
	other.draw(level);
	
	other.draw(scoreLabel);
	other.draw(score);

	other.draw(damage);

	other.draw(this->wave);



}

void GUI::reset()
{
	opacity = 0;
	time = 0;
}
