#include "GameBoard.h"
#include "Pathfinding.h"

DijkstraPathfinding *trailBlazer;

GameBoard *gameBoard;

int main() {

	::gameBoard = new GameBoard(0);

	::trailBlazer = new DijkstraPathfinding(::gameBoardDimensions[0 + gameBoard->getMapID()] * gameBoardDimensions[1 + gameBoard->getMapID()]);

	::trailBlazer->setStartPoint(0, 6, ::gameBoard);
	::trailBlazer->setEndPoint(3, 3, ::gameBoard);

	::trailBlazer->FindShortPath(::gameBoard);
	
	::gameBoard->getRenderer()->Update(::gameBoard);

	delete ::gameBoard;
	::gameBoard = 0;

	delete ::trailBlazer;
	::trailBlazer = 0;

	system("pause");

	return 0;
	
}