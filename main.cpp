#include "Menu.h"
#include "Game.h"
#include <time.h>

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1440, 900), "Game", sf::Style::Close);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1440, 900));;
	sf::Event event;
	window.setFramerateLimit(144.f);

	Game game(&window, view);
	Menu menu(&window, view);
	Player player;
	
	bool onScreen = true;
	while (window.isOpen())
	{
		int state = menu.getStates();
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::GainedFocus:
				onScreen = true;
				break;

			case sf::Event::LostFocus:
				onScreen = false;
				break;
			}
		}

		if (onScreen)
		{
			if (state == MENU)
			{
				menu.mainMenuUpdate();
				menu.mainMenuRender();
			}
			if (state == 1)
			{
				game.update();
				menu.pauseCheck();
				game.render();
			}
			if (state == 2)
			{
				menu.pauseMenuUpdate();
				menu.pauseMenuRender();
			}
			if (state == 4)
			{
				window.close();
			}
		}
	}
	return 0;
}