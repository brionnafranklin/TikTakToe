#include "pch.h"
#include <iostream>
#include "Game.h"

void main()
{
	Game game;

	if(game.startup() == false)
		return;

	//game loop
	while (!game.isGameOver())
	{
		game.draw();
		game.update();
	} //end game loop

	std::cout << std::endl << INDENT << "Press 'Enter' to exit the program." << std::endl;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
}