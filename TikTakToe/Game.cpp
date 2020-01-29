#include "pch.h"
#include "Game.h"
#include <iostream>

Game::Game() : m_gameOver{ false }, m_playerNum{ false }
{
}

Game::~Game()
{
}

bool Game::startup()
{
	initializeBoard();

	return true;
}

void Game::draw()
{
	system("cls");
	drawBoard();
}

void Game::update()
{
	playerNumController();
	system("pause");
}

void Game::initializeBoard()
{
	// set space positions
	for (int y = 0; y < BOARD_HEIGHT; y++) 
	{
		for (int x = 0; x < BOARD_WIDTH; x++) 
		{
			m_board[y][x] = EMPTY_TILE;
			//m_board[y][x].setPosition(Point2D{ x, y });
		}
	}
}

void Game::drawBoard()
{
	std::cout << std::endl;
	std::cout << std::endl;
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		std::cout << INDENT;
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			std::cout << m_board[y][x];
			//m_board[y][x].draw();
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool Game::isGameOver()
{
	return m_gameOver;
}

bool Game::getInput(int player)
{
	int input = 0;

	std::cout << INDENT << "player : " << player + 1 << " Please select a space using the number pad:" << INDENT;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cin >> input;

	while (input)
	{
		int x;
		int y;

		if (input == 7)
		{
			x = 0;
			y = 0;
		}
		else if (input == 8)
		{
			x = 1;
			y = 0;
		}
		else if (input == 9)
		{
			x = 2;
			y = 0;
		}
		else if (input == 4)
		{
			x = 0;
			y = 1;
		}
		else if (input == 5)
		{
			x = 1;
			y = 1;
		}
		else if (input == 6)
		{
			x = 2;
			y = 1;
		}
		else if (input == 1)
		{
			x = 0;
			y = 2;
		}
		else if (input == 2)
		{
			x = 1;
			y = 2;
		}
		else if (input == 3)
		{
			x = 2;
			y = 2;
		}
		else 
		{ 
			std::cout << INDENT << "You try, but you just can't do it." << std::endl;
			return false;
		}

		if (m_board[y][x] == EMPTY_TILE)
		{
			if (player)
			{
				m_board[y][x] = PLAYER2_TILE;
			}
			else
			{
				m_board[y][x] = PLAYER1_TILE;
			}

			if (checkForWin())
			{
				draw();
				std::cout << INDENT << "Player : " << player + 1 << " wins!" << INDENT;
				m_gameOver = true;
			}

			if (checkForTie())
			{
				draw();
				std::cout << INDENT << "Congratulations! You both loose!" << INDENT;
				m_gameOver = true;
			}

			return true;
		}
		else
		{
			std::cout << INDENT << "You try, but you just can't do it." << std::endl;
			return false;
		}
	}
}

bool Game::getPlayerNum()
{
	return m_playerNum;
}

bool Game::playerNumController()
{
	if (getInput(m_playerNum))
	{
		return m_playerNum = !m_playerNum;
	}
	else
	{
		return m_playerNum;
	}
}

bool Game::checkForWin()
{
	// 7, 4, 1
	if (m_board[0][0] == m_board[1][0] && m_board[0][0] == m_board[2][0] && m_board[0][0] != EMPTY_TILE)
	{
		return true;
	}
	// 8, 5, 2
	if (m_board[0][1] == m_board[1][1] && m_board[0][1] == m_board[2][1] && m_board[0][1] != EMPTY_TILE)
	{
		return true;
	}
	// 9, 6, 3
	if (m_board[0][2] == m_board[1][2] && m_board[0][2] == m_board[2][2] && m_board[0][2] != EMPTY_TILE)
	{
		return true;
	}
	// 7, 8, 9
	if (m_board[0][0] == m_board[0][1] && m_board[0][0] == m_board[0][2] && m_board[0][0] != EMPTY_TILE)
	{
		return true;
	}
	//4, 5, 6
	if (m_board[1][0] == m_board[1][1] && m_board[1][0] == m_board[1][2] && m_board[1][0] != EMPTY_TILE)
	{
		return true;
	}
	// 1, 2, 3
	if (m_board[2][0] == m_board[2][1] && m_board[2][0] == m_board[2][2] && m_board[2][0] != EMPTY_TILE)
	{
		return true;
	}
	// 7, 5, 3
	if (m_board[0][0] == m_board[1][1] && m_board[0][0] == m_board[2][2] && m_board[0][0] != EMPTY_TILE)
	{
		return true;
	}
	// 9, 5, 1
	if (m_board[0][2] == m_board[1][1] && m_board[0][2] == m_board[2][0] && m_board[0][2] != EMPTY_TILE)
	{
		return true;
	}
	return false;
}

bool Game::checkForTie()
{
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			if (m_board[y][x] == EMPTY_TILE)
			{
				return false;
			}
		}
	}
	return true;
}
