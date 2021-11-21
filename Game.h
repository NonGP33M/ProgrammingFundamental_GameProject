#pragma once
#include "Player.h"
#include "Enemy.h"
#include "WeaponHitbox.h"
#include "GUI.h"
#include "ItemDrop.h"

enum playerWeapon { NOTHING, SWORD, HAMMER };

class Game
{
private:
	sf::RenderWindow* window;
	sf::View view;
	sf::Event event;
	sf::RectangleShape background;
	sf::Texture backgroundTexture;
	sf::Font font;
	sf::Text enemyHp;

	Player player;
	std::vector<Enemy*> enemies;
	Enemy* enemy;
	std::vector<ItemDrop*> drop;
	ItemDrop* item;
	GUI gui;
	WeaponHitbox weaponHitbox;
	
	sf::Vector2f playerPos;
	float playerBaseDamage;
	float attackTimerMax;
	float attackingTimer = 3;
	float deltatime = 0;
	float pickingTime = 0;
	float gameOverTime = 0;
	float spawningTime = 0;

	int currentSlot = 0;
	int weaponSlot[2];
	int weaponDamage[2];

	int playerLevel = 0;
	int currentPlayerHp;
	int maxPlayerHp;
	int exp = 0;
	int maxExp;
	int playerWeapon = SWORD;

	std::string spawner;
	char enemyType;

	bool enableToAttack = true;
	bool duringWave;
	bool gameOver = false;
	
	int wave = 0;
	int enemyLeft;
	int killCount = 0;
	int spawnCount = 0;
	int score = 0;

public:
	Game(sf::RenderWindow* window, sf::View view);
	inline const sf::Vector2f getViewPos() { return view.getCenter(); }
	inline const bool gameOverCheck() { return gameOver; }
	inline const int getScore() { return score; }
	void timeTicking(float deltatime);
	void pollEvent();
	void screenUIupdate();
	void takeItemUpdate();
	void attackUpdate();
	void playerAttack();
	void playerAttackRange();
	void playerLevelUpdate();
	void waveUpdate();
	void enemyUpdate();
	void itemDropUpdate();
	void playerUpdate();
	void update();
	void render();
	void gameReset();
	void pauseRender();
};
