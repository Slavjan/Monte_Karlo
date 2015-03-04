#include <stdio.h>	
#include "grn.h"
#include <time.h>	
#include <iostream>
#include <vector>
#include "ParametersReader.h"

using namespace std;
							  
int main(int argc, char** argv)
{
	ParametersReader r;
	r.parsing(argc, argv);/*
	r.getPath();*/


#ifdef _MSC_VER	
	system("pause");
#endif
	return 0;
}

