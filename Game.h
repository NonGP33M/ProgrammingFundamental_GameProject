#pragma once
#include "Player.h"
#include "Enemy_1.h"
#include "Enemy_2.h"
#include "Knife.h"
#include "GUI.h"
#include "ItemDrop.h"

enum playerWeapon { NOTHING, DAGGER, SWORD, AXE, BOW };

class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode video;
	sf::View view;
	sf::Event event;
	sf::Sprite background;
	sf::Texture backgroundTexture;
	sf::Text enemy_1Hp;
	sf::Text enemy_2Hp;
	sf::Font font;

	Player player;
	std::vector<Enemy_1*> enemies_1;
	Enemy_1* type_1;
	std::vector<Enemy_2*> enemies_2;
	Enemy_2* type_2;
	std::vector<ItemDrop*> drop;
	ItemDrop* item;
	GUI gui;
	Knife knife;

	float playerBaseDamage;
	float spawnTimer;
	float spawnTimerMax;
	float attackTimer;
	float attackTimerMax;
	int currentSlot;
	int weaponSlot[2] = { 1,0 };
	int playerLevel = 1;
	bool attackCooldown;
	bool enableToAttack;
	int playerWeapon = DAGGER;
	int wave = 1;
	int enemyLeft;
	int killCount = 0;
	int spawnCount = 0;
	int exp = 0;
	int expMax;
	int enemyType;
public:
	inline const bool running() { return window->isOpen(); }
	void setting();
	void pollEvent();
	void UIupdate();
	void enemy_1UIUpdate(int index);
	void enemy_2UIUpdate(int index);
	void takeItemUpdate();
	void attackUpdate();
	void playerAttackRange();
	void levelUpdate();
	void enemyUpdate();
	void killingUpdate();
	void update();
	void render();
};

