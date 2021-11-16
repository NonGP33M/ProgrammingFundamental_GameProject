#include "Menu.h"
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
				game.gameReset();
				menu.mainMenuUpdate();
				menu.mainMenuRender();
			}
			if (state == PLAY)
			{
				if (!game.gameOverCheck())
				{
					game.update();
					menu.pauseCheck();
					game.render();
				}
				else
					menu.gameOver();
			}
			if (state == PAUSE)
			{
				menu.pauseMenuUpdate();
				menu.pauseMenuRender();
			}

			if (state == LEADERBOARD)
			{
				menu.leaderBoardMenuUpdate();
				menu.leaderBoardMenuRender();
				
			}
			if (state == GAMEOVER)
			{
				menu.gameOverMenuUpdate();
				menu.gameOverMenuRender();
				if (menu.tryAgainCheck())
				{
					game.gameReset();
					menu.tryAgainClickSetToFalse();
					menu.tryAgain();
				}
			}
		}
	}
	return 0;
}