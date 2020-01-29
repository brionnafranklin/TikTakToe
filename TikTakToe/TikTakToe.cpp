#include "pch.h"
#include <iostream>
#include "Game.h"

//main function; Starts when the program runs
void main()
{
	//creates an instance of the game class
	Game game;

	//sets game.startup equal to false after it runs once
	if(game.startup() == false)
		return;

	//game loop
	while (!game.isGameOver())
	{
		//redraws the board before the start of every turn
		game.draw();
		//starts a new turn
		game.update();
	} //end game loop

	//outputs information to the player on how to close the program
	std::cout << std::endl << INDENT << "Press 'Enter' to exit the program." << std::endl;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
}