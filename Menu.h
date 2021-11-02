#pragma once
#include <SFML/Graphics.hpp>

enum STATE { MENU, PLAY, PAUSE, GAMEOVER, LEADERBOARD };

class Menu
{
private:
	sf::Event event;
	sf::View view;
	sf::Font font;

	//MAIN_MENU
	sf::Text title;
	sf::Text playButtonText;
	sf::Text exitButtonText;
	sf::RenderWindow* window;
	sf::RectangleShape playButton;
	sf::RectangleShape exitButton;

	//PAUSE_MENU
	sf::Text resumeButtonText;
	sf::Text mainMenuButtonText;
	sf::RectangleShape pauseMenuBackground;
	sf::RectangleShape resumeButton;
	sf::RectangleShape mainMenuButton;

	//GAMEOVER
	sf::Text tryAgainButtonText;
	sf::RectangleShape tryAgainButton;

	bool pausing;
	int states;
public:
	Menu(sf::RenderWindow* window, sf::View view);
	inline int getStates() { return states; }
	void pauseCheck();
	void gameOverCheck();
	void mainMenuUpdate();
	void mainMenuRender();
	void pauseMenuUpdate();
	void pauseMenuRender();
	void gameOverUpdate();
	void gameOverRender();
};

