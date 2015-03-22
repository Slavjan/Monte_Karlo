#include "stdafx.h"
#include "ParametersReader.h"


int main(int argc, char** argv)
{	
	ParametersReader arg = ParametersReader(argc, argv);

	arg.findString("-p");

#ifdef _MSC_VER // if compiling in the MS Visual Studio
	system("pause");
#endif

	return 0;
}


