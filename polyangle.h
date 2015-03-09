#pragma once
#include "edge.h"

class Polyangle
{
private:
	// private fields
	Edge*	edge;
	int		verticesCount;
	int		maxX;
	int		maxY;

	// private mathods
	void	maxCoord();
	int		collisions(Point);
	int		collisions(int, int);

	void	isntShape();// if the points belongs to line, she shalln`t goting area

public:
	// publuc methods
	Polyangle(Edge* a, int count = 3);
	Polyangle(Point* points, int count = 3);  

	~Polyangle();
		// calculations						  	
	bool	inside(Point);
	bool	inside(int, int);

	// returning
	Edge*	getEdges();
	int		getVerticesCount();

	void print();

	// exceptions
	class isLine{};
};