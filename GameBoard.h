#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <vector>

//the demensions of each board in the game is defined in GridSquare.h
#include "GridSquare.h"
#include "GridRenderer.h"

class DijkstraPathfinding;

class GameBoard {

	friend class GridRenderer;
	friend class DijkstraPathfinding;

public:

	GameBoard(const unsigned char _mapID);
	~GameBoard();

	/**
	eventually this method should take the board's ID as an argument, or this should be given it's own class
	*/
	void BoardSizeInitialization();

	/**

	*/
	void UnmarkSquares();

	/**
	take the role of helper class to get the square's their neighbours set up
	*/
	void HelpNeighbours();

	/**
	returns the map ID of this map
	*/
	const unsigned char getMapID() const {

		return this->mapID;

	}
	/**
	assigns squares within the grid a proper position
	*/
	void AssignPositions();

	/**
	returns a pointer to the renderer of this grid
	*/
	GridRenderer* getRenderer()const {

		return this->textRenderer;
	}

	/**
	returns the square with the address of this->squares[_AV]
	*/
	const GridSquare* GetSquareAtAddress(unsigned short _AV) {

		return this->squares[_AV];

	}

private:


	bool isColumn, isRow;

	//the ID of the current map
	unsigned char mapID;
	//the squares that make up each gameboard
	std::vector<GridSquare*> squares;
	//the object in charge of rendering the grid
	GridRenderer *textRenderer;

};

#endif