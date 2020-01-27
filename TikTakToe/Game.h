#pragma once
class Game
{
public:
	Game();
	~Game();

	void draw();
	void update();

private: 
	void intializeBoard();
	void drawBoard();
};

