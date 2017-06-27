#include "GameBoard.h"
#include "GridRenderer.h"

GameBoard::GameBoard(const unsigned char _mapID) {

	this->mapID = _mapID;

	//checking if this board is a row
	if (gameBoardDimensions[0 + this->mapID] == 1) {

		this->isColumn = true;
		this->isRow = false;

	}

	//checking if this board is a column
	else if (gameBoardDimensions[1 + this->mapID] == 1) {

		this->isColumn = false;
		this->isRow = true;

	}

	else {

		this->isRow = this->isColumn = false;

	}

	this->BoardSizeInitialization();

	this->HelpNeighbours();

	this->textRenderer = new GridRenderer();

}

/**
convenience method for setting up the board
*/
void GameBoard::BoardSizeInitialization() {

	//getting the X and Y from the gameBoardDimensions array, evens are X's, odds are Y's
	this->squares.reserve(::gameBoardDimensions[0] * ::gameBoardDimensions[1]);

	for (unsigned short i = 0; i < ::gameBoardDimensions[0] * ::gameBoardDimensions[1]; ++i) {

		this->squares.push_back(new GridSquare());

	}

}

void GameBoard::AssignPositions() {

	//todo
	std::cout << "Assign positions needs to be implimented for proper position information \n";

}

void GameBoard::UnmarkSquares() {

	std::cout << "debug function unmark squares is being called\n";

	for (unsigned short i = 0; i < ::gameBoardDimensions[0 + this->mapID] * ::gameBoardDimensions[1 + this->mapID]; ++i) {

		this->squares[i]->myFlags.isMarked = false;

	}

}

void GameBoard::HelpNeighbours() {

	/*******************************************
	********************************************
	*************CORNERS & SIDES****************
	********************************************
	*******************************************/
	for (unsigned char i = 0; i < ::gameBoardDimensions[0 + this->mapID] * ::gameBoardDimensions[1 + this->mapID]; ++i) {

		//std::cout << (int)i << '\n';

		//along the north side of the grid
		if (i < ::gameBoardDimensions[0 + this->mapID]) {

			//everyone here is a wall
			this->squares[i]->myFlags.isWall = true;

			//everyone here has no neighbour to the north
			this->squares[i]->neighbours[0] = 0;

			if (this->isColumn) {

				this->squares[i]->neighbours[1] = 0;
				this->squares[i]->neighbours[3] = 0;

			}

			else if (this->isRow) {

				this->squares[i]->neighbours[2] = 0;

			}

			if (!this->isRow) {

				this->squares[i]->neighbours[2] = this->squares[i + ::gameBoardDimensions[0 + this->mapID]];

			}

			///worthless
			else if (!this->isColumn) {

				///cheap fix to make it so that row grids have a functioning left-most tile
				if (i)
					this->squares[i]->neighbours[3] = this->squares[i - ::gameBoardDimensions[1 + this->mapID]];

			}

			//testing for the north eastern corner
			if (i % ::gameBoardDimensions[0 + this->mapID] == ::gameBoardDimensions[0 + this->mapID] - 1) {

				//no neighbour east
				this->squares[i]->neighbours[1] = 0;

			}

			//testing for north western corner
			else if (i % ::gameBoardDimensions[0 + this->mapID] == 0) {

				//no neighbours north or west
				this->squares[i]->neighbours[3] = 0;
				//neighbours south and east
				this->squares[i]->neighbours[1] = this->squares[i + 1];

			}

			//this square is along the northern wall but not at a corner
			else {

				this->squares[i]->neighbours[1] = this->squares[i + 1];
				this->squares[i]->neighbours[3] = this->squares[i - 1];

			}

		}

		//along the south side of the grid
		else if (i >= ::gameBoardDimensions[0 + this->mapID] * (::gameBoardDimensions[1 + this->mapID] - 1)) {

			//everyone here is a wall
			this->squares[i]->myFlags.isWall = true;

			//everyone here has no neighbour to the south
			this->squares[i]->neighbours[2] = 0;

			///debug
			if (!this->isRow) {

				this->squares[i]->neighbours[0] = this->squares[i - ::gameBoardDimensions[0 + this->mapID]];

			}

			//south eastern corner
			if (i % ::gameBoardDimensions[0 + this->mapID] == ::gameBoardDimensions[0 + this->mapID] - 1) {

				//no neighbours east or south
				this->squares[i]->neighbours[1] = 0;

				//neighbours north and west
				this->squares[i]->neighbours[3] = this->squares[i - 1];

			}

			//south western corner
			else if (i % ::gameBoardDimensions[0 + this->mapID] == 0) {

				//no neighbours south or west
				this->squares[i]->neighbours[3] = 0;

				//neighbours north and east
				this->squares[i]->neighbours[1] = this->squares[i + 1];

			}

			//this square is along the southern wall but not on a corner
			else {

				this->squares[i]->neighbours[1] = this->squares[i + 1];
				this->squares[i]->neighbours[3] = this->squares[i - 1];

			}

		}

		//along the east side of the grid
		else if (i % ::gameBoardDimensions[0 + this->mapID] == ::gameBoardDimensions[0 + this->mapID] - 1) {

			this->squares[i]->myFlags.isWall = true;

			//no neighbour east
			this->squares[i]->neighbours[1] = 0;

			if (!this->isRow) {

				this->squares[i]->neighbours[0] = this->squares[i - ::gameBoardDimensions[0 + this->mapID]];
				this->squares[i]->neighbours[2] = this->squares[i + ::gameBoardDimensions[0 + this->mapID]];

			}

			else {

				this->squares[i]->neighbours[0] = 0;
				this->squares[i]->neighbours[2] = 0;

			}

			this->squares[i]->neighbours[3] = this->squares[i - 1];

		}

		//along west wall
		else if (i % ::gameBoardDimensions[0 + this->mapID] == 0) {

			this->squares[i]->myFlags.isWall = true;

			//no neighbour west
			this->squares[i]->neighbours[3] = 0;

			if (!this->isRow) {

				this->squares[i]->neighbours[0] = this->squares[i - ::gameBoardDimensions[0 + this->mapID]];
				this->squares[i]->neighbours[2] = this->squares[i + ::gameBoardDimensions[0 + this->mapID]];

			}

			else {

				this->squares[i]->neighbours[0] = 0;
				this->squares[i]->neighbours[2] = 0;

			}

			this->squares[i]->neighbours[1] = this->squares[i + 1];

		}

		//everyone else has a neighbour in each compass direction NESW
		else {

			this->squares[i]->neighbours[0] = this->squares[i - ::gameBoardDimensions[0 + this->mapID]];
			this->squares[i]->neighbours[1] = this->squares[i + 1];
			this->squares[i]->neighbours[2] = this->squares[i + ::gameBoardDimensions[0 + this->mapID]];
			this->squares[i]->neighbours[3] = this->squares[i - 1];

		}

	}

}

