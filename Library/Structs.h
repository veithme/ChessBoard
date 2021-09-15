#pragma once

#include "Enum.h"

// Coordinate Structure
struct COORDINATE {
	ALPHANUM X;
	int Y;
	bool operator < (const COORDINATE rhs) const { return (this->X < rhs.X) || ((this->X == rhs.X) && (this->Y < rhs.Y)); }
	bool operator > (const COORDINATE rhs) const { return (this->X > rhs.X) || ((this->X == rhs.X) && (this->Y > rhs.Y)); }
};

// Array of bools
struct BOOLBOARD {
	bool arr[H + 1][8 + 1];
};