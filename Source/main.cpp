#include "Game.hpp"

//todo: change field'Size' into numOfCell'Size'
//		change in calculation win'Size' into field'Size'

int main()
{
	Settings settings;
	Game game(settings);
	game.run();

	return 0;
}