#pragma once

#include "Piece.h"

class PieceSensor
{
public:
	// Gets the type of piece at a specific location on the board
	// Returns Piece::INVALID if there is no piece at that location
	// NOTE: The point (0,0) is at the top left of the board, with the positive x-axis 
	//       going right and the positive y-axis going down
	PieceId GetPieceAt( int x, int y );
};