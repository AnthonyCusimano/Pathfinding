#ifndef _PATH_FINDING_H_
#define _PATH_FINDING_H_

#include <queue>

#include "GameBoard.h"

class DijkstraPathfinding {

public:


	/**
	initializes the algorithm object without assigning values to startSquare and endSquare
	*/
	DijkstraPathfinding(unsigned short const _squareCount);

	/**
	initializes the algorithm object while assigning a value to startSquare and endSquare
	*/
	DijkstraPathfinding(GridSquare* const _startSquare, GridSquare* const _endSquare, unsigned short const _squareCount);


	/**
	This destructor is responsable for destroying possible points and setting startPoint and endPoint to null (but not deleting them)
	*/
	~DijkstraPathfinding();

	/*************************************************************************
	**************************************************************************
	**************************************************************************
	***************************PATHFINDING************************************
	**************************************************************************
	**************************************************************************
	*************************************************************************/

	/**
	method to find the shortest path between two squares
	*/
	void FindShortPath(GameBoard* const _board);

	/**
	unimplimented method meant to reset pathfinding flags
	*/
	void ResetFlags();

	/*************************************************************************
	**************************************************************************
	**************************************************************************
	*******************************ACCESS*************************************
	**************************************************************************
	**************************************************************************
	*************************************************************************/

	//
	//start point access
	//

	/**
	method to set both dimensions of the start point's position within the grid
	*/
	void setStartPoint(GridSquare* const _AV) {

		this->startPoint = _AV;
		this->startPoint->myFlags.isStart = true;

	}

	/**
	method overload to set the start point of the grid without direct access to the gameboard's private attributes
	this method must be tested
	*/
	void setStartPoint(const unsigned char _x, const unsigned char _y, GameBoard const *_board) {

		this->startPoint = _board->squares[_x + (_y * (::gameBoardDimensions[0 + _board->mapID]))];
		this->startPoint->myFlags.isStart = true;

	}

	/**
	return's the X value of the start point position within the grid
	*/
	const char getStartPositionX()const {

		return this->startPoint->GetX();

	}

	/**
	return's the Y value of the start point position within the grid
	*/
	const char getStartPositionY()const {

		return this->startPoint->GetY();

	}

	/**
	returns a pointer to this algorith's startPoint
	*/
	const GridSquare* getStartPoint() const {

		return this->startPoint;

	}

	//
	//end point access
	//

	/**
	method to set both dimensions of the start point's position within the grid
	*/
	void setEndPoint(GridSquare* const _AV) {

		this->endPoint = _AV;
		this->endPoint->myFlags.isEnd = true;

	}

	/**
	method overload to set the end point of the grid without direct access to the gameboard's private attributes
	this method must be tested, subtracting 1 for array notation may be incorrect
	*/
	void setEndPoint(const unsigned char _x, const unsigned char _y, GameBoard const *_board) {

		this->endPoint = _board->squares[_x + (_y * (::gameBoardDimensions[0 + _board->mapID]))];
		this->endPoint->myFlags.isEnd = true;

	}

	/**
	return's the X value of the end point position within the grid
	*/
	const char getEndPositionX()const {

		return this->endPoint->GetX();

	}

	/**
	return's the X value of the end point position within the grid
	*/
	const char getEndPositionY()const {

		return this->endPoint->GetY();

	}


private:

	//convenience pointers for the pathfinder
	GridSquare *startPoint, *endPoint;

	//current points being evaluated, and the best path found so far
	std::queue<GridSquare*> DijkstraPoints;
	std::queue<GridSquare*> DijkstraShortPath;

	//number of squares in the grid
	unsigned short squareCount;

};

#endif