#pragma once

#include "ChessPiece.h"
#include <iostream>

using namespace std;

class ChessBoard {
	protected:
		ChessPiece* myBoard[H + 1][8 + 1] = { nullptr };
	public:
		ChessBoard();
		void printBoard();
};

