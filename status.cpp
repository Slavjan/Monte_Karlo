#pragma once
#include "status.h"

void status(int now, int end, std::string ProcedureName)
{
	std::string str = "|";

	const int TERM_WIDTH = 40;

	int procent = 100 * (float)((float)now / end);

	for (int i = 0; i < procent; i++)
	{
		str += '/';
	}
	str += '|';

	std::cout.width(TERM_WIDTH-procent);
	std::cout << ProcedureName.data() << " | " << str.data() << ">" << procent << "%" << std::endl << std::endl;
}