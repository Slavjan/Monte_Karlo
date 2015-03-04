#include "ParametersReader.h"

ParametersReader::ParametersReader()
{
	path = '\0';
}
ParametersReader::~ParametersReader()
{}

void ParametersReader::parsing(int argc, char** argv)
{
	if (argc == 1)
	{
		throw "parameters wasn`t entering";
		return;
	}
	else if (argc % 2 == 0)	 
	{
		throw "invalid parameters count";
		return;
	}	
	else
	{
		for (int i = 1; i < argc; i += 2)
		{
			std::string  opt = std::string(argv[i]);
			if (opt == "-f")
			{
				path = std::string(argv[i + 1]);
				i++;
			}
			else if (opt == "-p")
			{
				k.push_back(atoi(argv[i]));
				k.push_back(atoi(argv[i + 1]));
			}
		}
	}
}

std::vector <int> ParametersReader::getVector()
{
	return k;
}

std::string ParametersReader::getPath()
{
	return path;
}