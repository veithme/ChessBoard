#include "PieceSensor.h"

// Specifies which pins are used to select input for each of the 4 multiplexers
static int controlPins[4][4] = {
	// { s0, s1, s2, s3 }
	{  1,  2,  3,  4 },
	{ 23, 22, 21, 20 },
	{ 37, 36, 35, 34 },
	{ 28, 29, 30, 31 }
};

// Specifies which pins are used for output for each of the 4 multiplexers
static int signalPins[4] = {
	5,
	19,
	33,
	32
};

static int MuxRead( int muxIndex, int channel )
{
	// Set the control pins
	for( int i = 0; i < 4; i++ )
	{
		digitalWrite( controlPins[muxIndex][i], ( channel >> i ) & 1 );
	}

	// Read analog output of the mux
	return analogRead( signalPins[muxIndex] );
}

static PieceId SensorValueToPiece( int value )
{
	// The HE sensor gives the following values:
	//  - 1V when there is no magnetic field detected
	//  - 2V for maximum north polarity magnetic field
	//  - 0V for maximum south polarity magnetic field

	// The full range of the ADC is 10 bits across 3.3V, which is 1024 points
	// However, since the maximum value we receive from the sensor is 2V, the
	// highest value is (2/3.3) * 1024 = 620
	constexpr int ADC_RANGE = 620;
	
	// To simplify things, we shift the [0,620] range into a [-310,310] range
	value -= ADC_RANGE / 2;

	// If we're in the negative range, then we have a black piece
	PieceColour colour = PieceColour::WHITE;
	if( value < 0 )
	{
		value = -value;
		colour = PieceColour::BLACK;
	}

	// No magnetic field means no piece
	if( value < 20 )
		return PieceId::INVALID;

	PieceType type;
	if( value < 100 )
		type = PieceType::PAWN;
	else if( value < 200 )
		type = PieceType::BISHOP;
	else if( value < 300 )
		type = PieceType::KNIGHT;
	else if( value < 400 )
		type = PieceType::ROOK;
	else if( value < 500 )
		type = PieceType::QUEEN;
	else if( value < 600 )
		type = PieceType::KING;

	return MakePieceId( type, colour );
}

PieceId PieceSensor::GetPieceAt( int x, int y )
{
	// The board contains 4 separate multiplexers (1 for every 2 rows)
	// The first step is to figure out which multiplexer to use
	int muxIndex = y / 2;
	// Adjust y coordinate to be relative to each mux
	y = y % 2;
	
	// Next, figure out the index of the sensor for that mux
	int sensorIndex = ( y * 8 ) + x;

	// Get a reading from the sensor
	int sensorValue = MuxRead( muxIndex, sensorIndex );

	// Convert from analog value to piece
	return SensorValueToPiece( sensorValue );
}