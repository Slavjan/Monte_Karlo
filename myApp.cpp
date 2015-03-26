#pragma once
#include "myApp.h"
#include "status.h"


// public
myApp::myApp(int _argc, char** _argv)
{
	argc = _argc;
	argv = _argv;
	source = nullptr;
	argument = nullptr;
}

myApp::~myApp()
{
	delete[] source;
	delete[] argument;
}

bool myApp::init()
{
	bool ex;
	ex = loadShape();

	if (!ex)
		return ex;

	generateControlShape();
	generatePontsSet();

	return true;
}

bool myApp::calculate()
{
	float mSpace = 0; // middle space
	int traces;
	grn r; 
	traces = r.getInRange(10, controlSpace);
	for (int i = 0; i < traces; i++)
	{
		mSpace += getSpace();
		status(i-1, traces, "myApp::calculate");
	}
	Space = mSpace / traces;
	status(traces, traces, "myApp::calculate");

	return true;
}

void myApp::returning()
{
	if (writeFlag)
		saveToFile();
	else printToConsole();
}

void myApp::saveToFile()
{
	try
	{					   
		source->saveToFile("Space.out", ""+ Space);		   
	}
	catch (PiPFormat::wasntSave)
	{
		std::cout << "Saving fail!" << std::endl;
	}
}

void myApp::printToConsole()
{
	std::cout << Space << std::endl;
}

// /public
// proeced

bool myApp::loadShape()
{
	bool ex;

	ex = readParams();

	if (readFlag)
	{
		ex = readFile(pathIn);
		if (!ex) return	ex;
		setShape(source->getVector().data());
	}
	else return ex;

	return true;
}

bool myApp::readFile(std::string path)
{
	source = new PiPFormat();
	try
	{
		source->loadFromFile(path);
	}
	catch (PiPFormat::notFound)
	{
		std::cout << "The file is not found" << std::endl;
		return false;
	}
	return true;
}

bool myApp::readParams()
{
	argument = new ParametersReader(argc, argv);

	try
	{
		pathOut = argument->findString("-o");
		writeFlag = true;
	}
	catch (ParametersReader::Empty)
	{
		writeFlag = false;
	}

	try
	{
		pathIn = argument->findString("-i");
		readFlag = true;
	}
	catch (ParametersReader::Empty)
	{
		readFlag = false;
		try
		{
			std::vector<Point> p;
			std::vector<int> _p;
			_p = argument->findVector("-p");
			for (int i = 0; i < _p.size(); i += 2)
			{
				status(i, _p.size(), "vector to Point");
				p.push_back(Point(_p.at(i), _p.at(i + 1)));
			}
			setShape(p);
		}
		catch (ParametersReader::Empty)
		{
			std::cout << "-p is empty" << std::endl;
			return false;
		}
		catch (ParametersReader::Invalid)
		{
			std::cout << "-p is invailid" << std::endl;
			return false;
		}
	}
	return true;
}

// /proteced