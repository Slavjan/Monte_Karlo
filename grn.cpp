#include "grn.h"
//#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
//#include <cmath>

//public

grn::grn()
{
	this->f_rNumber = nullptr;
}

grn::~grn()
{
	delete this->f_rNumber;
}

void grn::set(int count = 1, int number = 0)
{
	/*if (number == 0)
		this->i_number = rand();
		this->i_number = random();
		this->f_rNumber = randomize();*/
}



//private
void grn::setCount(int c)
{
	this->i_count = c;
}

void grn::setNumber(int n)
{
	this->i_number = n;
}

int grn::random()
{
	return 1111 + rand() % (9999 - 1111 + 1);
}