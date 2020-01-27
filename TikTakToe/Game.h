#pragma once
#include "GameDefines.h"
#include "Space.h"
class Game
{
public:
	Game();
	~Game();

	bool startup();
	void draw();
	void update();

private: 
	void initializeBoard();
	void drawBoard();

	bool m_gameOver;
	Space m_board[BOARD_HEIGHT][BOARD_WIDTH];
};

