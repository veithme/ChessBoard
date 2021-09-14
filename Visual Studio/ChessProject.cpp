// ChessProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\Library\ChessBoard.h"
#include "..\Library\Functions.h"
#include "..\Library\GameManager.h"
#include <iostream>

using namespace std;

int main() {
    StateManager stateManager;

    while (stateManager.running()) {
        stateManager.render();
        stateManager.update();
    }
}