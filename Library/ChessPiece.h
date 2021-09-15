#pragma once

#include "Enum.h"
#include "Structs.h"

// Forward Declaration of ChessBoard class
class ChessBoard;

// Base Chess Piece Class
class ChessPiece {
	protected:
		PIECETYPE myPieceType;
		COLOUR myColour;
		ALPHANUM myX;
		int myY;
	public:
		ChessPiece(COLOUR newColour, ALPHANUM newX, int newY);
		COLOUR getColour();
		PIECETYPE getPieceType();
		virtual char getPieceChar() = 0;
		virtual void getAvailableMoves(BOOLBOARD* board, ChessBoard* chessBoard) = 0;
		void setCoordinate(COORDINATE newCoordinate);
		COORDINATE getCoordinate();
};

// Pawn
class Pawn : public ChessPiece {
	public:
		Pawn(COLOUR newColour, ALPHANUM newX, int newY);
		char getPieceChar();
		void getAvailableMoves(BOOLBOARD* board, ChessBoard* chessBoard);
};

// Rook
class Rook : public ChessPiece {
public:
	Rook(COLOUR newColour, ALPHANUM newX, int newY);
	char getPieceChar();
	void getAvailableMoves(BOOLBOARD* board, ChessBoard* chessBoard);
};

// Knight
class Knight : public ChessPiece {
public:
	Knight(COLOUR newColour, ALPHANUM newX, int newY);
	char getPieceChar();
	void getAvailableMoves(BOOLBOARD* board, ChessBoard* chessBoard);
};

// Bishop
class Bishop : public ChessPiece {
public:
	Bishop(COLOUR newColour, ALPHANUM newX, int newY);
	char getPieceChar();
	void getAvailableMoves(BOOLBOARD* board, ChessBoard* chessBoard);
};

// Queen
class Queen : public ChessPiece {
public:
	Queen(COLOUR newColour, ALPHANUM newX, int newY);
	char getPieceChar();
	void getAvailableMoves(BOOLBOARD* board, ChessBoard* chessBoard);
};

// King
class King : public ChessPiece {
public:
	King(COLOUR newColour, ALPHANUM newX, int newY);
	char getPieceChar();
	void getAvailableMoves(BOOLBOARD* board, ChessBoard* chessBoard);
};
