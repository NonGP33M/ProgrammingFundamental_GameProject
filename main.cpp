#include "Game.h"

int main()
{
	Game game;
	game.setting();
	while (game.running())
	{
		game.update();
		game.render();
	}
	return 0;
}