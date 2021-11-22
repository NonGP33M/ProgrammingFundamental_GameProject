#include "Menu.h"
#include <time.h>

int main()
{
	srand(time(NULL));
	sf::Vector2f ScreenSize = { 1440.f,900.f };
	sf::RenderWindow window(sf::VideoMode(ScreenSize.x, ScreenSize.y), "MOOYIMM", sf::Style::Close);
	sf::View view(sf::Vector2f(0.0f, 0.0f), ScreenSize);
	sf::Event event;
	sf::Clock clock;
	std::vector<sf::Event> keyInput;
	sf::Image icon;
	window.setFramerateLimit(144.f);
	icon.loadFromFile("Texture/Icon/Icon.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	Game game(&window, view);
	Menu menu(&window, view);

	bool onScreen = true;
	while (window.isOpen())
	{
		keyInput.clear();
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
			case sf::Event::TextEntered:
				keyInput.push_back(event);
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
				menu.nameUpdate(keyInput);
				menu.mainMenuRenderComponent();
				menu.nameRender();
				if (menu.startCheck())
				{
					game.gameReset();
					menu.started();
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