#include "stdafx.h"
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
public:
	myApp(int _argc, char** _argv);
	~myApp();

	// methods
	bool loadShape() override;
	bool readFile(std::string path) override;
	bool readParams() override;

	void saveToFile();
};

int main(int argc, char** argv)
{
   /* std::string inFile = "File.in";
    std::string outFile = "File.out";
    if( argc > 1 ){
        inFile = argv[1];
        if(argc > 2){
            outFile = argv[2];
        }
    }
    PiPFormat file;
	Polyangle *shape;
	try{
		file.loadFromFile(inFile);
		file.print();
		file.saveToFile(outFile);
		shape = new Polyangle(file.getVector().data(), file.getVector().size());
	}
	catch (PiPFormat::notFound)
	{
		cout << "File is not found!" << endl << "//-----------------------------" << endl;
	}
	catch (PiPFormat::wasntSave)
	{
		cout << "File wasn`t save!" << endl << "//-----------------------------" << endl;
	}
	catch (Polyangle::isLine)
	{
		cout << "Shape is been line" << endl << "//-----------------------------" << endl;
	}
	*/

	
#ifdef _MSC_VER // if compiling in the MS Visual Studio
	system("pause");
#endif

	return 0;
}


// Imlement of the class myApp
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
		}
		catch (ParametersReader::Invalid)
		{
			std::cout << "-p is invailid";
		}
	}			
}