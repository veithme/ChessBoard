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
	myBoard[A][1] = new Rook(COLOUR::WHITE);
	myBoard[B][1] = new Knight(COLOUR::WHITE);
	myBoard[C][1] = new Bishop(COLOUR::WHITE);
	myBoard[D][1] = new King(COLOUR::WHITE);
	myBoard[E][1] = new Queen(COLOUR::WHITE);
	myBoard[F][1] = new Bishop(COLOUR::WHITE);
	myBoard[G][1] = new Knight(COLOUR::WHITE);
	myBoard[H][1] = new Rook(COLOUR::WHITE);

	myBoard[A][2] = new Pawn(COLOUR::WHITE);
	myBoard[B][2] = new Pawn(COLOUR::WHITE);
	myBoard[C][2] = new Pawn(COLOUR::WHITE);
	myBoard[D][2] = new Pawn(COLOUR::WHITE);
	myBoard[E][2] = new Pawn(COLOUR::WHITE);
	myBoard[F][2] = new Pawn(COLOUR::WHITE);
	myBoard[G][2] = new Pawn(COLOUR::WHITE);
	myBoard[H][2] = new Pawn(COLOUR::WHITE);

	myBoard[A][8] = new Rook(COLOUR::BLACK);
	myBoard[B][8] = new Knight(COLOUR::BLACK);
	myBoard[C][8] = new Bishop(COLOUR::BLACK);
	myBoard[D][8] = new King(COLOUR::BLACK);
	myBoard[E][8] = new Queen(COLOUR::BLACK);
	myBoard[F][8] = new Bishop(COLOUR::BLACK);
	myBoard[G][8] = new Knight(COLOUR::BLACK);
	myBoard[H][8] = new Rook(COLOUR::BLACK);

	myBoard[A][7] = new Pawn(COLOUR::BLACK);
	myBoard[B][7] = new Pawn(COLOUR::BLACK);
	myBoard[C][7] = new Pawn(COLOUR::BLACK);
	myBoard[D][7] = new Pawn(COLOUR::BLACK);
	myBoard[E][7] = new Pawn(COLOUR::BLACK);
	myBoard[F][7] = new Pawn(COLOUR::BLACK);
	myBoard[G][7] = new Pawn(COLOUR::BLACK);
	myBoard[H][7] = new Pawn(COLOUR::BLACK);

}

void ChessBoard::printBoard() {
	// Color of the console
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 40);

	for (int y = 8; y >= 1; y--) {
		cout << y << " ";
		for (int x = A; x <= H; x++) {

			// Print board w pieces
			if (myBoard[x][y] != nullptr) {
				cout << "[" << myBoard[x][y]->getPieceChar() << "]";
			}
			else {
				cout << "[ ]";
			}
		}
		cout << endl;
	}
	cout << "   A  B  C  D  E  F  G  H " << endl;
}