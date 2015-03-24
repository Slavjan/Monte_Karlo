#pragma once
#include "stdafx.h"
#include "myApp.h"
#include <stdio.h>


int main(int argc, char** argv)
{
	argv[0] = "Monte_Karlo.exe";
	argv[1] = "-p";
	argv[2] = "0";
	argv[3] = "0";
	argv[4] = "0";
	argv[5] = "10";
	argv[6] = "10";
	argv[7] = "10";
	argv[8] = "10"; 
	argv[9] = "0";
	argc = 10;

	myApp App = myApp(argc, argv);
	bool ex;
	
	ex = App.init();
	
	if (!ex)
	{
		std::cout << "Init failed!" << std::endl;
		return 1;
	}
	
	App.calculate();
	App.returning();


#ifdef _MSC_VER // if compiling in the MS Visual Studio
	system("pause");
#endif

	return 0;
}