/**

*/
GameBoard::~GameBoard() {

	if (this->textRenderer) {

		delete this->textRenderer;
		this->textRenderer = 0;

	}

	std::vector<GridSquare*>::iterator T_Igor;

	int T_I = GameBoard::squares.size();

	//for(it=tckts.begin();it!=tckts.end();it++)
	for (T_Igor = this->squares.begin(); T_Igor != this->squares.end(); T_Igor++) {

		delete *T_Igor;

	}

}


/*************************************************************************
**************************************************************************
**************************************************************************
*************************GRIDRENDERER.CPP*********************************
**************************************************************************
**************************************************************************
*************************************************************************/

GridRenderer::GridRenderer() {



}

GridRenderer::~GridRenderer() {



}

void GridRenderer::Render(GameBoard* const _board) {

	//this for loop hits every square in the grid
	for (unsigned char i = 0; i < ::gameBoardDimensions[0 + _board->mapID] * ::gameBoardDimensions[1 + _board->mapID]; ++i) {

		//start, regardless of terrain
		if (_board->squares[i]->getIsStart()) std::cout << 'E';

		//end, regardless of terrain
		else if (_board->squares[i]->getIsEnd()) std::cout << 'S';

		//X marks the spot
		else if (_board->squares[i]->getIsOnPath()) std::cout << 'X';

		//M for marked
		//else if (_board->squares[i]->GetIsMarked()) std::cout << "M";

		//0 is nothing special, should never be seen
		else std::cout << 'O';

		//this works for any size of grid
		if ((i + 1) % (::gameBoardDimensions[0 + _board->mapID]) == 0) std::cout << '\n';

	}

}

void GridRenderer::Update(GameBoard* const _board) {

	this->Render(_board);

}