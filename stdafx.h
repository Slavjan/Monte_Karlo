#pragma once
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

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