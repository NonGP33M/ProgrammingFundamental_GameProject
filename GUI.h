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
	sf::Text weapon;
	sf::Text weaponSlot;
	sf::Text weaponSlot_1;
	sf::Text currentPlayerHp;
	sf::RectangleShape maxHpBar;
	sf::RectangleShape currentHpBar;
	sf::RectangleShape maxEXPBar;
	sf::RectangleShape expBar;
	sf::RectangleShape UIHUD;
	sf::Texture HUDTexture;

public:
	GUI();
	void enemyUI(int currentHp, int maxHp, sf::Vector2f pos, sf::Vector2f size, sf::RenderTarget& other);
	void screenUI(sf::Vector2f pos, float currentEXP, float maxEXP, int wave, 
		int currentWeapon, int weaponDamage, int baseDamage, float currentPlayerHp, float maxPlayerHp, int slot);
	void render(sf::RenderTarget& other);
};

