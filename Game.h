#pragma once
#include "Player.h"
#include "Enemy_1.h"
#include "Knife.h"
#include "GUI.h"
class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode video;
	sf::View view;
	sf::Event event;
	sf::Sprite background;
	sf::Texture backgroundTexture;
	sf::Text enemyHp;
	sf::Font font;
	Player player;
	std::vector<Enemy_1*> enemies_1;
	Enemy_1* type_1;
	Knife knife;
	float spawnTimer;
	float spawnTimerMax;
	float attackTimer;
	float attackTimerMax;
	int weaponSlot = 1;
	int playerLevel = 1;
	bool attackCooldown;
	bool enableToAttack;
	int killCount = 0;
	int spawnCount = 0;
	int exp = 0;
	int expMax;
public:
	inline const bool running() { return window->isOpen(); }
	void setting();
	void pollEvent();
	void enemyUIUpdate(int index);
	void attackUpdate();
	void playerRange();
	void levelUpdate();
	void enemyUpdate();
	void killingUpdate();
	void update();
	void render();
};

