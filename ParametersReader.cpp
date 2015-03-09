#include "ParametersReader.h"

ParametersReader::ParametersReader()
{
	pathFrom = '\0';
	pathTo = '\0';
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
			if (opt == "-i") // from file - input
			{
				pathFrom = std::string(argv[i + 1]);
				i++;
			}
			else if (opt == "-p") // points
			{
				while (atoi(argv[i]) && atoi(argv[i + 1]))
				{
					k.push_back(atoi(argv[i]));
					k.push_back(atoi(argv[i + 1]));
					i++;
				}
			}
			else if (opt == "-o") // to file - output
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

std::string ParametersReader::getPathFrom()
{
	return pathFrom;
}

std::string ParametersReader::getPathTo()
{
	return pathTo;
}