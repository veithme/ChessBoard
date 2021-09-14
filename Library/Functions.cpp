#include "Functions.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <list>

using namespace std;

/* Split String Function
*  - Splits input string by specified delimeter writes to a refrenced queue
*/
vector <string> splitString(string input, string delimiter)
{
    string substring;
    vector <string> splitString;
    int pos = 0;
    while ((pos = input.find(delimiter)) != string::npos) {
        substring = input.substr(0, pos);
        splitString.push_back(substring);
        input.erase(0, pos + delimiter.length());
    }
    splitString.push_back(input);

    return splitString;
}

// String to uppercase
string toUpper(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

// String to lowercase
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Get Integer Input
int getIntInput() {
    int input;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
    }
    cin >> input;
    return input;
}
// Get Character Input
char getCharInput() {
    char input;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
    }
    cin >> input;
    return toupper(input);
}
// Get String Input Function
string getStringInput(bool keepCase) {
    string input;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
    }
    do {
        getline(cin, input);
    } while (input == "");  
    if (!keepCase) {
        for (auto& c : input) c = toupper(c);
    }
    return input;
}
// Get Enter Input
bool getEnterInput() {
    if (cin.fail()) {
        cin.clear();
    }
    do {
        cin.ignore();
    } while (cin.get() != '\n');
    return true;
}