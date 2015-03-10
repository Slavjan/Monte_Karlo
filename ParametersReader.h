#pragma once
#include <vector>
#include <iostream>
#include <string>

using std::string;

class ParametersReader
{
private:  
	// fields
	int argc;
	char** argv;

public:
	// methods
	ParametersReader(int _argc, char** _argv);
	~ParametersReader();
	
		// finding 
	string findString(string opt);
	std::vector<int> findVector(string opt);

	// exceptions
	class Invalid{};
	class Empty{};
};