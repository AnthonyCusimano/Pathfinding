#include "Pathfinding.h"

DijkstraPathfinding::DijkstraPathfinding(unsigned short const _squareCount) {

	this->startPoint = 0;
	this->endPoint = 0;

	this->squareCount = _squareCount;

}

DijkstraPathfinding::DijkstraPathfinding(GridSquare* const _startPoint, GridSquare* const _endPoint, unsigned short const _squareCount) {

	this->startPoint = _startPoint;
	this->endPoint = _endPoint;

	this->squareCount = _squareCount;

}

DijkstraPathfinding::~DijkstraPathfinding() {

	while (!DijkstraPoints.empty()) {

		DijkstraPoints.pop();

	}

	this->endPoint = this->startPoint = 0;

}void DijkstraPathfinding::FindShortPath(GameBoard* const _board) {

	std::cout << "we're finding a short path\n";

	//good place to start is adding the start point
	this->DijkstraPoints.push(this->startPoint);

	//start always on path
	this->startPoint->myFlags.isOnPath = true;


	while (!this->DijkstraPoints.empty()) {

		//once for each potential neighbour for each square
		for (unsigned char j = 0; j < 4; ++j) {

			//checking that the neighbour exists, and hasn't been passed over yet, AND that it isn't the end of the grid
			if (this->DijkstraPoints.front()->GetNeighbourAtAddress(j) && !this->DijkstraPoints.front()->GetNeighbourAtAddress(j)->myFlags.isMarked && this->DijkstraPoints.front() != this->endPoint) {

				this->DijkstraPoints.push(this->DijkstraPoints.front()->neighbours[j]);
				this->DijkstraPoints.front()->neighbours[j]->bestNeighbour = this->DijkstraPoints.front();
				this->DijkstraPoints.front()->neighbours[j]->myFlags.isMarked = true;

			}

			//when we reach the end of the grid, continue
			else if (this->DijkstraPoints.front()->myFlags.isEnd) {

				//start by marking the end point of the grid in the final queue
				this->DijkstraShortPath.push(this->DijkstraPoints.front());

				//do this until we hit the start
				while (this->DijkstraShortPath.front() != this->startPoint && this->DijkstraShortPath.empty() == false) {

					//we now know the most efficiant neighbour of each square we passed through
					this->DijkstraShortPath.push(this->DijkstraShortPath.front()->bestNeighbour);
					//make sure the AI knows this is on the path
					this->DijkstraShortPath.front()->myFlags.isOnPath = true;

					this->DijkstraShortPath.pop();

				}

			}

		}

		//fin
		this->DijkstraPoints.pop();

	}

}

void DijkstraPathfinding::ResetFlags() {

	std::cout << "unimplimented method Pathfinding::ResetFlags is being called\n";

}