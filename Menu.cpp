#include "Menu.h"

Menu::Menu(sf::RenderWindow* window, sf::View view)
{
	font.loadFromFile("Font/dogica.ttf");

	//MAIN_MENU
	title.setFont(font);
	title.setLetterSpacing(0.5f);
	title.setFont(font);
	title.setLetterSpacing(0.5f);
	title.setOutlineThickness(1.2f);
	title.setOutlineColor(sf::Color::White);
	title.setString("UNTITLED TITLE");
	title.setCharacterSize(36);
	title.setFillColor(sf::Color::White);
	title.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 2);

	playButtonText.setFont(font);
	playButtonText.setLetterSpacing(0.5f);
	playButtonText.setOutlineThickness(1.2f);
	playButtonText.setOutlineColor(sf::Color::White);
	playButtonText.setString("PLAY");
	playButtonText.setCharacterSize(16);
	playButtonText.setFillColor(sf::Color::White);
	playButtonText.setOrigin(playButtonText.getLocalBounds().width / 2, playButtonText.getLocalBounds().height / 2);

	exitButtonText.setFont(font);
	exitButtonText.setLetterSpacing(0.5f);
	exitButtonText.setOutlineThickness(1.2f);
	exitButtonText.setOutlineColor(sf::Color::White);
	exitButtonText.setString("EXIT");
	exitButtonText.setCharacterSize(16);
	exitButtonText.setFillColor(sf::Color::White);
	exitButtonText.setOrigin(exitButtonText.getLocalBounds().width / 2, exitButtonText.getLocalBounds().height / 2);

	playButton.setSize({ 200.f, 50.f });
	playButton.setOrigin(playButton.getLocalBounds().width / 2, playButton.getLocalBounds().height / 2);
	playButton.setFillColor(sf::Color::Transparent);
	playButton.setOutlineColor(sf::Color::White);
	playButton.setOutlineThickness(1.f);

	exitButton.setSize({ 200.f, 50.f });
	exitButton.setOrigin(exitButton.getLocalBounds().width / 2, exitButton.getLocalBounds().height / 2);
	exitButton.setFillColor(sf::Color::Transparent);
	exitButton.setOutlineColor(sf::Color::White);
	exitButton.setOutlineThickness(1.f);

	//PAUSE_MENU
	resumeButtonText.setFont(font);
	resumeButtonText.setLetterSpacing(0.5f);
	resumeButtonText.setOutlineThickness(1.2f);
	resumeButtonText.setOutlineColor(sf::Color::White);
	resumeButtonText.setString("RESUME");
	resumeButtonText.setCharacterSize(16);
	resumeButtonText.setFillColor(sf::Color::White);
	resumeButtonText.setOrigin(resumeButtonText.getLocalBounds().width / 2, resumeButtonText.getLocalBounds().height / 2);

	mainMenuButtonText.setFont(font);
	mainMenuButtonText.setLetterSpacing(0.5f);
	mainMenuButtonText.setOutlineThickness(1.2f);
	mainMenuButtonText.setOutlineColor(sf::Color::White);
	mainMenuButtonText.setString("MAIN MENU");
	mainMenuButtonText.setCharacterSize(16);
	mainMenuButtonText.setFillColor(sf::Color::White);
	mainMenuButtonText.setOrigin(mainMenuButtonText.getLocalBounds().width / 2, mainMenuButtonText.getLocalBounds().height / 2);

	resumeButton.setSize({ 200.f, 50.f });
	resumeButton.setOrigin(resumeButton.getLocalBounds().width / 2, resumeButton.getLocalBounds().height / 2);
	resumeButton.setFillColor(sf::Color::Transparent);
	resumeButton.setOutlineColor(sf::Color::White);
	resumeButton.setOutlineThickness(1.f);

	mainMenuButton.setSize({ 200.f, 50.f });
	mainMenuButton.setOrigin(mainMenuButton.getLocalBounds().width / 2, mainMenuButton.getLocalBounds().height / 2);
	mainMenuButton.setFillColor(sf::Color::Transparent);
	mainMenuButton.setOutlineColor(sf::Color::White);
	mainMenuButton.setOutlineThickness(1.f);

	pauseMenuBackground.setSize({ 1920.f, 1080.f });
	pauseMenuBackground.setOrigin(pauseMenuBackground.getSize().x / 2, pauseMenuBackground.getSize().y / 2);
	pauseMenuBackground.setFillColor(sf::Color(90.f, 90.f, 90.f, 255.f));

	//GAMEOVER
	tryAgainButtonText.setFont(font);
	tryAgainButtonText.setLetterSpacing(0.5f);
	tryAgainButtonText.setOutlineThickness(1.2f);
	tryAgainButtonText.setOutlineColor(sf::Color::White);
	tryAgainButtonText.setString("TRY AGAIN");
	tryAgainButtonText.setCharacterSize(16);
	tryAgainButtonText.setFillColor(sf::Color::White);
	tryAgainButtonText.setOrigin(tryAgainButtonText.getLocalBounds().width / 2, tryAgainButtonText.getLocalBounds().height / 2);

	tryAgainButton.setSize({ 200.f, 50.f });
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

