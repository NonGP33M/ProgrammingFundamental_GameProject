#include "Menu.h"

Menu::Menu(sf::RenderWindow* window, sf::View view)
{
	font.loadFromFile("Font/Retro Gaming.ttf");

	//MAIN_MENU
	title.setFont(font);
	title.setCharacterSize(72);
	title.setString("UNTITLED TITLE");
	title.setFillColor(sf::Color::White);
	title.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height);

	playButtonText.setFont(font);
	playButtonText.setCharacterSize(30);
	playButtonText.setString("PLAY");
	playButtonText.setFillColor(sf::Color::White);
	playButtonText.setOrigin(playButtonText.getLocalBounds().width / 2, playButtonText.getLocalBounds().height);

	leaderBoardButtonText.setFont(font);
	leaderBoardButtonText.setCharacterSize(30);
	leaderBoardButtonText.setString("LEADERBOARD");
	leaderBoardButtonText.setFillColor(sf::Color::White);
	leaderBoardButtonText.setOrigin(leaderBoardButtonText.getLocalBounds().width / 2, leaderBoardButtonText.getLocalBounds().height);

	exitButtonText.setFont(font);
	exitButtonText.setCharacterSize(30);
	exitButtonText.setString("EXIT");
	exitButtonText.setFillColor(sf::Color::White);
	exitButtonText.setOrigin(exitButtonText.getLocalBounds().width / 2, exitButtonText.getLocalBounds().height);

	playButton.setSize(buttonSize);
	playButton.setOrigin(playButton.getLocalBounds().width / 2, playButton.getLocalBounds().height / 2);
	playButton.setFillColor(sf::Color::Transparent);
	playButton.setOutlineColor(sf::Color::White);
	playButton.setOutlineThickness(1.f);

	leaderBoardButton.setSize(buttonSize);
	leaderBoardButton.setOrigin(leaderBoardButton.getLocalBounds().width / 2, leaderBoardButton.getLocalBounds().height / 2);
	leaderBoardButton.setFillColor(sf::Color::Transparent);
	leaderBoardButton.setOutlineColor(sf::Color::White);
	leaderBoardButton.setOutlineThickness(1.f);

	exitButton.setSize(buttonSize);
	exitButton.setOrigin(exitButton.getLocalBounds().width / 2, exitButton.getLocalBounds().height / 2);
	exitButton.setFillColor(sf::Color::Transparent);
	exitButton.setOutlineColor(sf::Color::White);
	exitButton.setOutlineThickness(1.f);

	//LEADERBOARD_MENU
	leaderBoardTitle.setFont(font);
	leaderBoardTitle.setCharacterSize(60);
	leaderBoardTitle.setString("LEADERBOARD");
	leaderBoardTitle.setFillColor(sf::Color::White);
	leaderBoardTitle.setOrigin(leaderBoardTitle.getLocalBounds().width / 2, leaderBoardTitle.getLocalBounds().height / 2);

	frame.setSize({ 800.f, 400.f });
	frame.setOrigin(frame.getLocalBounds().width / 2, frame.getLocalBounds().height / 2);
	frame.setFillColor(sf::Color::Transparent);
	frame.setOutlineColor(sf::Color::White);
	frame.setOutlineThickness(1.f);

	backButtonText.setFont(font);
	backButtonText.setCharacterSize(30);
	backButtonText.setString("Back");
	backButtonText.setFillColor(sf::Color::White);
	backButtonText.setOrigin(backButtonText.getLocalBounds().width / 2, backButtonText.getLocalBounds().height);

	backButton.setSize({ 150.f, 75.f });
	backButton.setOrigin(backButton.getLocalBounds().width / 2, backButton.getLocalBounds().height / 2);
	backButton.setFillColor(sf::Color::Transparent);
	backButton.setOutlineColor(sf::Color::White);
	backButton.setOutlineThickness(1.f);

	//PAUSE_MENU
	resumeButtonText.setFont(font);
	resumeButtonText.setCharacterSize(30);
	resumeButtonText.setString("Resume");
	resumeButtonText.setFillColor(sf::Color::White);
	resumeButtonText.setOrigin(resumeButtonText.getLocalBounds().width / 2, resumeButtonText.getLocalBounds().height);

	mainMenuButtonText.setFont(font);
	mainMenuButtonText.setCharacterSize(30);
	mainMenuButtonText.setString("Main menu");
	mainMenuButtonText.setFillColor(sf::Color::White);
	mainMenuButtonText.setOrigin(mainMenuButtonText.getLocalBounds().width / 2, mainMenuButtonText.getLocalBounds().height);

	resumeButton.setSize(buttonSize);
	resumeButton.setOrigin(resumeButton.getLocalBounds().width / 2, resumeButton.getLocalBounds().height / 2);
	resumeButton.setFillColor(sf::Color::Transparent);
	resumeButton.setOutlineColor(sf::Color::White);
	resumeButton.setOutlineThickness(1.f);

	mainMenuButton.setSize(buttonSize);
	mainMenuButton.setOrigin(mainMenuButton.getLocalBounds().width / 2, mainMenuButton.getLocalBounds().height / 2);
	mainMenuButton.setFillColor(sf::Color::Transparent);
	mainMenuButton.setOutlineColor(sf::Color::White);
	mainMenuButton.setOutlineThickness(1.f);

	pauseMenuBackground.setSize({ 1920.f, 1080.f });
	pauseMenuBackground.setOrigin(pauseMenuBackground.getSize().x / 2, pauseMenuBackground.getSize().y / 2);
	pauseMenuBackground.setFillColor(sf::Color(90.f, 90.f, 90.f, 255.f));

	//GAMEOVER
	gameOverTitle.setFont(font);
	gameOverTitle.setCharacterSize(100);
	gameOverTitle.setString("GAME OVER");
	gameOverTitle.setFillColor(sf::Color::White);
	gameOverTitle.setOrigin(gameOverTitle.getLocalBounds().width / 2, gameOverTitle.getLocalBounds().height);

	tryAgainButtonText.setFont(font);
	tryAgainButtonText.setCharacterSize(30);
	tryAgainButtonText.setString("Try again");
	tryAgainButtonText.setFillColor(sf::Color::White);
	tryAgainButtonText.setOrigin(tryAgainButtonText.getLocalBounds().width / 2, tryAgainButtonText.getLocalBounds().height / 1.5);

	tryAgainButton.setSize(buttonSize);
	tryAgainButton.setOrigin(tryAgainButton.getLocalBounds().width / 2, tryAgainButton.getLocalBounds().height / 2);
	tryAgainButton.setFillColor(sf::Color::Transparent);
	tryAgainButton.setOutlineColor(sf::Color::White);
	tryAgainButton.setOutlineThickness(1.f);

	this->window = window;
	this->view = view;
}

