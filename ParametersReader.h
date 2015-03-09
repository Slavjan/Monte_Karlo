#pragma once
#include <vector>
#include <iostream>



class ParametersReader
{
private:  
	// fields
	std::vector<int> k;
	std::string pathFrom;
	std::string pathTo;
public:
	// methods
	ParametersReader();
	~ParametersReader();
	// parsing
	void parsing(int argc, char** argv);
	// returning
	std::vector<int> getVector();
	std::string getPath();

	// exceptions
	class Invalid{};
	class Empty{};
};

