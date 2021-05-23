#include"Game.h"
#include"Definitions.h"

int main()
{
	_engine::Game game(SCREEN_WIDTH, SCREEN_HEIGHT, "SFML starter");
	
	while (game.IsRunning())
	{
		//Uptade
		game.Update();

		//Render
		game.Render();
	}
	
	return EXIT_SUCCESS;
}
