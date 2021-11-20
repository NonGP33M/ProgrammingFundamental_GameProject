#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>


class Enemy
{
private:
	sf::RectangleShape enemy;
	sf::RectangleShape enemyHitBox;
	sf::RectangleShape enemySight;
	sf::FloatRect nextPos;
	sf::Vector2f position;
	sf::Vector2f size;

	int type;
	float randomX;
	float randomY;
	float timeStamp;
	float MaxHp;
	float currentHp;
	float exp;
	float movementSpeed;
	float damage;
	float timeAfter;
	float timeBefore;
	bool enableToAttack;
	bool cooldown;
	bool isBoss;
	bool knockingback = false;

	float attackTimer = 0;
	float movingTimer = 0;

	float knockbackspeed = 5;

	sf::Vector2f randomDir;
	sf::Vector2f dir;
	sf::Vector2f normalizedDir;
	sf::Vector2f knockbackDir;
	sf::Vector2f normalizedKnockbackDir;
public:
	Enemy(char type, float posX, float posY, float wave);
	inline const sf::FloatRect getBound() { return enemy.getGlobalBounds(); }
	inline const sf::FloatRect getHitBoxBound() { return enemyHitBox.getGlobalBounds(); }
	inline const sf::Vector2f getPos() { return enemy.getPosition(); }
	inline const int getHp() { return currentHp; }
	inline const int getMaxHp() { return MaxHp; }
	inline const int getEXP() { return exp; }
	inline const int getType() { return this->type; }
	inline const int getDamage() { return damage; }
	inline const bool bossCheck() { return isBoss; }
	inline const sf::Vector2f getSize() { return size; }
	inline const sf::Vector2f getNormalizedDir() { return normalizedDir; }
	inline const bool enemyAttackCooldown() { return cooldown; }
	inline const float randomAngle() { return ((rand()%2001)-1000);}
	inline const float randomTime(int range, int add) { return rand() % range + add; }
	inline void knockBack() { knockingback = true; }
	void timeTicking(float deltatime);
	void attackCooldown();
	void doDamage(int& playerHp);
	void takeDamage(float damage, int weapon);
	void knockBackUpdate();
	void movement(sf::Vector2f playerPos, sf::Vector2f playerHitBoxPos, sf::FloatRect playerBound);
	void checkObstruct(sf::FloatRect thisPos, sf::FloatRect otherPos);
	void update();
	void render(sf::RenderTarget& other);
};

