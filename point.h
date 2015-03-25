#pragma once



#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "stdafx.h"

class Point
{
public:
	int x;
	int y;

	Point(int x = 0, int y = 0);
	~Point();

	void print();

//	int vector();
};
#endif
