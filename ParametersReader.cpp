#include "ParametersReader.h"
// public
		   
ParametersReader::ParametersReader(int _argc, char** _argv)
{
	argc = _argc;
	argv = _argv;
}

ParametersReader::~ParametersReader()
{}

string ParametersReader::findString(string opt)
{
	if (argc > 1)
		for (int i = 0; i < argc; i++)
		{
			string arg = string(argv[i]);
			if (
				arg == opt && 
				!(string(argv[i + 1])[0] == '-') && 
				i + 1 <= argc
			   )
				return string(argv[i+1]);
			else throw Empty();
		}
	else
	{
		throw Empty();
	}
}

std::vector<int> ParametersReader::findVector(string opt)
{
	std::vector<int> v;

	if (argc > 1)
		for (int i = 0; i < argc; i++)
		{
			string arg = string(argv[i]);
			if (arg == opt && i + 1 <= argc)
			{
				while (atoi(argv[i + 1]) && i + 1 <= argc)
				{
					v.push_back(atoi(argv[i+1]));
					i++;
				}
				if (v.size() % 2 != 0)
				{
					throw Invalid();
				}		  
				return v;
			}
			else
			{
				throw Empty();
			}
		}
	else
	{
		throw Empty();
	}
}
