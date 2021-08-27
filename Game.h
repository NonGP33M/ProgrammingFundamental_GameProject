#pragma once
#include "Player.h"
class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode video;
	sf::View view;
	sf::Event event;
	Player player;
	std::vector<Enemy_1*> enemies_1;
	Enemy_1* type_1;
	Knife knife;
	float spawnTimer;
	float spawnTimerMax;
	float attackTimer;
	float attackTimerMax;
	int weaponSlot = 1;
	float playerLevel = 1.f;
	bool enableToAttack;
public:
	inline const bool running() { return window->isOpen(); }
	void setting();
	void pollEvent();
	void attackUpdate();
	void playerRange();
	void enemyUpdate();
	void killingUpdate();
	void update();
	void render();
};

