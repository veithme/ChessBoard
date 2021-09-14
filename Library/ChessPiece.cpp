#include "ChessPiece.h"

ChessPiece::ChessPiece(COLOUR newColour, COORDINATE newCoordinate) {
	myColour = newColour;
	myCoordinate = newCoordinate;
	myPieceType = PIECETYPE::NONE;
}

COLOUR ChessPiece::getColour() {
	return myColour;
}

PIECETYPE ChessPiece::getPieceType() {
	return myPieceType;
}

//char ChessPiece::getPieceChar() {
//	return ' ';
//}

//void ChessPiece::getAvailableMoves(BOOLBOARD board) {
//	;
//}

void ChessPiece::setCoordinate(COORDINATE newCoordinate) {
	myCoordinate = newCoordinate;
}

COORDINATE ChessPiece::getCoordinate() {
	return myCoordinate;
}

// Pawn
Pawn::Pawn(COLOUR newColour, COORDINATE newCoordinate) : ChessPiece(newColour, newCoordinate) {
	myPieceType = PIECETYPE::PAWN;
}

char Pawn::getPieceChar() {
	return 'P';
}

void Pawn::getAvailableMoves(BOOLBOARD* board) {
	
	switch (myColour) {
		case COLOUR::BLACK:
			if (myCoordinate.Y == 7) {
				board->board[myCoordinate.X][myCoordinate.Y - 1] = true;
				board->board[myCoordinate.X][myCoordinate.Y - 2] = true;
			}
			else if (myCoordinate.Y > 1) {
				board->board[myCoordinate.X][myCoordinate.Y - 1] = true;
			}
		case COLOUR::WHITE:
			if (myCoordinate.Y == 2) {
				board->board[myCoordinate.X][myCoordinate.Y + 1] = true;
				board->board[myCoordinate.X][myCoordinate.Y + 2] = true;
			}
			else if	(myCoordinate.Y < 8) {
				board->board[myCoordinate.X][myCoordinate.Y + 1] = true;
			}
		}
		
}

// Rook
Rook::Rook(COLOUR newColour, COORDINATE newCoordinate) : ChessPiece(newColour, newCoordinate) {
	myPieceType = PIECETYPE::ROOK;
}

char Rook::getPieceChar() {
	return 'R';
}

void Rook::getAvailableMoves(BOOLBOARD* board)
{
}

// Knight
Knight::Knight(COLOUR newColour, COORDINATE newCoordinate) : ChessPiece(newColour, newCoordinate) {
	myPieceType = PIECETYPE::KNIGHT;
}

char Knight::getPieceChar() {
	return 'K';
}

void Knight::getAvailableMoves(BOOLBOARD* board)
{
}

// Bishop
Bishop::Bishop(COLOUR newColour, COORDINATE newCoordinate) : ChessPiece(newColour, newCoordinate) {
	myPieceType = PIECETYPE::BISHOP;
}

char Bishop::getPieceChar() {
	return 'B';
}

void Bishop::getAvailableMoves(BOOLBOARD* board)
{
}

// Queen
Queen::Queen(COLOUR newColour, COORDINATE newCoordinate) : ChessPiece(newColour, newCoordinate) {
	myPieceType = PIECETYPE::QUEEN;
}

char Queen::getPieceChar() {
	return 'Q';
}

void Queen::getAvailableMoves(BOOLBOARD* board)
{
}

// King
King::King(COLOUR newColour, COORDINATE newCoordinate) : ChessPiece(newColour, newCoordinate) {
	myPieceType = PIECETYPE::KING;
}

char King::getPieceChar() {
	return 'K';
}

void King::getAvailableMoves(BOOLBOARD* board)
{
}
