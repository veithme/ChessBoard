#pragma once

// Chess Piece Types
enum PIECETYPE {PAWN = 1, ROOK, KNIGHT, BISHOP, QUEEN, KING};
enum ALPHANUM {A = 1, B, C, D, E, F, G, H};
enum COLOUR {WHITE = 0, BLACK = 1};

struct COORDINATE {
	ALPHANUM X;
	int Y;
};

// Base Chess Piece Class
class ChessPiece {
	protected:
		COORDINATE myCoordinate;
		PIECETYPE myPieceType;
		COLOUR myColour;
	public:
		ChessPiece();
		ChessPiece(COLOUR newColour);
		COLOUR getColour();
		PIECETYPE getPieceType();
		virtual char getPieceChar();
};

// Pawn
class Pawn : public ChessPiece {
	public:
		Pawn(COLOUR newColour);
		char getPieceChar();
};

// Rook
class Rook : public ChessPiece {
public:
	Rook(COLOUR newColour);
	char getPieceChar();
};

// Knight
class Knight : public ChessPiece {
public:
	Knight(COLOUR newColour);
	char getPieceChar();
};

// Bishop
class Bishop : public ChessPiece {
public:
	Bishop(COLOUR newColour);
	char getPieceChar();
};

// Queen
class Queen : public ChessPiece {
public:
	Queen(COLOUR newColour);
	char getPieceChar();
};

// King
class King : public ChessPiece {
public:
	King(COLOUR newColour);
	char getPieceChar();
};
