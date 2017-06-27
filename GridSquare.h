#ifndef GRID_SQUARE_H
#define GRID_SQUARE_H

///remove me
#include <iostream>

struct SquareFlags {

	//used to help the pathfinding algorithm mark this square as being on the path, or if it's the start, or if it's the end
	///potentially depricated
	bool isEnd, isStart;
	//ismarked potentially depricated, isOnPath for when the end has been found, isClosed to mark a square that cannot be on the path
	bool isMarked, isOnPath;
	///potentially depricated, atm the pathfinder only checks if the neighbour at the relevent address is null or not
	//used to help pathfinding AI by telling it that this square is on the end of one side of the grid
	bool isWall;


};


const unsigned char gameBoardDimensions[2] = { 6, 7 };

class GridSquare {

	friend class GameBoard;
	friend class DijkstraPathfinding;

public:

	/*************************************************************************
	**************************************************************************
	**************************************************************************
	**********************CONSTRUCTORS & DESTRUCTOR***************************
	**************************************************************************
	**************************************************************************
	*************************************************************************/

	/**
	default constructor, initializes position to 0,0 and is unmarked
	*/
	GridSquare();


	/**
	additional copy constructor
	*/
	GridSquare(const unsigned char _AX, const unsigned char _AY, const short _distance, const int _priority);

	/**
	constructor which sets position to 0,0 and the isMarked flag to _isMarked
	We're moving away from a need for _isMarked so this could soon be depricated
	*/
	GridSquare(bool const _isMarked);

	/**
	constructor which copies the position, and isMakred flag on the passed GridSquare
	*/
	//GridSquare(GridSquare const *_AS);

	/**
	destructor
	*/
	~GridSquare();

	/*************************************************************************
	**************************************************************************
	**************************************************************************
	*******************************ACCESS*************************************
	**************************************************************************
	**************************************************************************
	*************************************************************************/

	/**
	returns the x factor of the position of this square
	*/
	const unsigned char GetX() const {

		return this->position[0];

	}

	/**
	returns the y factor of the position of this square
	*/
	const unsigned char GetY() const {

		return this->position[1];

	}

	/**
	returns the flag for if this square is marked or not
	*/
	const bool GetIsMarked() const {

		return this->myFlags.isMarked;

	}

	/**
	method used to mark or unmark squares dynamically
	*/
	void SetIsMarked(bool const _mark) {


		this->myFlags.isMarked = _mark;

	}

	/**
	helper method for pathfinding algorithm
	returns true only if this square is on the path
	*/
	const bool getIsOnPath() const {

		return this->myFlags.isOnPath;

	}

	/**
	returns true
	*/
	const bool getIsWall() const {

		return this->myFlags.isWall;

	}

	/**
	returns true only if this square is on the wall of the grid
	*/
	const bool getIsEnd() const {

		return this->myFlags.isEnd;

	}

	/**
	helper method for pathfinding algorithm
	returns true only if this square is the start point
	*/
	const bool getIsStart() const {

		return this->myFlags.isStart;

	}

	/*************************************************************************
	**************************************************************************
	**************************************************************************
	******************************NEIGHBOUR***********************************
	**************************************************************************
	**************************************************************************
	*************************************************************************/

	/**
	gets a particular neighbour
	*/
	const GridSquare* GetNeighbourAtAddress(const unsigned char _ID) {

		//if someone sends something stupid
		if (_ID > 3) return this->neighbours[3];

		else return this->neighbours[_ID];

	}

	/**
	method to assign a square pointer to be one of the neighbours of this square
	done in NESW order
	*/
	void SetUpNeighbour(const unsigned char _ID, GridSquare *_Neighbour);


	/**
	Method which marks all the neighbours of this square
	*/
	void MarkMyNeighbours();

	private:

	//wrapper for flags pretaining to this square
	SquareFlags myFlags;

	//used to help pathfinding do what it needs to do
	GridSquare* bestNeighbour;
	GridSquare* neighbours[4];

	//X, Y factors (Repsectively) of this square's position within a grid
	unsigned char position[2];

};
#endif
