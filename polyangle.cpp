#pragma once
#include "polyangle.h"
#include "stdafx.h"
#include "status.h"

// pablic
Polyangle::Polyangle(Edge* a, int count)
{
	edge = nullptr;
	edge = new Edge[count];
	int j = 0;
	for (int i = 0; i < count; i++)
	{
		status(i, count, "polyangle::Polyangle()");
		edge[i].setPoints(a[i].getDot(0), a[i].getDot(1));
		edge[i].calculateAngle();
	}
	
	verticesCount = count * 2;
	extremumCoord();
} 

Polyangle::Polyangle(Point* points, int count)
{
	edge = nullptr;
	edge = new Edge[count];
	int j = 0;
	for (int i = 0; i < count; i++)
	{
		status(i, count, "polyangle::Polyangle()");
		edge[i].setPoints(points[i], points[i + 1]);
		edge[i].calculateAngle();
	}

	verticesCount = count;
	extremumCoord();
}

Polyangle::~Polyangle()
{
	delete[] edge;
}  

bool Polyangle::inside(Point p)
{					  
	// isntShape();
	return collisions(p) % 2 == 0 ? false : true;
}

bool Polyangle::inside(int x, int y)
{
	// isntShape();
	return collisions(x, y) % 2 == 0 ? false : true;
}

void Polyangle::print(){
	std::cout << "Polyangle. Edges:" << std::endl;
	for (size_t i = 0; i < verticesCount; i++)
	{
		std::cout << edge[i].getB() << ", " << edge[i].getK() << std::endl;
	}
	std::cout << std::endl;
}

Edge* Polyangle::getEdges()
{
	return edge;
}

int Polyangle::getVerticesCount()
{
	return verticesCount;
}

int Polyangle::getMaxX()
{
	return maxX;
}
int Polyangle::getMaxY()
{
	return maxY;
}
int Polyangle::getMinX()
{
	return minX;
}
int Polyangle::getMinY()
{
	return minY;
}

// /public

// private 
void Polyangle::extremumCoord()
{
	maxX = 0;
	maxY = 0;
	minX = 0;
	minY = 0;

	for (int i = 0; i < verticesCount/2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			
			maxX = maxNumber(edge[i].getDotX(j), maxX);
			maxY = maxNumber(edge[i].getDotY(j), maxY);

			minX = minNumber(edge[i].getDotX(j), minX);
			minY = minNumber(edge[i].getDotY(j), minY);
			status(i + 1 * j, verticesCount, "polyangle::Polyangle()");
		}
	}
}

int Polyangle::collisions(Point p)
{
	int collisions_count = 0;

	for (int i = 0; i < verticesCount / 2; i++)
	{
		if (edge[i].collision(p))
		{
			collisions_count++;
		}
		status(i, verticesCount/2, "polyangle::collisions");
	}

	return collisions_count;
}

int Polyangle::collisions(int x, int y)
{
	int collisions_count = 0;
	Point p = Point(x, y);

	for (int i = 0; i < verticesCount / 2; i++)
	{
		if (edge[i].collision(p))
		{
			collisions_count++;
		}
		status(i, verticesCount / 2, "polyangle::collisions");
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

	for (int i = 0; i < verticesCount-1; i++)
	{
		x1 = edge[i].getDotX(0);
		x2 = edge[i].getDotX(1);
		x3 = edge[i + 1].getDotX(0);

		y1 = edge[i].getDotY(0);
		y2 = edge[i].getDotY(1);
		y3 = edge[i+1].getDotY(0);


		int raznostX1X3 = x1 - x3,
			raznostX2X3 = x2 - x3,
			raznostY1Y3 = y1 - y3,
			raznostY2Y3 = y2 - y3;

		if (raznostX2X3 == 0 || raznostY2Y3 == 0)
		{
			dx = 0;
			dy = 1;
		}
		else
		{
			dx = raznostX1X3 / raznostX2X3;
			dy = raznostY1Y3 / raznostY2Y3;
		}

		
		if (dx == dy)
			zeros++;

		status(i, verticesCount, "polyangle::isntShape");
	}
	if (zeros == verticesCount)
	{
		throw isLine();
	}
}

// /private