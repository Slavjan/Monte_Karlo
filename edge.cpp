#include "edge.h"


Edge::Edge()
{
	P_dot = NULL;
				  
	b_horizontal = 0;
	b_vertical = 0;
}


Edge::~Edge()
{
	if (P_dot)
	{
		delete[] P_dot;
	}
}

// initing 

void Edge::setPoints(Point A, Point B)
{
	P_dot = new Point[2];

	P_dot[0].x = A.x; P_dot[0].y = A.y;
	P_dot[1].x = B.x; P_dot[1].y = B.y;
}

void Edge::setPoints(Point* A, Point* B)
{
	P_dot = new Point[2];
	
	P_dot[0].x = A[0].x; P_dot[0].y = A[0].y;
	P_dot[1].x = B[0].x; P_dot[1].y = B[0].y;
}

void Edge::setPoints(int x1, int x2, int y1, int y2)
{
	P_dot = new Point[2];
	
	P_dot[0].x = x1; P_dot[0].y = y1;
	P_dot[1].x = x2; P_dot[1].y = y2;
}

// getting fields

Point Edge::getDot(int n)
{
	return P_dot[n];
}

int Edge::getDotX(int dot)
{
	return P_dot[dot].x;
}

int Edge::getDotY(int dot)
{
	return P_dot[dot].y;
}

int Edge::getK()
{
	return i_k;
}
int Edge::getB()
{
	return i_b;
}

bool Edge::getHorizont()
{
	return b_horizontal;
}

bool Edge::getVertical()
{
	return b_vertical;
}

// calculations
void Edge::calculateAngle()
{
	/*
	k = (1)(p2.y - p1.y) / (2)(p2.x - p1.x)

	(1)	= 0 -> goriz = 1;
	(2) = 0	-> vertical = 1;
	*/

	int dx, dy;

	dx = P_dot[1].x - P_dot[0].x;
	dy = P_dot[1].y - P_dot[0].y;

	if (dx == 0)
	{
		b_vertical = true;
		b_horizontal = false;
		i_b = 0;
	}
	else if (dy == 0)
	{
		b_horizontal = true;
		b_vertical = false;
		i_k = 0;
		i_b = P_dot[0].y;
	}
	else
	{
		i_k = dy / dx;
		i_b = P_dot[0].y - i_k*P_dot[0].x;
	}
}

bool Edge::collision(Point p)
{
	if (b_horizontal)
	{
		if (
			p.x <= maxNamber(P_dot[0].x, P_dot[1].x) && 
			p.x >= minNamber(P_dot[0].x, P_dot[1].x)
		   )
		{
			int y0 = i_k * p.x + i_b;
			return y0 >= p.y ? true : false;
		}
		else return false;
	}
	else if (b_vertical)
	{
		if (
			p.y <= maxNamber(P_dot[0].y, P_dot[1].y) &&
			p.y >= minNamber(P_dot[0].y, P_dot[1].y)
		   )
		{
			return P_dot[0].x >= p.x ? true : false;
		}
		else return false;
	}
	else
	{
		int x0,
			y0;

		if (
			(
			 p.y <= maxNamber(P_dot[0].y, P_dot[1].y)  &&
			 p.y >= minNamber(P_dot[0].y, P_dot[1].y)
			) 
			||
			(
			 (
			  p.x <= maxNamber(P_dot[0].x, P_dot[1].x) &&
			  p.x >= minNamber(P_dot[0].x, P_dot[1].x)
			 )
		    )
		   )
		{ 
		
			x0 = (p.y - i_b) / i_k;
			y0 = i_k * p.x + i_b;
			
			return x0 >= p.x || y0 >= p.y ? true : false;
		}
		else return false;
	}

	return false;
}

bool Edge::collision(Point* p)
{
	return false;
}