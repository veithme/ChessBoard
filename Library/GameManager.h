#pragma once

#include "Enum.h"
#include "ChessBoard.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <list>

using namespace std;

// States Type
enum class STATES { MAIN_MENU, ABOUT, HELP, GAMEPLAY, QUIT };

//State Parent Class
class State {
public:
    virtual STATES update() = 0;
    virtual void render() = 0;
};

/*States
* 1. Main Menu
* 2. About
* 3. Help
* 4. Gameplay
* 5. Quit
*/
// Main Menu
class MainMenu : public State {
    STATES update();
    void render();
};

// About
class About : public State {
    STATES update();
    void render();
};

// Help
class Help : public State {
    STATES update();
    void render();
};

// Gameplay
class Gameplay : public State {
    protected:
        ChessBoard board; 
        COLOUR turnColour;
    public:
        STATES update();
        void render();
        Gameplay();
};

// Quit
class Quit : public State {
    STATES update();
    void render();
};

// Game State Manager
class StateManager {
private:
    MainMenu _main_menu;
    About _about;
    Help _help;
    Gameplay _gameplay;
    Quit _quit;
    State* _current = &_main_menu;
    STATES _state = STATES::MAIN_MENU;
public:
    StateManager();
    bool running();
    void update();
    void render();
};

// Functions
COORDINATE getCoordinateInput();