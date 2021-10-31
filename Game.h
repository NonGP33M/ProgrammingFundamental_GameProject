#pragma once
#include "Player.h"
#include "Enemy.h"
#include "WeaponHitbox.h"
#include "GUI.h"
#include "ItemDrop.h"

enum playerWeapon { NOTHING, DAGGER, SWORD, AXE, BOW };

class Game
{
private:
	sf::RenderWindow* window;
	sf::View view;
	sf::Event event;
	sf::Sprite background;
	sf::Texture backgroundTexture;
	sf::Text enemyHp;
	sf::Font font;
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
	float deltaTime;
	float playerBaseDamage;
	float spawnTimer;
	float spawnTimerMax;
	float attackTimer;
	float attackTimerMax;
	int currentSlot;
	int weaponSlot[2] = { 1,0 };
	int weaponDamage[2] = { 2,0 };
	int playerLevel = 1;
	bool attackCooldown;
	bool enableToAttack;
	bool duringWave;
	int playerWeapon = DAGGER;
	int wave = 0;
	int enemyLeft;
	int killCount = 0;
	int spawnCount = 0;
	int exp = 0;
	int expMax;
	int enemyType;

public:
	Game(sf::RenderWindow* window);
	bool pause = false;
	inline const sf::Vector2f getPlayerPos() { return this->playerPos; }
	inline const bool pauseCheck() { return pause; }
	inline const sf::Vector2f getViewPos() { return view.getCenter(); }
	void pollEvent();
	void playerUIupdate();
	void enemyUIUpdate(int index);
	void takeItemUpdate();
	void attackUpdate();
	void playerAttackRange();
	void levelUpdate();
	void enemyInit();
	void enemyUpdate();
	void update();
	void render();
};

