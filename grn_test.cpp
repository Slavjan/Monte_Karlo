#pragma once
#include <iostream>

#include "grn.h"

int main(int argc, char** argv)
{	
	grn a;
	
	for (int i = 0; i < 100; i++)
		std::cout << "[" << i << "]"
				  << "random: " << a.random()
				/*  << " Mid Multipl (MMM): " << a.MMM()
				  << "\t Mid Squares (MMS): " << a.MMS()
				*/  << "\t generate: " << a.generate()
				 /* << " getInRange 1 - 100: " << a.genInRange(1, 100)
				  << std::endl*/ << std::endl;


#ifdef _MSC_VER // if compiling in the MS Visual Studio
	system("pause");
#endif

	return 0;
}


