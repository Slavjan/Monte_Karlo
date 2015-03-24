#pragma once
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
	std::string str;

	if (argc > 1)
		for (int i = 0; i < argc; i++)
		{
			string arg = string(argv[i]);
			if (arg == opt)
			{	
				if (
					!(string(argv[i + 1])[0] == '-') &&
					i + 1 <= argc
					)
				{
				   str = string(argv[i + 1]);
				} 					
				else throw Empty();
			}
		}
	else
	{
		throw Empty();
	}
	if (str.empty())
		throw Empty();

	return " ";
}

std::vector<int> ParametersReader::findVector(string opt)
{
	std::vector<int> v;
	int sizeInt = sizeof(int)*8,
		_sizeInt = -1 * sizeInt;

	if (argc > 1)
		for (int i = 0; i < argc; i++)
		{
			string arg = string(argv[i]);
			if (arg == opt)
			{
				if (
					atoi(argv[i + 1]) >= _sizeInt && 
					atoi(argv[i + 1]) <= sizeInt
				   )
				{
					while (	
							(i + 1 >= argc) ? false :
							(
								atoi(argv[i + 1]) >= _sizeInt &&
								atoi(argv[i + 1]) <= sizeInt
							)  							
						  )
					{	
						v.push_back(atoi(argv[i + 1]));
						i++;
					}
					if (!v.empty())
						return v;
					else throw Empty();
				}
				else throw Empty();
			}
		}
	else
	{
		throw Empty();
	}
	return v;
}
