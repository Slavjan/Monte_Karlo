#ifndef POINT_H
#define POINT_H
#include <iostream>

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
#endif // POINT_H