void Menu::gameOverCheck()
{
}

void Menu::mainMenuUpdate()
{
	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	title.setPosition(view.getCenter().x / 2, view.getCenter().y / 2 - 200);

	playButtonText.setPosition(view.getCenter().x / 2, view.getCenter().y / 2);
	exitButtonText.setPosition(view.getCenter().x / 2, view.getCenter().y / 2 + 100);

	playButton.setPosition(view.getCenter().x / 2, view.getCenter().y / 2);
	exitButton.setPosition(view.getCenter().x / 2, view.getCenter().y / 2 + 100);

	if (playButton.getGlobalBounds().contains(screenPos))
	{
		playButtonText.setScale(1.5f, 1.5f);
		playButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			states = PLAY;
	}
	else
	{
		playButtonText.setScale(1.f, 1.f);
		playButton.setScale(1.f, 1.f);
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
	window->draw(exitButtonText);
	window->draw(playButton);
	window->draw(exitButton);

	window->display();
}

void Menu::pauseMenuUpdate()
{
	resumeButtonText.setPosition(view.getCenter().x - 150, view.getCenter().y);
	mainMenuButtonText.setPosition(view.getCenter().x + 150, view.getCenter().y);

	resumeButton.setPosition(view.getCenter().x - 150, view.getCenter().y);
	mainMenuButton.setPosition(view.getCenter().x + 150, view.getCenter().y);

	pauseMenuBackground.setPosition(view.getCenter());

	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	if (resumeButton.getGlobalBounds().contains(screenPos))
	{
		resumeButtonText.setScale(1.5f, 1.5f);
		resumeButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			states = PLAY;
			pausing = false;
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
			states = MENU;
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

void Menu::gameOverUpdate()
{
	tryAgainButtonText.setPosition(view.getCenter().x - 150, view.getCenter().y);
	mainMenuButtonText.setPosition(view.getCenter().x + 150, view.getCenter().y);

	tryAgainButton.setPosition(view.getCenter().x - 150, view.getCenter().y);
	mainMenuButton.setPosition(view.getCenter().x + 150, view.getCenter().y);

	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	if (tryAgainButton.getGlobalBounds().contains(screenPos))
	{
		tryAgainButtonText.setScale(1.5f, 1.5f);
		tryAgainButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			states = PLAY;
		pausing = false;
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
			states = MENU;
	}
	else
	{
		mainMenuButtonText.setScale(1.f, 1.f);
		mainMenuButton.setScale(1.f, 1.f);
	}
}

void Menu::gameOverRender()
{
	this->window->setView(view);
	this->window->clear();
	
	this->window->draw(tryAgainButtonText);
	this->window->draw(tryAgainButton);
	this->window->draw(mainMenuButtonText);
	this->window->draw(mainMenuButton);

	this->window->display();
}
