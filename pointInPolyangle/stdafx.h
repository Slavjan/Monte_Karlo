#pragma once
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

// maxNamber int 
template <class N>
N maxNamber(N a, N b)
{
	return a > b ? a : b;
}
template <class N>
N minNamber(N a, N b)
{
	return a < b ? a : b;
}