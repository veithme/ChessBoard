#include "ChessPiece.h"

// Base Chess Class
ChessPiece::ChessPiece() {
}

ChessPiece::ChessPiece(COLOUR newColour) {
	myColour = newColour;
}

COLOUR ChessPiece::getColour() {
	return myColour;
}

PIECETYPE ChessPiece::getPieceType() {
	return myPieceType;
}

char ChessPiece::getPieceChar() {
	return ' ';
}

// Pawn
Pawn::Pawn(COLOUR newColour) : ChessPiece(newColour) {
	myPieceType = PAWN;
}

char Pawn::getPieceChar() {
	return 'P';
}

// Rook
Rook::Rook(COLOUR newColour) : ChessPiece(newColour) {
	myPieceType = ROOK;
}

char Rook::getPieceChar() {
	return 'R';
}

// Knight
Knight::Knight(COLOUR newColour) : ChessPiece(newColour) {
	myPieceType = KNIGHT;
}

char Knight::getPieceChar() {
	return 'K';
}

// Bishop
Bishop::Bishop(COLOUR newColour) : ChessPiece(newColour) {
	myPieceType = BISHOP;
}

char Bishop::getPieceChar() {
	return 'B';
}

// Queen
Queen::Queen(COLOUR newColour) : ChessPiece(newColour) {
	myPieceType = QUEEN;
}

char Queen::getPieceChar() {
	return 'Q';
}

// King
King::King(COLOUR newColour) : ChessPiece(newColour) {
	myPieceType = KING;
}

char King::getPieceChar() {
	return 'K';
}