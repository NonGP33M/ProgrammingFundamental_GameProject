#include "Menu.h"
#include <time.h>

int main()
{
	srand(time(NULL));
	sf::Vector2f ScreenSize = { 1440.f,900.f };
	sf::RenderWindow window(sf::VideoMode(ScreenSize.x, ScreenSize.y), "Game", sf::Style::Close);
	sf::View view(sf::Vector2f(0.0f, 0.0f), ScreenSize);
	sf::Event event;
	sf::Clock clock;
	window.setFramerateLimit(144.f);

	Game game(&window, view);
	Menu menu(&window, view);

	bool onScreen = true;
	while (window.isOpen())
	{
		float deltatime = clock.restart().asSeconds();
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
				menu.timeTicking(deltatime);
				game.gameReset();
				menu.mainMenuUpdate();
				menu.mainMenuRender();
			}
			if (state == NAME)
			{
				menu.timeTicking(deltatime);
				menu.nameUpdate(event);
				menu.mainMenuRenderComponent();
				menu.nameRender();
				if (menu.startCheck())
				{
					menu.started();
					game.gameReset();
				}
			}
			if (state == PLAY)
			{
				if (!game.gameOverCheck())
				{
					game.timeTicking(deltatime);
					game.update();
					menu.setScore(game.getScore());
					menu.pauseCheck();
					game.render();
				}
				else
				{
					menu.gameOver();
				}
			}
			if (state == PAUSE)
			{
				menu.timeTicking(deltatime);
				menu.pauseMenuUpdate();
				game.pauseRender();
				menu.pauseMenuRender();
			}

			if (state == LEADERBOARD)
			{
				menu.timeTicking(deltatime);
				menu.leaderBoardMenuUpdate();
				menu.leaderBoardMenuRender();

			}
			if (state == GAMEOVER)
			{
				menu.timeTicking(deltatime);
				menu.gameOverMenuUpdate();
				game.pauseRender();
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