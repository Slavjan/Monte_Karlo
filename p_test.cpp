#include "stdafx.h"
#include "ParametersReader.h"


int main(int argc, char** argv)
{	
	argv[0] = "test.exe";
	argv[1] = "-p";	  // jlkjlj 
	argv[2] = "0";
	argv[3] = "0";
	argv[4] = "0";
	argv[5] = "10";
	argv[6] = "10";
	argv[7] = "10";
	argv[8] = "10";
	argv[9] = "0";
	argc = 10;

	ParametersReader arg = ParametersReader(argc, argv);

	try
	{
		std::string str = arg.findString("-p");	
		std::cout << "string:" << str.data() << std::endl;
	}
	catch (ParametersReader::Empty)
	{
		std::cout << "Empty str! " << std::endl;
	}
	catch (ParametersReader::Invalid)
	{
		std::cout << "Invalid str!" << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::vector<int> v = arg.findVector("-p");
		for (int i = 0; i < v.size(); i++)
		{
			std::cout << "vector:" << v.at(i) << " ";
		}
		std::cout << std::endl;
	}
	catch (ParametersReader::Empty)
	{
		std::cout << "Empty vector!" << std::endl;
	}
	catch (ParametersReader::Invalid)
	{
		std::cout << "Invalid vector!" << std::endl;
	}

#ifdef _MSC_VER // if compiling in the MS Visual Studio
	system("pause");
#endif

	return 0;
}


