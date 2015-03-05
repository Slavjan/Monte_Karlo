#include "stdafx.h"
#include "polyangle.h"
#include "pipformat.h"

using namespace std;
int main(int argc, char** argv)
{
    std::string inFile = "File.in";
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
	// A, B, C, D;
	Edge line[3];
	
	/*A.x = 1;
	A.y = 2;
	B.x = 4;
	B.y = 2;*/

	Point C;
		  C.x = 2;
		  C.y = 3;

	line[0].setPoints(2, 4, 1, 4);
	line[0].calculateAngle();
	line[1].setPoints(4, 4, 4, 3);
	line[1].calculateAngle();
	line[2].setPoints(4, 2, 3, 1);
	line[2].calculateAngle();
	
	
	Polyangle a(line);

	char s[1]; 
	if (a.inside(C))
	{
		s[0] = 't';
	}
	else
	{
		s[0] = 'f';
	}

	cout << s[0] << endl;

	
#ifdef _MSC_VER
	system("pause");
#endif

	return 0;
}