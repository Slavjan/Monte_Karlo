#include "grn.h"
//#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
//#include <cmath>

//public

grn::grn()
{
	this->f_rNumber = nullptr;
	this->i_number = 0;
}

grn::~grn()
{
	delete[] this->f_rNumber;
}

void grn::set(int count = 1, int number = 0)
{
	if (number == 0)
		this->i_number = random();
	else if (number >= 1000)
		this->i_number = number;

	this->i_count = count;
}

//float grn::generate()
//{
//	float f_rNumber;
//
//	for (int i = 0; i < i_count > 1 ? i_count + 10:(int)(random()/100); i++)
//	{
//
//	}
//		  
//}
//private
void grn::setCount(int c)
{
	this->i_count = c;
}

void grn::setNumber(int n)
{
	this->i_number = n;
}

int grn::midExtract(unsigned long int n)
{
	unsigned long int c = n,
					  divider = 10;
	int				  middle = 0,
					  count = 0 ;
	
	do
	{
		c /= 10;
		count++;
	} while (c > 0);


	if ((((count - 4) / 2) - 1) < 0)
		count = (((count - 4) / 2) - 1) * -1;
	else
		count = ((count - 4) / 2) - 1 ;

	for (int i = 0; i < count; i++)
	{
		divider *= 10;
	}
	middle = (n / divider) % 10000;
	return middle;	
}

int grn::random(int n1, int n2)
{
	int i = 0;

	if (n1 == 0 && n2 == 0)// if a range isn`t setted 
	{					   // calculate the four-digit numbers
		n1 = 1111;
		n2 = 9999;
	}
	
	i = n1 + rand() % (n2 - n1 + 1);
	
	return i;
}

int grn::MMM() // set dddd, dddd*cccc = ddmmmmdd, mmmm is middle of multiplication 
{
	int i_fnumber,//first number dddd
		i_snumber,//second number cccc
		i_mm = 0; //mid of multiplication
	
	i_fnumber = this->i_number;	//dddd
	i_snumber = random();		//cccc

	for (int i = 0; i < 20; i++)// for mutcher range
	{
		i_mm = midExtract(i_fnumber * i_snumber);
		i_fnumber = i_mm;
		if (i_mm == 0)
		{
			i_fnumber = random();
			i--;
		}

	}

	return i_mm;
}

int grn::MMS() // set dddd, sqr(dddd) = ddmmmmdd, mmmm is middle of square
{
	int i_fnumber,//first number dddd
		i_ms = 0; //mid of square

	i_fnumber = this->i_number;	//dddd

	for (int i = 0; i < 25; i++)
	{
		i_ms = midExtract(i_fnumber*i_fnumber);
		i_fnumber = i_ms;
	}

	return i_ms;
}