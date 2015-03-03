#include <stdio.h>	
#include "grn.h"
#include <time.h>	
#include <iostream>
#include <vector>

using namespace std;
							  
int main(int argc, char** argv)
{
	//time_t t = clock();
	
	vector <int> k;

//	cout << argc <<"  " << argc % 2 << endl;

	if (argc == 1)
		cout << "parameters wasn`t entering" << endl;
	else if (argc % 2 == 0)
		cout << "invalid parameters count" << endl;
	else{		
		for (int i = 1; i < argc; i += 2)
		{
			string  opt = string(argv[i]);
			if (opt == "--f")
			{
				string path = string(argv[i + 1]);
				cout << "reading from file : " << path.data() << endl;
				i++;
			}
			else{

				k.push_back(atoi(argv[i]));
				k.push_back(atoi(argv[i + 1]));
			}
		}
		for (int i = 0; i < k.size(); i += 2)
		{
			cout << "x: " << k[i] << "y: " << k[i + 1] << endl;
		}

		
	}
//	cout << clock() << endl;
//	grn a;	
	
	//cout << "random: " << a.random() << "| MMM: " << a.MMM() << "| MMS: " << a.MMS() << "| generate: " << a.generate() << endl;
	//for (int i = 0; i < 10; i++)
	//{
	//	//("MMM: %i\tMMS: %i\n", a.MMM(), a.MMS());///, rcount: %i
	//}

#ifdef _MSC_VER	
	system("pause");
#endif
	return 0;
}

