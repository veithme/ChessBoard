#include "ChessPiece.h"
#include "ChessBoard.h"

ChessPiece::ChessPiece(COLOUR newColour, ALPHANUM newX, int newY) {
	myColour = newColour;
	myX = newX;
	myY = newY;
	myPieceType = PIECETYPE::NONE;
}

COLOUR ChessPiece::getColour() {
	return myColour;
}

PIECETYPE ChessPiece::getPieceType() {
	return myPieceType;
}

void ChessPiece::setCoordinate(COORDINATE newCoordinate) {
	myX = newCoordinate.X;
	myY = newCoordinate.Y;
}

COORDINATE ChessPiece::getCoordinate() {
	return { myX, myY };
}

// Pawn
Pawn::Pawn(COLOUR newColour, ALPHANUM newX, int newY) : ChessPiece(newColour, newX, newY) {
	myPieceType = PIECETYPE::PAWN;
}

char Pawn::getPieceChar() {
	return 'P';
}

void Pawn::getAvailableMoves(BOOLBOARD* board, ChessBoard* chessBoard) {
	// Pawn movement dependent on player
	switch (myColour) {
		case COLOUR::BLACK:
			if (myY > 1 && chessBoard->getPiece({ myX, myY - 1 }) == nullptr) {
				board->arr[myX][myY - 1] = true; // Can move forward 1 space
				if (myY == 7 && chessBoard->getPiece({ myX, myY - 2 }) == nullptr) {
					board->arr[myX][myY - 2] = true; // Can move forward 2 spaces
				}
			}
			if (myX > A && myY > 1 && chessBoard->getPiece({ ALPHANUM(myX - 1), myY - 1 }) != nullptr && chessBoard->getPiece({ ALPHANUM(myX - 1), myY - 1 })->getColour() != myColour) {
				board->arr[myX - 1][myY - 1] = true; // Can attack diagonal down-left
			}
			if (myX < H && myY > 1 && chessBoard->getPiece({ ALPHANUM(myX + 1), myY - 1 }) != nullptr && chessBoard->getPiece({ ALPHANUM(myX + 1), myY - 1 })->getColour() != myColour) {
				board->arr[myX + 1][myY - 1] = true; // Can attack diagonal down-right
			}
			break;
		case COLOUR::WHITE:
			if (myY < 8 && chessBoard->getPiece({ myX, myY + 1 }) == nullptr) {
				board->arr[myX][myY + 1] = true; // Can move forward 1 space
				if (myY == 2 && chessBoard->getPiece({ myX, myY + 2 }) == nullptr) {
					board->arr[myX][myY + 2] = true; // Can move forward 2 spaces
				}
			}
			if (myX > A && myY < 8 && chessBoard->getPiece({ ALPHANUM(myX - 1), myY + 1 }) != nullptr && chessBoard->getPiece({ ALPHANUM(myX - 1), myY + 1 })->getColour() != myColour) {
				board->arr[myX - 1][myY + 1] = true; // Can attack diagonal up-left
			}
			if (myX < H && myY < 8 && chessBoard->getPiece({ ALPHANUM(myX + 1), myY + 1 }) != nullptr && chessBoard->getPiece({ ALPHANUM(myX + 1), myY + 1 })->getColour() != myColour) {
				board->arr[myX + 1][myY + 1] = true; // Can attack diagonal up-right
			}
			break;
		}	
}

// Rook
Rook::Rook(COLOUR newColour, ALPHANUM newX, int newY) : ChessPiece(newColour, newX, newY) {
	myPieceType = PIECETYPE::ROOK;
}

char Rook::getPieceChar() {
	return 'R';
}

void Rook::getAvailableMoves(BOOLBOARD* board, ChessBoard* chessBoard) {
	// Loop in 4 straight direction

	// Check right direction
	for (int i = myX + 1; i <= H; i++) {
		if (chessBoard->getPiece({ ALPHANUM(i), myY }) == nullptr) {
			board->arr[i][myY] = true;
		}
		else if (chessBoard->getPiece({ ALPHANUM(i), myY })->getColour() != myColour) {
			board->arr[i][myY] = true;
			break;
		}
		else {
			break;
		}
	}
	// Check left direction
	for (int i = myX - 1; i >= A; i--) {
		if (chessBoard->getPiece({ ALPHANUM(i), myY }) == nullptr) {
			board->arr[i][myY] = true;
		}
		else if (chessBoard->getPiece({ ALPHANUM(i), myY })->getColour() != myColour) {
			board->arr[i][myY] = true;
			break;
		}
		else {
			break;
		}
	}
	// Check up direction
	for (int i = myY + 1; i <= 8; i++) {
		if (chessBoard->getPiece({ myX, i }) == nullptr) {
			board->arr[myX][i] = true;
		}
		else if (chessBoard->getPiece({ myX, i })->getColour() != myColour) {
			board->arr[myX][i] = true;
			break;
		}
		else {
			break;
		}
	}
	// Check down direction
	for (int i = myY - 1; i >= 1; i--) {
		if (chessBoard->getPiece({ myX, i }) == nullptr) {
			board->arr[myX][i] = true;
		}
		else if (chessBoard->getPiece({ myX, i })->getColour() != myColour) {
			board->arr[myX][i] = true;
			break;
		}
		else {
			break;
		}
	}
}

