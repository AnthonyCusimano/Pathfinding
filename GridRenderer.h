#ifndef GRID_RENDERER_H
#define GRID_RENDERER_H

#include <iostream>

class GameBoard;

//this class's definition is in GameBoard.cpp
class GridRenderer {

public:

	GridRenderer();
	~GridRenderer();

	/**
	Displays the gameBoard in text
	*/
	void Render(GameBoard* const _board);

	/**
	Currently only recalls the Render function of this object
	*/
	void Update(GameBoard* const _board);

private:



};

#endif
