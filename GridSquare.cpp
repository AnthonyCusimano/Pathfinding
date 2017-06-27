#include "GridSquare.h"

#include "GridSquare.h"


GridSquare::GridSquare() {

	this->position[0] = 0;
	this->position[1] = 0;
	this->myFlags.isMarked = false;
	this->myFlags.isOnPath = false;
	this->myFlags.isEnd = this->myFlags.isStart = false;

}

GridSquare::GridSquare(const unsigned char _AX, const unsigned char _AY, short _distance, int _priority) {

	this->position[0] = _AX;
	this->position[1] = _AY;

	this->myFlags.isMarked = false;
	this->myFlags.isOnPath = false;
	this->myFlags.isEnd = this->myFlags.isStart = false;

}

GridSquare::GridSquare(bool const _isMarked) {

	this->myFlags.isMarked = _isMarked;
	this->position[0] = 0;
	this->position[1] = 0;

}

void GridSquare::SetUpNeighbour(const unsigned char _ID, GridSquare *_Neighbour) {

	this->neighbours[_ID] = _Neighbour;

}

void GridSquare::MarkMyNeighbours() {

	std::cout << "Debug function GridSquare::MarkMyNeighbours is being called\n";

}


GridSquare::~GridSquare() {

	for (unsigned char i = 0; i < 4; ++i) {

		if (this->neighbours[i]) {

			this->neighbours[i] = 0;

		}

	}

	this->bestNeighbour = 0;

}