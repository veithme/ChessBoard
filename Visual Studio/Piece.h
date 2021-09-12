#pragma once

enum class PieceType
{
	INVALID = -1,

	PAWN = 0,
	BISHOP,
	KNIGHT,
	ROOK,
	QUEEN,
	KING
};

enum class PieceColour
{
	WHITE = 0,
	BLACK = 1
};

enum class PieceId : unsigned char
{
	INVALID = -1,

	WHITE_PAWN = 0,
	WHITE_BISHOP,
	WHITE_KNIGHT,
	WHITE_ROOK,
	WHITE_QUEEN,
	WHITE_KING,

	BLACK_PAWN,
	BLACK_BISHOP,
	BLACK_KNIGHT,
	BLACK_ROOK,
	BLACK_QUEEN,
	BLACK_KING,
};

inline PieceId MakePieceId( PieceType type, PieceColour colour )
{
	return (PieceId)( ( (unsigned char)type & 0b1111 ) | ( (unsigned char)colour << 4 ) );
}

inline PieceColour GetPieceColour( PieceId piece )
{
	return (PieceColour)( (unsigned char)piece >> 4 );
}

inline PieceType GetPieceType( PieceId piece )
{
	return (PieceType)( (unsigned char)piece & 0b1111 );
}
