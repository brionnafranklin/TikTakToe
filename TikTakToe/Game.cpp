#include "pch.h"
#include "Game.h"
#include <iostream>

//default constructer for game
Game::Game() : m_gameOver{ false }, m_playerNum{ false }
{
}

//default deconstructer for game
Game::~Game()
{
}

//runs once when the game starts
bool Game::startup()
{
	//draws the board with only empty tiles
	initializeBoard();
	//returns true to show that the board has been drawn the first time
	return true;
}

//clears the outdated board and replaces it with one with the correct tiles
void Game::draw()
{
	//clears board
	system("cls");
	//redraws board
	drawBoard();
}

//starts a new turn and waits before updating
void Game::update()
{
	//starts a new turn
	playerNumController();
	//waits
	system("pause");
}

//draws the board the first time
void Game::initializeBoard()
{
	// set space positions
	//iterate through the y-axis
	for (int y = 0; y < BOARD_HEIGHT; y++) 
	{
		//iterate through the x-axis
		for (int x = 0; x < BOARD_WIDTH; x++) 
		{
			//set each space to empty
			m_board[y][x] = EMPTY_TILE;
		}
	}
}

//draws each tile of the board
void Game::drawBoard()
{
	//skip line
	std::cout << std::endl;
	//skip line
	std::cout << std::endl;
	//iterate through the y-axis
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		//skip line
		std::cout << INDENT;
		//iterate through the x-axis
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			//print the tile at coordinants on the board
			std::cout << m_board[y][x];
		}
		//skip line
		std::cout << std::endl;
	}
	//skip line
	std::cout << std::endl;
}

//returns the value of m_gameOver
bool Game::isGameOver()
{
	//returns true or false based on the value of m_gameOver;
	return m_gameOver;
}

//takes a player's input and places their tile in the coorisponding cooridinent. then determines if there is a winner or a tie after
bool Game::getInput(int player)
{
	//declares input as an int
	int input = 0;

	//asks for input from the player whomst turn it is
	std::cout << INDENT << "player : " << player + 1 << " Please select a space using the number pad:" << INDENT;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	//take in input
	std::cin >> input;

	//check for valid input
	if (input == 0)
	{
		//tell the user they did something wrong
		std::cout << INDENT << "You try, but you just can't do it." << std::endl;
		//return and restart turn
		return false;
	}

	//if input is valid
	while (input)
	{
		//declare x as an int
		int x;
		//declare y as an int
		int y;

		//if player selects position 7 
		if (input == 7)
		{
			//set x
			x = 0;
			//set y
			y = 0;
		}
		//if player selects position 8
		else if (input == 8)
		{
			//set x
			x = 1;
			//set y
			y = 0;
		}
		//if player selects position 9
		else if (input == 9)
		{
			//set x
			x = 2;
			//set y
			y = 0;
		}
		//if player selects position 4
		else if (input == 4)
		{
			//set x
			x = 0;
			//set y
			y = 1;
		}
		//if player selects position 5
		else if (input == 5)
		{
			//set x
			x = 1;
			//set y
			y = 1;
		}
		//if player selects position 6
		else if (input == 6)
		{
			//set x
			x = 2;
			//set y
			y = 1;
		}
		//if player selects position 1
		else if (input == 1)
		{
			//set x
			x = 0;
			//set y
			y = 2;
		}
		//if player selects position 2
		else if (input == 2)
		{
			//set x
			x = 1;
			//set y
			y = 2;
		}
		//if player selects position 3
		else if (input == 3)
		{
			//set x
			x = 2;
			//set y
			y = 2;
		}

		//make sure the space is empty
		if (m_board[y][x] == EMPTY_TILE)
		{
			//if player is 1 (true)
			if (player)
			{
				//set the position on the board to player 2's token
				m_board[y][x] = PLAYER2_TILE;
			}
			else
			{
				//set the position on the board to player 1's token
				m_board[y][x] = PLAYER1_TILE;
			}

			//if one of the players got 3 in a row after this turn
			if (checkForWin())
			{
				//redraw the board
				draw();
				//print winner message
				std::cout << INDENT << "Player : " << player + 1 << " wins!" << INDENT;
				//set game to be over
				m_gameOver = true;
			}

			//if there are no empty tiles left after this turn
			if (checkForTie())
			{
				//redraw the board
				draw();
				//print loosing message
				std::cout << INDENT << "Congratulations! You both loose!" << INDENT;
				//set game to be over
				m_gameOver = true;
			}

			//end turn
			return true;
		}
		else
		{
			//print a message letting the player know something went wrong
			std::cout << INDENT << "You try, but you just can't do it." << std::endl;
			//restart turn
			return false;
		}
	}
}

