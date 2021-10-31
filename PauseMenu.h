#pragma once
#include <SFML/Graphics.hpp>
class PauseMenu
{
private:
	sf::RenderWindow* window;
	sf::View view;
	sf::Font font;
	sf::Text resumeButtonText;
	sf::Text mainMenuButtonText;
	sf::RectangleShape pauseMenuBackground;
	sf::RectangleShape resumeButton;
	sf::RectangleShape mainMenuButton;
public:
	PauseMenu(sf::RenderWindow* window, sf::View& view);
	void update(int& state);
	void render();
};

