#pragma once

#include "polyangle.h"
#include "pipformat.h"
#include "ParametersReader.h"
#include "MonteKarloApp.h"


class myApp : MonteKarloApp
{
protected:
	// fields
	PiPFormat*	source;
	ParametersReader* argument;
	std::string pathOut;
	std::string pathIn;
	bool readFlag;
	bool writeFlag;
	int	argc;
	char**	argv;
	//method
	bool readFile(std::string path) override;
	bool readParams() override;
	bool loadShape() override;

	void saveToFile();
	void printToConsole();

public:
	myApp(int _argc, char** _argv);
	~myApp();

	// methods
	bool init();
	bool calculate();
	void returning();

	
};