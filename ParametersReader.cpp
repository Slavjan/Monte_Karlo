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
		throw Empty();
		return;
	}
	else if (argc % 2 == 0)	 
	{
		throw Invalid();
		return;
	}	
	else
	{
		for (int i = 1; i < argc; i += 2)
		{
			std::string  opt = std::string(argv[i]);
			if (opt == "-ff") // from file
			{
				pathFrom = std::string(argv[i + 1]);
				i++;
			}
			else if (opt == "-p") // points
			{
				k.push_back(atoi(argv[i]));
				k.push_back(atoi(argv[i + 1]));
			}
			else if (opt == "-tf") // to file
			{
				pathTo = std::string(argv[i + 1]);
				i++;
			}
		}
	}
}

std::vector<int> ParametersReader::getVector()
{
	return k;
}

std::string ParametersReader::getPath()
{
	return path;
}