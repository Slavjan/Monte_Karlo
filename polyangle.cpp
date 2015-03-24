#pragma once
#include "polyangle.h"
#include "stdafx.h"
// pablic
Polyangle::Polyangle(Edge* a, int count)
{
	edge = nullptr;
	edge = new Edge[count];
	int j = 0;
	for (int i = 0; i < count; i++)
	{
		edge[i].setPoints(a[i].getDot(0), a[i].getDot(1));
		edge[i].calculateAngle();
	}

	verticesCount = count * 2;
} 

Polyangle::Polyangle(Point* points, int count)
{
	edge = nullptr;
	edge = new Edge[count];
	int j = 0;
	for (int i = 0; i < count; i++)
	{
		edge[i].setPoints(points[i], points[i + 1]);
		edge[i].calculateAngle();
	}

	verticesCount = count * 2;
}

Polyangle::~Polyangle()
{
	delete[] edge;
}  

bool Polyangle::inside(Point p)
{					  
	isntShape();
	return collisions(p) % 2 == 0 ? false : true;
}

bool Polyangle::inside(int x, int y)
{
	isntShape();
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
// /public

// private 
void Polyangle::maxCoord()
{
	maxX = 0;
	maxY = 0;

	for (int i = 0; i < verticesCount; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			maxX = maxNumber(edge[i].getDotX(j), maxX);
			maxY = maxNumber(edge[i].getDotY(j), maxY);
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

	for (int i = 0; i < verticesCount; i++)
	{
		x1 = edge[i].getDotX(0);
		x2 = edge[i].getDotX(1);
		x3 = edge[i + 1].getDotX(0);

		y1 = edge[i].getDotY(0);
		y2 = edge[i].getDotY(1);
		y3 = edge[i+1].getDotY(0);

		dx = (x1 - x3) / (x2 - x3);
		dy = (y1 - y3) / (y2 - y3);
		if (dx == dy)
			zeros++;
	}
	if (zeros == verticesCount)
	{
		throw isLine();
		return;
	}
}

// /private