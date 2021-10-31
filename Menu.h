#pragma once
#include <SFML/Graphics.hpp>

class Menu
{
private:
	sf::Event event;
	sf::View view;
	sf::Font font;
	sf::Text playButtonText;
	sf::Text exitButtonText;
	sf::RenderWindow* window;
	sf::RectangleShape playButton;
	sf::RectangleShape exitButton;
public:
	Menu(sf::RenderWindow* window, sf::View view);
	void update(int& state);
	void render();
};