// Knight
Knight::Knight(COLOUR newColour, ALPHANUM newX, int newY) : ChessPiece(newColour, newX, newY) {
	myPieceType = PIECETYPE::KNIGHT;
}

char Knight::getPieceChar() {
	return 'k';
}

void Knight::getAvailableMoves(BOOLBOARD* board, ChessBoard* chessBoard) {
	// 8 Possible moves, check each individually
	if (myX > B && myY < 8 && (chessBoard->getPiece({ ALPHANUM(myX - 2), myY + 1 }) == nullptr || chessBoard->getPiece({ ALPHANUM(myX - 2), myY + 1 })->getColour() != myColour)) {
		board->arr[myX - 2][myY + 1] = true; 
	}
	if (myX > A && myY < 7 && (chessBoard->getPiece({ ALPHANUM(myX - 1), myY + 2 }) == nullptr || chessBoard->getPiece({ ALPHANUM(myX - 1), myY + 2 })->getColour() != myColour)) {
		board->arr[myX - 1][myY + 2] = true; 
	}
	if (myX < H && myY < 7 && (chessBoard->getPiece({ ALPHANUM(myX + 1), myY + 2 }) == nullptr || chessBoard->getPiece({ ALPHANUM(myX + 1), myY + 2 })->getColour() != myColour)) {
		board->arr[myX + 1][myY + 2] = true; 
	}
	if (myX < G && myY < 8 && (chessBoard->getPiece({ ALPHANUM(myX + 2), myY + 1 }) == nullptr || chessBoard->getPiece({ ALPHANUM(myX + 2), myY + 1 })->getColour() != myColour)) {
		board->arr[myX + 2][myY + 1] = true; 
	}
	if (myX < G && myY > 1 && (chessBoard->getPiece({ ALPHANUM(myX + 2), myY - 1 }) == nullptr || chessBoard->getPiece({ ALPHANUM(myX + 2), myY - 1 })->getColour() != myColour)) {
		board->arr[myX + 2][myY - 1] = true; 
	}
	if (myX < H && myY > 2 && (chessBoard->getPiece({ ALPHANUM(myX + 1), myY - 2 }) == nullptr || chessBoard->getPiece({ ALPHANUM(myX + 1), myY - 2 })->getColour() != myColour)) {
		board->arr[myX + 1][myY - 2] = true; 
	}
	if (myX > A && myY > 2 && (chessBoard->getPiece({ ALPHANUM(myX - 1), myY - 2 }) == nullptr || chessBoard->getPiece({ ALPHANUM(myX - 1), myY - 2 })->getColour() != myColour)) {
		board->arr[myX - 1][myY - 2] = true; 
	}
	if (myX > B && myY > 1 && (chessBoard->getPiece({ ALPHANUM(myX - 2), myY - 1 }) == nullptr || chessBoard->getPiece({ ALPHANUM(myX - 2), myY - 1 })->getColour() != myColour)) {
		board->arr[myX - 2][myY - 1] = true; 
	}
}

// Bishop
Bishop::Bishop(COLOUR newColour, ALPHANUM newX, int newY) : ChessPiece(newColour, newX, newY) {
	myPieceType = PIECETYPE::BISHOP;
}

char Bishop::getPieceChar() {
	return 'B';
}

void Bishop::getAvailableMoves(BOOLBOARD* board, ChessBoard* chessBoard) {
	// Loop in 4 diagonal directions

	// Check up-right direction
	for (int i = 1; i < 8; i++) {
		if ((myX + i) > H || (myY + i) > 8) { 
			break; 
		}
		else if (chessBoard->getPiece({ALPHANUM(myX + i), myY + i}) == nullptr) {
			board->arr[myX + i][myY + i] = true; 
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX + i), myY + i })->getColour() != myColour) {
			board->arr[myX + i][myY + i] = true;
			break;
		}
		else {
			break;
		}
	}
	// Check down-right direction
	for (int i = 1; i < 8; i++) {
		if ((myX + i) > H || (myY - i) < 1) {
			break;
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX + i), myY - i }) == nullptr) {
			board->arr[myX + i][myY - i] = true;
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX + i), myY - i })->getColour() != myColour) {
			board->arr[myX + i][myY - i] = true;
			break;
		}
		else {
			break;
		}
	}
	// Check up-left direction
	for (int i = 1; i < 8; i++) {
		if ((myX - i) < A || (myY + i) > 8) {
			break;
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX - i), myY + i }) == nullptr) {
			board->arr[myX - i][myY + i] = true;
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX - i), myY + i })->getColour() != myColour) {
			board->arr[myX - i][myY + i] = true;
			break;
		}
		else {
			break;
		}
	}
	// Check down-left direction
	for (int i = 1; i < 8; i++) {
		if ((myX - i) < A || (myY - i) < 1) {
			break;
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX - i), myY - i }) == nullptr) {
			board->arr[myX - i][myY - i] = true;
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX - i), myY - i })->getColour() != myColour) {
			board->arr[myX - i][myY - i] = true;
			break;
		}
		else {
			break;
		}
	}
}

