#pragma once
#include <stdlib.h>
#include <time.h>

// maxNamber int 
template <class N>
N maxNumber(N a, N b)
{
	return a > b ? a : b;
}

template <class N>
N minNumber(N a, N b)
{
	return a < b ? a : b;
}


#if defined (_MY_TIME)
#define MY_TIME
int clockInThisSecond()
{
	int c = clock(), _c = c;
	if (c > 100)
	{
		_c /= 100;
		_c *= 100;
		c -= _c;
	}
	return c;
}
#endif
