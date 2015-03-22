#include "stdafx.h"
#include "ParametersReader.h"


int main(int argc, char** argv)
{	
	argv[0] = "test.exe";
	argv[1] = "-p";	  // jlkjlj 
	argv[2] = "-o";
	argc = 3;

	ParametersReader arg = ParametersReader(argc, argv);

	try
	{
		std::string str = arg.findString("-p");	  
		std::cout << str.data() << std::endl;
	}
	catch (ParametersReader::Empty)
	{
		std::cout << "Empty!" << std::endl;
	}
	catch (ParametersReader::Invalid)
	{
		std::cout << "Invalid" << std::endl;
	}

#ifdef _MSC_VER // if compiling in the MS Visual Studio
	system("pause");
#endif

	return 0;
}


