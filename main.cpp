#pragma once
#include "stdafx.h"
#include "polyangle.h"
#include "pipformat.h"

//using namespace std;
int main(int argc, char** argv)
{
    std::string inFile = "File.in";
	if( argc > 1 ){
        inFile = argv[1];
    }
	PiPFormat file;
	try{
		file.loadFromFile(inFile);
	}
	catch (PiPFormat::notFound)
	{
		std::cout << "file is not found" << std::endl;
	}

	Polyangle *shape = new Polyangle(file.getVector().data(), file.getVector().size());
	Point *dot = new Point(file.getCrossPoint());
	bool in = shape[0].inside(*dot);

	if (in)
		std::cout << "true";
	else std::cout << "false";

	// A, B, C, D;
	//Edge line[3];
	
	/*A.x = 1;
	A.y = 2;
	B.x = 4;
	B.y = 2;*/

	//Point C;
	//	  C.x = 2;
	//	  C.y = 3;

	//line[0].setPoints(2, 4, 1, 4);
	//line[0].calculateAngle();
	//line[1].setPoints(4, 4, 4, 3);
	//line[1].calculateAngle();
	//line[2].setPoints(4, 2, 3, 1);
	//line[2].calculateAngle();
	//
	//
	//Polyangle a(line);

	/*char s[1]; 
	if (a.prenadleznost(C))
	{
		s[0] = 't';
	}
	else
	{
		s[0] = 'f';
	}

	cout << s[0] << endl;
*/
	
#ifdef _MSC_VER
	system("pause");
#endif

	return 0;
}
