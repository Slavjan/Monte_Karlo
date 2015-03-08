#include "polyangle.h"
#include "stdafx.h"
// pablic
Polyangle::Polyangle(Edge* a, int count)
{
	E_line = nullptr;
	E_line = new Edge[count];
	int j = 0;
	for (int i = 0; i < count; i++)
	{
		E_line[i].setPoints(a[i].getDot(0), a[i].getDot(1));
		E_line[i].calculateAngle();
	}
	isntShape();

	i_verticesCount = count * 2;
} 

Polyangle::Polyangle(Point* points, int count)
{
	E_line = nullptr;
	E_line = new Edge[count];
	int j = 0;
	for (int i = 0; i < count; i++)
	{
		E_line[i].setPoints(points[i], points[i + 1]);
		E_line[i].calculateAngle();
	}
	isntShape();

	i_verticesCount = count * 2;
}

Polyangle::~Polyangle()
{
	if (E_line)
	{
		delete[] E_line;
	}
}  

bool Polyangle::inside(Point p)
{
	return collisions(p) % 2 == 0 ? false : true;
}

bool Polyangle::inside(int x, int y)
{
    return collisions(x, y) % 2 == 0 ? false : true;
}

void Polyangle::print(){
	std::cout << "Polyangle. Edges:" << std::endl;
	for (size_t i = 0; i < i_verticesCount; i++)
	{
		std::cout << E_line[i].getB() << ", " << E_line[i].getK() << std::endl;
	}
	std::cout << std::endl;
}

Edge* Polyangle::getEdges()
{
	return E_line;
}

int Polyangle::getVerticesCount()
{
	return i_verticesCount;
}
// /public

// private 
void Polyangle::maxCoord()
{
	i_maxX = 0;
	i_maxY = 0;

	for (int i = 0; i < i_verticesCount; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			i_maxX = maxNamber(E_line[i].getDotX(j), i_maxX);
			i_maxY = maxNamber(E_line[i].getDotY(j), i_maxY);
		}
	}
}

int Polyangle::collisions(Point p)
{
	int collisions_count = 0;

	for (int i = 0; i < i_verticesCount / 2; i++)
	{
		if (E_line[i].collision(p))
		{
			collisions_count++;
		}
	}

	return collisions_count;
}

int Polyangle::collisions(int x, int y)
{
	int collisions_count = 0;
	Point *p = new Point(x, y);

	for (int i = 0; i < i_verticesCount / 2; i++)
	{
		if (E_line[i].collision(p))
		{
			collisions_count++;
		}
	}

	return collisions_count;
}	

void Polyangle::isntShape()
{
	/*
		Take three point and calculate the space, if it equal 0 - this isn`t shape, it is line.

		x1 - x3		y1 - y3
		________ = ___________
		x2 - x3 	y2 - y3
	*/
	int zeros = 0;
	int x1, x2, x3,
		y1, y2, y3;
	float dx, dy;

	for (int i = 0; i < i_verticesCount; i++)
	{
		x1 = E_line[i].getDotX(0);
		x2 = E_line[i].getDotX(1);
		x3 = E_line[i + 1].getDotX(0);

		y1 = E_line[i].getDotY(0);
		y2 = E_line[i].getDotY(1);
		y3 = E_line[i+1].getDotY(0);

		dx = (x1 - x3) / (x2 - x3);
		dy = (y1 - y3) / (y2 - y3);
		if (dx == dy)
			zeros++;
	}
	if (zeros == i_verticesCount)
	{
		throw isLine();
		return;
	}
}

// /private