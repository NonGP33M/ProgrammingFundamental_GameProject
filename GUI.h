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
	sf::Text currentPlayerHp;
	sf::Text level;
	sf::Text levelLabel;
	sf::Text damage;
	sf::Text scoreLabel;
	sf::Text score;
	sf::Text enemyToGo;
	sf::RectangleShape maxHpBar;
	sf::RectangleShape currentHpBar;
	sf::RectangleShape maxEXPBar;
	sf::RectangleShape expBar;
	sf::RectangleShape UIHUD;
	sf::RectangleShape weaponIcon_1;
	sf::RectangleShape weaponIcon_2;
	sf::RectangleShape weaponFrame_1;
	sf::RectangleShape weaponFrame_2;
	sf::Texture HUDTexture;
	sf::Texture WICO_1;
	sf::Texture WICO_2;
	sf::Texture WF_1;
	sf::Texture WF_2;
	sf::Vector2f iconSize_1;
	sf::Vector2f iconSize_2;
	sf::IntRect lockedFrame;
	sf::IntRect firstFrame;
	sf::IntRect secondFrame;
	float opacity = 0;
	float time = 0;

public:
	GUI();
	void enemyUI(int currentHp, int maxHp, sf::Vector2f pos, sf::Vector2f size, sf::RenderTarget& other);
	void screenUI(sf::Vector2f pos, float currentEXP, float maxEXP, int wave, 
		int weapon_1, int weapon_2, int weaponDamage, int baseDamage, float currentPlayerHp,
		float maxPlayerHp, int slot, float waveTime, bool duringWave, bool enableToAttack, int score,
		bool isKnockingBack, int enemyleft);
	void render(sf::RenderTarget& other);
	void reset();
};

