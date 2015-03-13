#include "stdafx.h"
#include "myApp.h"


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


