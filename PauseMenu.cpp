#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow* window, sf::View& view)
{
	font.loadFromFile("Font/dogica.ttf");
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

	this->window = window;
	this->view = view;
}

void PauseMenu::update(int& state)
{
	resumeButtonText.setPosition(view.getCenter().x / 2, view.getCenter().y / 2);
	mainMenuButtonText.setPosition(view.getCenter().x / 2, view.getCenter().y / 2 - 100);
	pauseMenuBackground.setPosition(view.getCenter());
	resumeButton.setPosition(view.getCenter().x / 2, view.getCenter().y / 2);
	mainMenuButton.setPosition(view.getCenter().x / 2, view.getCenter().y / 2 - 100);

	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	if (resumeButton.getGlobalBounds().contains(screenPos))
	{
		resumeButtonText.setScale(1.5f, 1.5f);
		resumeButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			state = 1;
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
			state = 0;
	}
	else
	{
		mainMenuButtonText.setScale(1.f, 1.f);
		mainMenuButton.setScale(1.f, 1.f);
	}
}

void PauseMenu::render()
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
