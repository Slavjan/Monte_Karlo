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


int clockInThisSecond()
{

	int c = clock(), _c = c;
	if (c > 1000)
	{
		_c /= 1000;
		_c *= 1000;
		c -= _c;
	}
	return c;
}



