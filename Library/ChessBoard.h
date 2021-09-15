#pragma once

#include "Enum.h"
#include "Structs.h"

#include <iostream>
#include <map>

using namespace std;

// Forward Declarations
class ChessPiece;

// Chess Board Class
class ChessBoard {
	protected:
		map < COORDINATE, ChessPiece* > myBoard;
		ChessPiece* selectedPiece = nullptr;
		BOOLBOARD* validMoves;
	public:
		ChessBoard();
		void printBoard();
		bool movePiece(ChessPiece* piece, COORDINATE newCoordinate);
		ChessPiece* getPiece(COORDINATE coordinate);
		ChessPiece* selectPiece(COORDINATE coordinate, COLOUR colour);
		void unselectPiece();
		void checkValidMoves();
		void resetValidMoves();
};