void Menu::pauseCheck()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		states = PAUSE;
}

void Menu::mainMenuUpdate()
{
	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	title.setPosition(view.getCenter().x, view.getCenter().y - 200);

	playButtonText.setPosition(view.getCenter().x, view.getCenter().y + 100);
	leaderBoardButtonText.setPosition(view.getCenter().x, view.getCenter().y + 200);
	exitButtonText.setPosition(view.getCenter().x, view.getCenter().y + 300);

	playButton.setPosition(view.getCenter().x, view.getCenter().y + 100);
	leaderBoardButton.setPosition(view.getCenter().x, view.getCenter().y + 200);
	exitButton.setPosition(view.getCenter().x, view.getCenter().y + 300);

	if (playButton.getGlobalBounds().contains(screenPos))
	{
		playButtonText.setScale(1.5f, 1.5f);
		playButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			states = PLAY;
		}
	}
	else
	{
		playButtonText.setScale(1.f, 1.f);
		playButton.setScale(1.f, 1.f);
	}

	if (leaderBoardButton.getGlobalBounds().contains(screenPos))
	{
		leaderBoardButtonText.setScale(1.5f, 1.5f);
		leaderBoardButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			states = LEADERBOARD;
		}
	}
	else
	{
		leaderBoardButtonText.setScale(1.f, 1.f);
		leaderBoardButton.setScale(1.f, 1.f);
	}

	if (exitButton.getGlobalBounds().contains(screenPos))
	{
		exitButtonText.setScale(1.5f, 1.5f);
		exitButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			window->close();
	}
	else
	{
		exitButtonText.setScale(1.f, 1.f);
		exitButton.setScale(1.f, 1.f);
	}
}

