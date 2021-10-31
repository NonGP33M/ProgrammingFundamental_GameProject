#include "Menu.h"
#include "Game.h"
#include "PauseMenu.h"
#include <time.h>

enum STATE {MENU,GAME,PAUSE,LEADERBOARD,EXIT};

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1920, 1020), "Game", sf::Style::Fullscreen);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1920, 1080));;
	window.setFramerateLimit(144.f);

	Game game(&window);
	Menu menu(&window, view);
	PauseMenu pausemenu(&window, view);
	Player player;
	sf::Event event;
	int state = MENU;

	while (window.isOpen())
	{
		if (state == 0)
		{
			menu.update(state);
			menu.render();
		}
		if (state == 1)
		{
			game.pause = false;
			game.update();
			game.render();
			if (game.pauseCheck())
				state = 2;
		}
		if (state == 2)
		{
			game.pause = true;
			pausemenu.update(state);
			pausemenu.render();
		}
		if (state == 4)
		{
			window.close();
		}

	}
	return 0;
}