#pragma once
#include <vector>
#include <iostream>



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
	std::string findString(std::string opt);
	std::vector<int> findVector(std::string opt);

	// exceptions
	class Invalid{};
	class Empty{};
};