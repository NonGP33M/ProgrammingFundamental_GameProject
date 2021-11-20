#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

class Score
{
private:
	std::FILE* fp;
	sf::RenderWindow* window;
	sf::View view;
	sf::Font font;
	sf::Text leaderName[5];
	sf::Text leaderScore[5];
	std::string name[6];
	char temp[255];
	int score[6];

	std::vector<std::pair<int, std::string>> scorePair;
public:
	Score();
	void setScoreBoard();
	void getName();
	void writeFile(std::string playerName, int playerScore);
	void render(sf::RenderTarget& window, sf::View view);
};

