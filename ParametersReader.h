#pragma once
#include <vector>
#include <iostream>



class ParametersReader
{
private:
	std::vector <int> k;
	std::string path;
public:
	ParametersReader();
	~ParametersReader();

	void parsing(int argc, char** argv);

	std::vector <int> getVector();
	std::string getPath();
};

