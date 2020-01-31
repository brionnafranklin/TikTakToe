#pragma once
#include "GameDefines.h"

//declares everything within the game class
class Game
{
//declares everything that is public in the game class
public:
	//declares the default constructer for game
	Game();
	//declares the default deconstructer for game
	~Game();

	//declares the startup bool
	bool startup();
	//declares the draw function
	void draw();
	//declares the update function
	void update();
	//declares the isGameOver bool
	bool isGameOver();
	//declares the getInput bool
	bool getInput(int player);
	//declares the playerNumController bool
	bool playerNumController();
	//declares the checkForWin bool
	bool checkForWin();
	//declares the checkForTie bool
	bool checkForTie();

//declares everything that is private in the game class
private: 
	//declares the initializeBoard function
	void initializeBoard();
	//declares the drawBoard function
	void drawBoard();
	//declares the m_gameOver bool
	bool m_gameOver;
	//declares m_board (the variable used for the board) as a constant character
	const char* m_board[BOARD_HEIGHT][BOARD_WIDTH];
	//declares the m_playerNum bool
	bool m_playerNum; //0 = player 1 (false) // 1 = player 2 (true)
};

