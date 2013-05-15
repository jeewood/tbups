#include "data_struct.h"

CValue Value={0};
//SValue sValue={0};
int sValue[10] = {0};

Bits bFlag={0};
Bits ControlBits={0};
/*
b0 = work mode
b1 = start mode
*/

unsigned int Root(unsigned long Number) {
	unsigned int i;
	unsigned long SquareRoot;
	if( Number == 0)
	{
	    return 0;
	}
	if( Number <= 4194304 )
	{
	    SquareRoot = ( Number >> 10 ) + 63;
	}
	else if ( Number <= 134217728 )
	{
	    SquareRoot = ( Number >> 12 ) + 255;
	}
	else
	{
		SquareRoot = ( Number >> 14 ) + 1023;
	}
	for ( i = 0; i < 5; i++ )
	{
		SquareRoot=( SquareRoot + Number / SquareRoot ) >> 1;
	}
	return ((unsigned int)SquareRoot);
}

