#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Score.h"

enum STATE { MENU, PLAY, PAUSE, LEADERBOARD, GAMEOVER, NAME, HELP};

class Menu
{
private:
	Score score;
	sf::Event event;
	sf::View view;
	sf::Font font;
	sf::Vector2f buttonSize = { 350.f, 80.f };

	sf::RectangleShape greyScreen;
	sf::Texture buttonTexture;
	sf::Texture mediumButtonTexture;
	sf::Texture smallButtonTexture;
	sf::Texture shortButtonTexture;
	sf::Texture backgroundTexture;
	sf::Texture helpTexture;

	//MAIN_MENU
	sf::Text title;
	sf::Text myName;
	sf::Text playButtonText;
	sf::Text leaderBoardButtonText;
	sf::Text exitButtonText;
	sf::Text helpButtonText;
	sf::RenderWindow* window;
	sf::RectangleShape playButton;
	sf::RectangleShape leaderBoardButton;
	sf::RectangleShape exitButton;
	sf::RectangleShape mainBackground;
	sf::RectangleShape helpButton;

	//PAUSE_MENU
	sf::Text resumeButtonText;
	sf::Text mainMenuButtonText;
	sf::RectangleShape resumeButton;
	sf::RectangleShape mainMenuButton;

	//LEADERBOARD_MENU
	sf::Texture frameTexture;
	sf::Text leaderBoardTitle;
	sf::Text backButtonText;
	sf::RectangleShape frame;
	sf::RectangleShape backButton;
	sf::RectangleShape leaderboardBackground;
	sf::Text showingName[5];
	sf::Text showingScore[5];

	//GAMEOVER_MENU
	sf::Text gameOverTitle;
	sf::Text tryAgainButtonText;
	sf::RectangleShape tryAgainButton;

	//NAME_MENU
	sf::Texture nameFrameTexture;
	sf::RectangleShape nameFrame;
	sf::RectangleShape nameFill;
	sf::RectangleShape confirmButton;
	sf::RectangleShape backButton_2;
	sf::Text confirmButtonText;
	sf::Text backButtonText_2;
	sf::Text name;
	sf::Text cursor;
	std::string enteredName;
	
	//HELP
	sf::RectangleShape helpFrame;

	
	int buttonTextSize;
	
	bool tryAgainClick = false;
	bool enableToType = true;
	bool start = false;
	float transitionDebounce;
	float typingDebounce;
	float cursorBlinking;
	int states;
	int playerScore;
public:
	Menu(sf::RenderWindow* window, sf::View view);
	inline int getStates() { return states; }
	inline bool tryAgainCheck() { return tryAgainClick; }
	inline bool startCheck() { return start; }
	inline void tryAgainClickSetToFalse() { tryAgainClick = false; }
	inline void gameOver() { states = GAMEOVER; }
	inline void tryAgain() { states = PLAY; }
	inline void setScore(int score) { playerScore = score; }
	inline void started() { start = false; }
	inline void timeTicking(float deltatime) { transitionDebounce += deltatime; 
	typingDebounce += deltatime; cursorBlinking += deltatime;}
	void updateScore();
	void pauseCheck();
	void mainMenuUpdate();
	void mainMenuRender();
	void leaderBoardMenuUpdate();
	void leaderBoardMenuRender();
	void pauseMenuUpdate();
	void pauseMenuRender();
	void gameOverMenuUpdate();
	void gameOverMenuRender();
	void nameUpdate(std::vector<sf::Event> event);
	void nameRender();
	void helpUpdate();
	void helpRender();
	void mainMenuRenderComponent();
};

