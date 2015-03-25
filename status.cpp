#pragma once
#include "status.h"

void status(int now, int end, std::string ProcedureName)
{
	std::string str = "|";

	int procent = 100 * (float)((float)now / end);

	for (int i = 0; i < procent; i++)
	{
		str += '/';
	}
	str += '|';

	std::cout << ProcedureName.data() << " | " << str.data() << ">" << procent << "%" << std::endl << std::endl;
}