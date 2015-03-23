#include "stdafx.h"
#include "grn.h"
#include <iostream>

int main(int argc, char** argv)
{	
	grn a;
	
	for (int i = 0; i < 5; i++)
		std::cout << "random: " << a.random()
		<< " Mid Multipl (MMM): " << a.MMM()
		<< " Mid Squares (MMS): " << a.MMS()
		<< " generate: " << a.generate()
		<< " getInRange 1 - 100: " << a.genInRange(1, 100)
		<< std::endl;

#ifdef _MSC_VER // if compiling in the MS Visual Studio
	system("pause");
#endif

	return 0;
}


