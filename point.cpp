#include "point.h"


Point::Point(int x, int y)
{
	this->x = x != 0 ? x : 0;
	this->y = y != 0 ? y : 0;
}


Point::~Point()
{
}

void Point::print(){
    std::cout << "Point(" << x << "," << y << ")";
}
