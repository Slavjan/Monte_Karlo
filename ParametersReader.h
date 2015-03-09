#pragma once
#include <vector>
#include <iostream>



class ParametersReader
{
private:  
	// fields
	std::vector<int> coords;
	std::string pathFrom;
	std::string pathTo;

	//find options
	std::string findInputPath(int argc, char** argv);
	std::string findOutputPath(int argc, char** argv);
	std::string findEnteredCoords(int argc, char** argv);

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

