#pragma once
#include "stdafx.h"
#include "myApp.h"


int main(int argc, char** argv)
{
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


