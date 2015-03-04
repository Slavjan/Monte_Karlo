#include "polyangle.h"
#include "stdafx.h"

Polyangle::Polyangle(Edge* a, int count)
{
	E_line = NULL;
	E_line = new Edge[count];
	for (int i = 0; i < count; i++)
	{
		E_line[i].setPoints(a[i].getDot(0), a[i].getDot(1));
		E_line[i].calculateAngle();
	}

	i_verticesCount = count * 2;
} 

Polyangle::Polyangle(Point* points, int count)
{
	E_line = NULL;
	E_line = new Edge[count];
	for (int i = 0; i < count; i++)
	{
		E_line[i].setPoints(points[i], points[i + 1]);
		E_line[i].calculateAngle();
	}

	i_verticesCount = count * 2;
}

Polyangle::~Polyangle()
{
	if (E_line)
	{
		delete[] E_line;
	}
} 

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
	
	for (int i = 0; i < i_verticesCount/2; i++)
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

bool Polyangle::inside(Point p)
{
	return collisions(p) % 2 == 0 ? false : true;
}

bool Polyangle::inside(int x, int y)
{
    return collisions(x, y) % 2 == 0 ? false : true;
}
