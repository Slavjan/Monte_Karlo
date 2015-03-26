#pragma once


#include "stdafx.h"
#include "myApp.h"
#include <stdio.h>


int main(int argc, char** argv)
{
	int _argc = 10;
	char* _argv[] = { "Monte_Karlo.exe", "-p", "0", "0", "0", "10", "10", "10", "10", "0"};

	myApp App = myApp(_argc, _argv);
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


