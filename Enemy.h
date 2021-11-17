#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Enemy
{
private:
	sf::RectangleShape enemy;
	sf::RectangleShape enemyHitBox;
	sf::FloatRect nextPos;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Clock attackClock;

	int type;
	float attackTimer;
	float timeStamp;
	float MaxHp;
	float currentHp;
	float exp;
	float movementSpeed;
	float damage;
	bool enableToAttack;
	bool cooldown;
	bool isBoss;

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
	inline const bool bossCheck() { return isBoss; }
	inline const sf::Vector2f getSize() { return size; }
	inline const sf::Vector2f getNormalizedDir() { return normalizedDir; }
	inline const bool enemyAttackCooldown() { return cooldown; }
	void attackCooldown();
	void doDamage(int& playerHp);
	void takeDamage(float damage, int weapon);
	void knockBack();
	void movement(sf::Vector2f playerPos, sf::Vector2f playerHitBoxPos);
	void checkObstruct(sf::FloatRect thisPos, sf::FloatRect otherPos);
	void update();
	void render(sf::RenderTarget& other);
};

