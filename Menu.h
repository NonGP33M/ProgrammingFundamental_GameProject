#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Score.h"

enum STATE { MENU, PLAY, PAUSE, LEADERBOARD, GAMEOVER};

class Menu
{
private:
	Score score;
	sf::Event event;
	sf::View view;
	sf::Font font;
	sf::Vector2f buttonSize = { 350.f, 80.f };
	sf::Clock debounce;

	//MAIN_MENU
	sf::Text title;
	sf::Text playButtonText;
	sf::Text leaderBoardButtonText;
	sf::Text exitButtonText;
	sf::RenderWindow* window;
	sf::RectangleShape playButton;
	sf::RectangleShape leaderBoardButton;
	sf::RectangleShape exitButton;
	sf::RectangleShape mainBackground;

	//PAUSE_MENU
	sf::Text resumeButtonText;
	sf::Text mainMenuButtonText;
	sf::RectangleShape pauseMenuBackground;
	sf::RectangleShape resumeButton;
	sf::RectangleShape mainMenuButton;

	//LEADERBOARD_MENU
	sf::Text leaderBoardTitle;
	sf::Text backButtonText;
	sf::RectangleShape frame;
	sf::RectangleShape backButton;

	//GAMEOVER_MENU
	sf::Text gameOverTitle;
	sf::Text tryAgainButtonText;
	sf::RectangleShape tryAgainButton;

	bool tryAgainClick = false;
	bool transition = false;
	float transitionDebounce;
	int states;
public:
	Menu(sf::RenderWindow* window, sf::View view);
	inline int getStates() { return states; }
	inline bool tryAgainCheck() { return tryAgainClick; }
	inline void tryAgainClickSetToFalse() { tryAgainClick = false; }
	inline void gameOver() { states = GAMEOVER; }
	inline void tryAgain() { states = PLAY; }
	void pauseCheck();
	void mainMenuUpdate();
	void mainMenuRender();
	void leaderBoardMenuUpdate();
	void leaderBoardMenuRender();
	void pauseMenuUpdate();
	void pauseMenuRender();
	void gameOverMenuUpdate();
	void gameOverMenuRender();
};

