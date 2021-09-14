#pragma once

#include "ChessPiece.h"
#include <iostream>
#include <map>

using namespace std;

class ChessBoard {
	protected:
		map < COORDINATE, ChessPiece* > myBoard;
		ChessPiece* selectedPiece = nullptr;
	public:
		ChessBoard();
		void printBoard();
		bool movePiece(ChessPiece* piece, COORDINATE newCoordinate);
		ChessPiece* selectPiece(COORDINATE coordinate, COLOUR colour);
		void unselectPiece();
};