#pragma once
#include "edge.h"
#include "stdafx.h"
// public
Edge::Edge()
{
	dot = NULL;
				  
	horizontal = 0;
	vertical = 0;
}


Edge::~Edge()
{
	if (dot)
	{
		delete[] dot;
	}
}

	// settings 

void Edge::setPoints(Point A, Point B)
{
	dot = new Point[2];

	dot[0].x = A.x; dot[0].y = A.y;
	dot[1].x = B.x; dot[1].y = B.y;
}

void Edge::setPoints(Point* A, Point* B)
{
	dot = new Point[2];
	
	dot[0].x = A[0].x; dot[0].y = A[0].y;
	dot[1].x = B[0].x; dot[1].y = B[0].y;
}

void Edge::setPoints(int x1, int x2, int y1, int y2)
{
	dot = new Point[2];
	
	dot[0].x = x1; dot[0].y = y1;
	dot[1].x = x2; dot[1].y = y2;
}

	// /settings
	// getting

Point Edge::getDot(int n)
{
	return dot[n];
}

int Edge::getDotX(int _dot)
{
	return dot[_dot].x;
}

int Edge::getDotY(int _dot)
{
	return dot[_dot].y;
}

int Edge::getK()
{
	return k;
}
int Edge::getB()
{
	return b;
}

bool Edge::getHorizont()
{
	return horizontal;
}

bool Edge::getVertical()
{
	return vertical;
}

	// /getting
	// calculations
void Edge::calculateAngle()
{
	/*
	k = (1)(p2.y - p1.y) / (2)(p2.x - p1.x)

	(1)	= 0 -> goriz = 1;
	(2) = 0	-> vertical = 1;
	*/

	int dx, dy;

	dx = dot[1].x - dot[0].x;
	dy = dot[1].y - dot[0].y;

	if (dx == 0)
	{
		vertical = true;
		horizontal = false;
		b = 0;
	}
	else if (dy == 0)
	{
		horizontal = true;
		vertical = false;
		k = 0;
		b = dot[0].y;
	}
	else
	{
		k = dy / dx;
		b = dot[0].y - k*dot[0].x;
	}
}

bool Edge::collision(Point p)
{
	if (horizontal)
	{
		if (
			p.x <= maxNumber(dot[0].x, dot[1].x) && 
			p.x >= minNumber(dot[0].x, dot[1].x)
		   )
		{
			int y0 = k * p.x + b;
			return y0 >= p.y ? true : false;
		}
		else return false;
	}
	else if (vertical)
	{
		if (
			p.y <= maxNumber(dot[0].y, dot[1].y) &&
			p.y >= minNumber(dot[0].y, dot[1].y)
		   )
		{
			return dot[0].x >= p.x ? true : false;
		}
		else return false;
	}
	else
	{
		int x0,
			y0;

		if (
			(
			 p.y <= maxNumber(dot[0].y, dot[1].y)  &&
			 p.y >= minNumber(dot[0].y, dot[1].y)
			) 
			||
			(
			 (
			  p.x <= maxNumber(dot[0].x, dot[1].x) &&
			  p.x >= minNumber(dot[0].x, dot[1].x)
			 )
		    )
		   )
		{ 
		
			x0 = (p.y - b) / k;
			y0 = k * p.x + b;
			
			return x0 >= p.x || y0 >= p.y ? true : false;
		}
		else return false;
	}

	return false;
}

	// /calculations
// /public