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
	sf::Clock attackCoolDownClock;
	sf::Clock enemySpawningClock;

	Player player;
	std::vector<Enemy*> enemies;
	Enemy* enemy;
	std::vector<ItemDrop*> drop;
	ItemDrop* item;
	GUI gui;
	WeaponHitbox weaponHitbox;
	
	sf::Vector2f playerPos;
	float playerBaseDamage;
	float spawnTimer;
	float spawnTimerMax;
	float attackTimer;
	float attackTimerMax;

	int currentSlot = 0;
	int weaponSlot[2];
	int weaponDamage[2];

	int playerLevel = 1;
	int currentPlayerHp;
	int maxPlayerHp;
	int exp = 0;
	int maxExp;
	int playerWeapon = SWORD;

	std::string spawner;
	char enemyType;

	bool attackCooldown;
	bool enableToAttack;
	bool duringWave;
	bool gameOver = false;
	
	int wave = 0;
	int enemyLeft;
	int killCount = 0;
	int spawnCount = 0;

public:
	Game(sf::RenderWindow* window, sf::View view);
	inline const sf::Vector2f getViewPos() { return view.getCenter(); }
	inline const bool gameOverCheck() { return gameOver; }
	void pollEvent();
	void screenUIupdate();
	void takeItemUpdate();
	void attackUpdate();
	void playerAttackRange();
	void playerLevelUpdate();
	void waveUpdate();
	void enemyUpdate();
	void update();
	void render();
	void gameReset();
};
