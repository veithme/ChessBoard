#pragma once directive 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <list>

using namespace std;

int getIntInput();
char getCharInput();
string getStringInput(bool keepCase);
bool getEnterInput();
string toUpper(string str);
string toLower(string str);
vector <string> splitString(string input, string delimiter);