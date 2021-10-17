#include "Game.h"
#include <time.h>

int main()
{
	srand(time(NULL));
	Game game;
	game.setting();
	while (game.running())
	{
		game.update();
		game.render();
	}
	return 0;
}