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

	bool isGameOver();

	bool getInput(int player);
	bool getPlayerNum();

	bool playerNumController();

	bool checkForWin();
	bool checkForTie();

private: 
	void initializeBoard();
	void drawBoard();

	bool m_gameOver;
	const char* m_board[BOARD_HEIGHT][BOARD_WIDTH];
	//Space m_board[BOARD_HEIGHT][BOARD_WIDTH];

	bool m_playerNum; //0 = player 1 (false) // 1 = player 2 (true)
};