//changes which player's turn it is
bool Game::playerNumController()
{
	//if the turn ends successfully
	if (getInput(m_playerNum))
	{
		//make whatever playerNum equals (true/1 or false/0) the opisite
		return m_playerNum = !m_playerNum;
	}
	else
	{
		//failed turn results is restarting that player's turn
		return m_playerNum;
	}
}

//checks to see if a player has 3 connecting tokens
bool Game::checkForWin()
{
	//checks to see if the tiles in positions 7, 4, and 1 are equal and not empty
	if (m_board[0][0] == m_board[1][0] && m_board[0][0] == m_board[2][0] && m_board[0][0] != EMPTY_TILE)
	{
		//returns to show a player has won
		return true;
	}
	//checks to see if the tiles in positions 8, 5, and 2 are equal and not empty
	if (m_board[0][1] == m_board[1][1] && m_board[0][1] == m_board[2][1] && m_board[0][1] != EMPTY_TILE)
	{
		//returns to show a player has won
		return true;
	}
	//checks to see if the tiles in positions 9, 6, and 3 are equal and not empty
	if (m_board[0][2] == m_board[1][2] && m_board[0][2] == m_board[2][2] && m_board[0][2] != EMPTY_TILE)
	{
		//returns to show a player has won
		return true;
	}
	//checks to see if the tiles in positions 7, 8, and 9 are equal and not empty
	if (m_board[0][0] == m_board[0][1] && m_board[0][0] == m_board[0][2] && m_board[0][0] != EMPTY_TILE)
	{
		//returns to show a player has won
		return true;
	}
	//checks to see if the tiles in positions4, 5, and 6 are equal and not empty
	if (m_board[1][0] == m_board[1][1] && m_board[1][0] == m_board[1][2] && m_board[1][0] != EMPTY_TILE)
	{
		//returns to show a player has won
		return true;
	}
	//checks to see if the tiles in positions 1, 2, and 3 are equal and not empty
	if (m_board[2][0] == m_board[2][1] && m_board[2][0] == m_board[2][2] && m_board[2][0] != EMPTY_TILE)
	{
		//returns to show a player has won
		return true;
	}
	//checks to see if the tiles in positions 7, 5, and 3 are equal and not empty
	if (m_board[0][0] == m_board[1][1] && m_board[0][0] == m_board[2][2] && m_board[0][0] != EMPTY_TILE)
	{
		//returns to show a player has won
		return true;
	}
	//checks to see if the tiles in positions 9, 5, and 1 are equal and not empty
	if (m_board[0][2] == m_board[1][1] && m_board[0][2] == m_board[2][0] && m_board[0][2] != EMPTY_TILE)
	{
		//returns to show a player has won
		return true;
	}
	//returns to show a player has not won
	return false;
}

//checks to see if the game can continue or if the board is full
bool Game::checkForTie()
{
	//iterate through the y-axis
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		//iterate through the x-axis
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			//if any tile on the board is empty
			if (m_board[y][x] == EMPTY_TILE)
			{
				//the game continues
				return false;
			}
		}
	}
	//game ends in tie if no tiles are empty
	return true;
}
