#include <stdio.h>	
#include "grn.h"
#include <time.h>	
#include <iostream>

using namespace std;

							  
int main(int argc, char** argv)
{
	//time_t t = clock();
	
//	cout << clock() << endl;
	grn a;	
	
	cout << "random: " << a.random() << "| MMM: " << a.MMM() << "| MMS: " << a.MMS() << "| generate: " << a.generate() << endl;
	//for (int i = 0; i < 10; i++)
	//{
	//	//("MMM: %i\tMMS: %i\n", a.MMM(), a.MMS());///, rcount: %i
	//}
#ifdef _MSC_VER	
	system("pause");
#endif
	return 0;
}

