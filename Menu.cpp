#include "Menu.h"

Menu::Menu(sf::RenderWindow* window, sf::View view)
{
	font.loadFromFile("Font/dogica.ttf");
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

	this->window = window;
	this->view = view;
}

void Menu::update(int& state)
{
	sf::Vector2i gamePos = sf::Mouse::getPosition(*window);
	sf::Vector2f screenPos = window->mapPixelToCoords(gamePos);

	playButtonText.setPosition(view.getCenter().x / 2, view.getCenter().y / 2);
	exitButtonText.setPosition(view.getCenter().x / 2, view.getCenter().y / 2 + 100);

	playButton.setPosition(view.getCenter().x / 2, view.getCenter().y / 2);
	exitButton.setPosition(view.getCenter().x / 2, view.getCenter().y / 2 + 100);

	if (playButton.getGlobalBounds().contains(screenPos))
	{
		playButtonText.setScale(1.5f, 1.5f);
		playButton.setScale(1.2f, 1.2f);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			state = 1;
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
			state = 4;
	}
	else
	{
		exitButtonText.setScale(1.f, 1.f);
		exitButton.setScale(1.f, 1.f);
	}
}

void Menu::render()
{
	window->setView(view);
	window->clear();
	
	window->draw(playButtonText);
	window->draw(exitButtonText);
	window->draw(playButton);
	window->draw(exitButton);

	window->display();
}
