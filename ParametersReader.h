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

	//find options
	std::string findInputPath();
	std::string findOutputPath();
	std::string findEnteredCoords();

public:
	// methods
	ParametersReader();
	~ParametersReader();
	// parsing
	void parsing(int argc, char** argv);
	// returning
	std::vector<int> getVector();
	std::string getPathFrom();
	std::string getPathTo();

	// exceptions
	class Invalid{};
	class Empty{};
};

