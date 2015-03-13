#include "myApp.h"
// public
myApp::myApp(int _argc, char** _argv)
{
	source = nullptr;
	argument = nullptr;
}

myApp::~myApp()
{
	delete[] source;
	delete[] argument;
}

// /public
// proeced

bool myApp::readFile(std::string path)
{
	source = new PiPFormat();
	try
	{
		source->loadFromFile(path);
	}
	catch (PiPFormat::notFound)
	{
		std::cout << "The file is not found";
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
			setShape(argument->findVector("-p").data);
		}
		catch (ParametersReader::Empty)
		{
			std::cout << "-p is empty";
			return false;
		}
		catch (ParametersReader::Invalid)
		{
			std::cout << "-p is invailid";
			return false;
		}
	}
	return true;
}

// /proteced