#include "GameManager.h"
#include "ChessPiece.h"
#include "Functions.h"

using namespace std;

/*States
* Main Menu
* About
* Help
* Select Adventure
* Gameplay
* New High Score
* Hall Of Fame
* Quit
*/
// Main Menu
    STATES MainMenu::update() {
        // Process input
        int input;
        input = getIntInput();
        while (input < 1 || input > 5) {
            cout << "Invalid input. Select 1 - 4: >";
            input = getIntInput();
        }
        // State selection
        switch (input) {
            case 1: return STATES::GAMEPLAY;
            case 2: return STATES::HELP;
            case 3: return STATES::ABOUT;
            case 4: return STATES::QUIT;
            default: return STATES::MAIN_MENU;
        }
    }
    void MainMenu::render() {
        cout << "\nChess :: Main Menu"
                "\n----------------------------------------------"
                "\n1. Play"
                "\n2. Help"
                "\n3. About"
                "\n4. Quit"
                "\nSelect 1 - 4: > ";
    }

// About
    STATES About::update() {
        getEnterInput();
        return STATES::MAIN_MENU;
    }
    void About::render() {
        cout << "\nChess :: About"
                "\n----------------------------------------------"
                "\nWritten by : Micah Veith"
                "\nPress Enter to return to the Main Menu"
                "\n";
    }

// Help
STATES Help::update() {
    getEnterInput();
    return STATES::MAIN_MENU;
}
void Help::render() {
    cout << "\nChess :: Help"
            "\n----------------------------------------------"
            "\n"
            "\nThe following commands are supported:"
            "\n quit"
            "\n hiscore"
            "\n"
            "\nPress Enter to return to the Main Menu"
            "\n";
}

// Gameplay
Gameplay::Gameplay() {
    turnColour = COLOUR::WHITE;
};

STATES Gameplay::update() {
    ChessPiece* selectedPiece;
    bool valid;

    // Print player turn
    cout << (turnColour == COLOUR::WHITE ? "White Player Turn" : "Black Player Turn") << endl;

    // Piece Selection
    cout << "Select piece: ";
    do {
        selectedPiece = board.selectPiece(getCoordinateInput(), turnColour);
        if (selectedPiece == nullptr) {
            cout << endl << "Invalid selection. Select piece: ";
        }
    } while (selectedPiece == nullptr);

    // Piece movement
    board.checkValidMoves();
    board.printBoard();
    cout << "Move piece to: ";
    do {
        valid = board.movePiece(selectedPiece, getCoordinateInput());
        if (!valid) {
            cout << endl << "Invalid selection. Move piece to: ";
        }
    } while (!valid);

    board.unselectPiece();
    board.resetValidMoves();

    // Switch turn
    turnColour = (turnColour == COLOUR::WHITE ? COLOUR::BLACK : COLOUR::WHITE);

    return STATES::GAMEPLAY;
}
void Gameplay::render() {
    board.printBoard(); // Show chess board
}

// Quit
STATES Quit::update() {
    return STATES::QUIT;
}
void Quit::render() {
}

// Game State Manager
StateManager::StateManager() {
}
bool StateManager::running() {
    return (_state != STATES::QUIT);
}

void StateManager::update() {
    _state = _current->update();
    switch (_state) {
        case STATES::MAIN_MENU: _current = &_main_menu; break;
        case STATES::ABOUT: _current = &_about; break;
        case STATES::HELP: _current = &_help; break;
        case STATES::GAMEPLAY: _current = &_gameplay; break;
        case STATES::QUIT: _current = &_quit; break;
    }
}

void StateManager::render() {
    _current->render();
}

// FUNCTIONS

// Get Coordinate
COORDINATE getCoordinateInput() {
    
    // Process & validate input
    string input;
    bool valid;
    COORDINATE coordinate = { NONE, 0 };

    valid = false;
    coordinate = { ALPHANUM::A, 1 };

    do {
        input = getStringInput(false);
        if (input.length() != 2 || input.front() < 'A' || input.front() > 'H' || input.back() < '1' || input.back() > '8') {
            cout << "Incorrect format. Enter coordinates in format 'A1'" << endl;
        }
        else {
            coordinate.X = ALPHANUM(int(input.front()) - 'A' + 1);
            coordinate.Y = int(input.back()) - '0';
            valid = true;
        };
    } while (!valid);
    
    return coordinate;
}