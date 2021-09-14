#pragma once

// Chess Piece Types & Colours
enum class PIECETYPE {NONE = 0, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING};\
enum class COLOUR {WHITE = 0, BLACK = 1};
enum ALPHANUM { NONE = 0, A, B, C, D, E, F, G, H };

// Coordinate Structure
struct COORDINATE {
	ALPHANUM X;
	int Y;
	bool operator < (const COORDINATE rhs) const { return (this->X < rhs.X) || ((this->X == rhs.X) && (this->Y < rhs.Y)); }
	bool operator > (const COORDINATE rhs) const { return (this->X > rhs.X) || ((this->X == rhs.X) && (this->Y > rhs.Y)); }
};

// Array of bools
struct BOOLBOARD {
	bool board[H + 1][8 + 1];
};

// Base Chess Piece Class
class ChessPiece {
	protected:
		PIECETYPE myPieceType;
		COLOUR myColour;
		COORDINATE myCoordinate;
	public:
		//ChessPiece();
		ChessPiece(COLOUR newColour, COORDINATE newCoordinate);
		COLOUR getColour();
		PIECETYPE getPieceType();
		virtual char getPieceChar() = 0;
		virtual void getAvailableMoves(BOOLBOARD* board) = 0;
		void setCoordinate(COORDINATE newCoordinate);
		COORDINATE getCoordinate();
};

// Pawn
class Pawn : public ChessPiece {
	public:
		Pawn(COLOUR newColour, COORDINATE newCoordinate);
		char getPieceChar();
		void getAvailableMoves(BOOLBOARD* board);
};

// Rook
class Rook : public ChessPiece {
public:
	Rook(COLOUR newColour, COORDINATE newCoordinate);
	char getPieceChar();
	void getAvailableMoves(BOOLBOARD* board);
};

// Knight
class Knight : public ChessPiece {
public:
	Knight(COLOUR newColour, COORDINATE newCoordinate);
	char getPieceChar();
	void getAvailableMoves(BOOLBOARD* board);
};

// Bishop
class Bishop : public ChessPiece {
public:
	Bishop(COLOUR newColour, COORDINATE newCoordinate);
	char getPieceChar();
	void getAvailableMoves(BOOLBOARD* board);
};

// Queen
class Queen : public ChessPiece {
public:
	Queen(COLOUR newColour, COORDINATE newCoordinate);
	char getPieceChar();
	void getAvailableMoves(BOOLBOARD* board);
};

// King
class King : public ChessPiece {
public:
	King(COLOUR newColour, COORDINATE newCoordinate);
	char getPieceChar();
	void getAvailableMoves(BOOLBOARD* board);
};