void Menu::mainMenuRender()
{
	window->setView(view);
	window->clear();
	
	window->draw(title);
	window->draw(playButtonText);
	window->draw(leaderBoardButtonText);
	window->draw(exitButtonText);
	window->draw(playButton);
	window->draw(leaderBoardButton);
	window->draw(exitButton);

	window->display();
}

void Menu::leaderBoardMenuUpdate()
{
	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	leaderBoardTitle.setPosition(view.getCenter().x, view.getCenter().y - 300);

	frame.setPosition(view.getCenter().x, view.getCenter().y);

	backButtonText.setPosition(view.getCenter().x - 320, view.getCenter().y + 260);
	backButton.setPosition(view.getCenter().x - 320, view.getCenter().y + 260);
	
	if (backButton.getGlobalBounds().contains(screenPos))
	{
		backButtonText.setScale(1.5f, 1.5f);
		backButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			states = MENU;
		}
	}
	else
	{
		backButtonText.setScale(1.f, 1.f);
		backButton.setScale(1.f, 1.f);
	}
}

void Menu::leaderBoardMenuRender()
{
	window->setView(view);
	window->clear();

	window->draw(leaderBoardTitle);
	window->draw(frame);
	window->draw(backButton);
	window->draw(backButtonText);

	score.render(*window, view);

	window->display();
}

void Menu::pauseMenuUpdate()
{
	resumeButtonText.setPosition(view.getCenter().x - 200, view.getCenter().y);
	mainMenuButtonText.setPosition(view.getCenter().x + 200, view.getCenter().y);

	resumeButton.setPosition(view.getCenter().x - 200, view.getCenter().y);
	mainMenuButton.setPosition(view.getCenter().x + 200, view.getCenter().y);

	pauseMenuBackground.setPosition(view.getCenter());

	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	if (resumeButton.getGlobalBounds().contains(screenPos))
	{
		resumeButtonText.setScale(1.5f, 1.5f);
		resumeButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			states = PLAY;
		}
	}
	else
	{
		resumeButtonText.setScale(1.f, 1.f);
		resumeButton.setScale(1.f, 1.f);
	}

	if (mainMenuButton.getGlobalBounds().contains(screenPos))
	{
		mainMenuButtonText.setScale(1.5f, 1.5f);
		mainMenuButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			states = MENU;
		}
	}
	else
	{
		mainMenuButtonText.setScale(1.f, 1.f);
		mainMenuButton.setScale(1.f, 1.f);
	}
}

void Menu::pauseMenuRender()
{
	this->window->setView(view);
	this->window->clear();

	//this->window->draw(pauseMenuBackground);
	this->window->draw(mainMenuButtonText);
	this->window->draw(resumeButtonText);
	this->window->draw(resumeButton);
	this->window->draw(mainMenuButton);

	this->window->display();
}

void Menu::gameOverMenuUpdate()
{
	gameOverTitle.setPosition(view.getCenter().x, view.getCenter().y - 100);

	tryAgainButtonText.setPosition(view.getCenter().x - 200, view.getCenter().y);
	mainMenuButtonText.setPosition(view.getCenter().x + 200, view.getCenter().y);

	tryAgainButton.setPosition(view.getCenter().x - 200, view.getCenter().y);
	mainMenuButton.setPosition(view.getCenter().x + 200, view.getCenter().y);

	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	if (tryAgainButton.getGlobalBounds().contains(screenPos))
	{
		tryAgainButtonText.setScale(1.5f, 1.5f);
		tryAgainButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			tryAgainClick = true;
		}
	}
	else
	{
		tryAgainButtonText.setScale(1.f, 1.f);
		tryAgainButton.setScale(1.f, 1.f);
	}

	if (mainMenuButton.getGlobalBounds().contains(screenPos))
	{
		mainMenuButtonText.setScale(1.5f, 1.5f);
		mainMenuButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			states = MENU;
		}
	}
	else
	{
		mainMenuButtonText.setScale(1.f, 1.f);
		mainMenuButton.setScale(1.f, 1.f);
	}
}

void Menu::gameOverMenuRender()
{
	this->window->setView(view);
	this->window->clear();

	this->window->draw(gameOverTitle);
	this->window->draw(tryAgainButtonText);
	this->window->draw(tryAgainButton);
	this->window->draw(mainMenuButtonText);
	this->window->draw(mainMenuButton);

	this->window->display();
}