// Queen
Queen::Queen(COLOUR newColour, ALPHANUM newX, int newY) : ChessPiece(newColour, newX, newY) {
	myPieceType = PIECETYPE::QUEEN;
}

char Queen::getPieceChar() {
	return 'Q';
}

void Queen::getAvailableMoves(BOOLBOARD* board, ChessBoard* chessBoard) {
	// Loop in 4 straight directions and 4 diagonal directions

	// Check right direction
	for (int i = myX + 1; i <= H; i++) {
		if (chessBoard->getPiece({ ALPHANUM(i), myY }) == nullptr) {
			board->arr[i][myY] = true;
		}
		else if (chessBoard->getPiece({ ALPHANUM(i), myY })->getColour() != myColour) {
			board->arr[i][myY] = true;
			break;
		}
		else {
			break;
		}
	}
	// Check left direction
	for (int i = myX - 1; i >= A; i--) {
		if (chessBoard->getPiece({ ALPHANUM(i), myY }) == nullptr) {
			board->arr[i][myY] = true;
		}
		else if (chessBoard->getPiece({ ALPHANUM(i), myY })->getColour() != myColour) {
			board->arr[i][myY] = true;
			break;
		}
		else {
			break;
		}
	}
	// Check up direction
	for (int i = myY + 1; i <= 8; i++) {
		if (chessBoard->getPiece({ myX, i }) == nullptr) {
			board->arr[myX][i] = true;
		}
		else if (chessBoard->getPiece({ myX, i })->getColour() != myColour) {
			board->arr[myX][i] = true;
			break;
		}
		else {
			break;
		}
	}
	// Check down direction
	for (int i = myY - 1; i >= 1; i--) {
		if (chessBoard->getPiece({ myX, i }) == nullptr) {
			board->arr[myX][i] = true;
		}
		else if (chessBoard->getPiece({ myX, i })->getColour() != myColour) {
			board->arr[myX][i] = true;
			break;
		}
		else {
			break;
		}
	}

	// Check up-right direction
	for (int i = 1; i < 8; i++) {
		if ((myX + i) > H || (myY + i) > 8) {
			break;
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX + i), myY + i }) == nullptr) {
			board->arr[myX + i][myY + i] = true;
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX + i), myY + i })->getColour() != myColour) {
			board->arr[myX + i][myY + i] = true;
			break;
		}
		else {
			break;
		}
	}
	// Check down-right direction
	for (int i = 1; i < 8; i++) {
		if ((myX + i) > H || (myY - i) < 1) {
			break;
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX + i), myY - i }) == nullptr) {
			board->arr[myX + i][myY - i] = true;
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX + i), myY - i })->getColour() != myColour) {
			board->arr[myX + i][myY - i] = true;
			break;
		}
		else {
			break;
		}
	}
	// Check up-left direction
	for (int i = 1; i < 8; i++) {
		if ((myX - i) < A || (myY + i) > 8) {
			break;
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX - i), myY + i }) == nullptr) {
			board->arr[myX - i][myY + i] = true;
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX - i), myY + i })->getColour() != myColour) {
			board->arr[myX - i][myY + i] = true;
			break;
		}
		else {
			break;
		}
	}
	// Check down-left direction
	for (int i = 1; i < 8; i++) {
		if ((myX - i) < A || (myY - i) < 1) {
			break;
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX - i), myY - i }) == nullptr) {
			board->arr[myX - i][myY - i] = true;
		}
		else if (chessBoard->getPiece({ ALPHANUM(myX - i), myY - i })->getColour() != myColour) {
			board->arr[myX - i][myY - i] = true;
			break;
		}
		else {
			break;
		}
	}
}

// King
King::King(COLOUR newColour, ALPHANUM newX, int newY) : ChessPiece(newColour, newX, newY) {
	myPieceType = PIECETYPE::KING;
}

char King::getPieceChar() {
	return 'K';
}

void King::getAvailableMoves(BOOLBOARD* board, ChessBoard* chessBoard) {
	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			if (chessBoard->getPiece({ ALPHANUM(myX + x), myY + y }) == nullptr || chessBoard->getPiece({ ALPHANUM(myX + x), myY + y })->getColour() != myColour) {
				board->arr[myX + x][myY + y] = true;
			}
		}
	}
}