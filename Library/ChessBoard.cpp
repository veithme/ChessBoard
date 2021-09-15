#include "ChessPiece.h"
#include "ChessBoard.h"
#include <windows.h>

using namespace std;

/*________________________________
8 | _ | # | _ | # | _ | # | _ | # |
7 | # | _ | # | _ | # | _ | # | _ |
6 | _ | # | _ | # | _ | # | _ | # |
5 | # | _ | # | _ | # | _ | # | _ |
4 | _ | # | _ | # | _ | # | _ | # |
3 | # | _ | # | _ | # | _ | # | _ |
2 | _ | # | _ | # | _ | # | _ | # |
1 | # | _ | # | _ | # | _ | # | _ |
    a   b   c   d   e   f   g   h
*/
ChessBoard::ChessBoard() {

	myBoard[{A,1}] = new Rook  (COLOUR::WHITE, A, 1);
	myBoard[{B,1}] = new Knight(COLOUR::WHITE, B, 1);
	myBoard[{C,1}] = new Bishop(COLOUR::WHITE, C, 1);
	myBoard[{D,1}] = new King(COLOUR::WHITE, D, 1);
	myBoard[{E,1}] = new Queen(COLOUR::WHITE, E, 1);
	myBoard[{F,1}] = new Bishop(COLOUR::WHITE, F, 1);
	myBoard[{G,1}] = new Knight(COLOUR::WHITE, G, 1);
	myBoard[{H,1}] = new Rook(COLOUR::WHITE, H, 1);

	myBoard[{A,2}] = new Pawn(COLOUR::WHITE, A, 2);
	myBoard[{B,2}] = new Pawn(COLOUR::WHITE, B, 2);
	myBoard[{C,2}] = new Pawn(COLOUR::WHITE, C, 2);
	myBoard[{D,2}] = new Pawn(COLOUR::WHITE, D, 2);
	myBoard[{E,2}] = new Pawn(COLOUR::WHITE, E, 2);
	myBoard[{F,2}] = new Pawn(COLOUR::WHITE, F, 2);
	myBoard[{G,2}] = new Pawn(COLOUR::WHITE, G, 2);
	myBoard[{H,2}] = new Pawn(COLOUR::WHITE, H, 2);

	myBoard[{A,8}] = new Rook  (COLOUR::BLACK, A, 8);
	myBoard[{B,8}] = new Knight(COLOUR::BLACK, B, 8);
	myBoard[{C,8}] = new Bishop(COLOUR::BLACK, C, 8);
	myBoard[{D,8}] = new King(COLOUR::BLACK, D, 8);
	myBoard[{E,8}] = new Queen(COLOUR::BLACK, E, 8);
	myBoard[{F,8}] = new Bishop(COLOUR::BLACK, F, 8);
	myBoard[{G,8}] = new Knight(COLOUR::BLACK, G, 8);
	myBoard[{H,8}] = new Rook(COLOUR::BLACK, H, 8);

	myBoard[{A,7}] = new Pawn(COLOUR::BLACK, A, 7);
	myBoard[{B,7}] = new Pawn(COLOUR::BLACK, B, 7);
	myBoard[{C,7}] = new Pawn(COLOUR::BLACK, C, 7);
	myBoard[{D,7}] = new Pawn(COLOUR::BLACK, D, 7);
	myBoard[{E,7}] = new Pawn(COLOUR::BLACK, E, 7);
	myBoard[{F,7}] = new Pawn(COLOUR::BLACK, F, 7);
	myBoard[{G,7}] = new Pawn(COLOUR::BLACK, G, 7);
	myBoard[{H,7}] = new Pawn(COLOUR::BLACK, H, 7);

	validMoves = new BOOLBOARD{ false };

}

void ChessBoard::printBoard() {

	ChessPiece* piece;
	
	// Color of the console text
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 8);

	// Loop through all tiles of chess board
	cout << endl;
	for (int y = 8; y >= 1; y--) {
		cout << y << " ";
		for (int x = A; x <= H; x = x++) {

			SetConsoleTextAttribute(console_color, 8);
			cout << "[";

			// Print each piece
			piece = myBoard[{ALPHANUM(x), y}];

			if (piece != nullptr) {
				if (piece == selectedPiece) {
					SetConsoleTextAttribute(console_color, 10); // Green
				}
				else if (piece->getColour() == COLOUR::BLACK) {
					SetConsoleTextAttribute(console_color, (validMoves->arr[x][y] == true ? 41 : 9)); // Blue
				}
				else {
					SetConsoleTextAttribute(console_color, (validMoves->arr[x][y] == true ? 47 : 15)); // White
				}
				cout << piece->getPieceChar();
			}
			else {
				SetConsoleTextAttribute(console_color, (validMoves->arr[x][y] == true ? 47 : 15)); // White
				cout << " ";
			}

			SetConsoleTextAttribute(console_color, 8);
			cout << "]";

		}
		cout << endl;
	}
	cout << "   A  B  C  D  E  F  G  H " << endl << endl;
	SetConsoleTextAttribute(console_color, 7); // Reset colour to default
	
}

bool ChessBoard::movePiece(ChessPiece* piece, COORDINATE newCoordinate) {
	// Check move is valid
	if (validMoves->arr[newCoordinate.X][newCoordinate.Y]) {
		myBoard[piece->getCoordinate()] = nullptr;
		delete myBoard[newCoordinate];
		myBoard[newCoordinate] = piece;
		piece->setCoordinate(newCoordinate);
		return true;
	}
	else {
		return false;
	}
}

ChessPiece* ChessBoard::getPiece(COORDINATE coordinate){
	return myBoard[coordinate];
}

ChessPiece* ChessBoard::selectPiece(COORDINATE coordinate, COLOUR colour) {
	selectedPiece = myBoard[coordinate];
	if (selectedPiece != nullptr && selectedPiece->getColour() == colour) {
		return selectedPiece;
	}
	else {
		return nullptr;
	}
}

void ChessBoard::unselectPiece() {
	selectedPiece = nullptr;
}

void ChessBoard::checkValidMoves() {
	selectedPiece->getAvailableMoves(validMoves, this);
}

void ChessBoard::resetValidMoves() {
	delete validMoves;
	validMoves = new BOOLBOARD{ false };
}
