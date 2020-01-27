#include "pch.h"
#include "Game.h"

Game::Game()
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
}

void Game::update()
{
}

void Game::initializeBoard()
{
	// set space positions
	for (int y = 0; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			m_board[y][x].setPosition(Point2D{ x, y });
		}
	}
}

void Game::drawBoard()
{
}
