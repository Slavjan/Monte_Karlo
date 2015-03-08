#include "Application.h"

// publice
Application::Application()
{
	Space = 0;
	testing = nullptr;
	control = nullptr;
}


Application::~Application()
{
	delete[] testing;
	delete[] control;
}



// /public

// private
void Application::generateControlShape()
{	// calcelate the coordinates for control Shape
	int maxX = 0, maxY = 0;
	int minX = 0, minY = 0;

	for (int i = 0; i < testing->getVerticesCount(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			maxX = maxNumber(testing->getEdges()[i].getDotX(j), maxX);
			maxY = maxNumber(testing->getEdges()[i].getDotY(j), maxY);

			minX = minNumber(testing->getEdges()[i].getDotX(j), maxX);
			minY = minNumber(testing->getEdges()[i].getDotY(j), maxY);
		}
	}
	// creating a new shape - the control shape
		// create an edges for polygon
	Edge* edge = new Edge [4];
	
	edge[0].setPoints(minX, minX, minY, maxY);
	edge[1].setPoints(minX, maxX, maxY, maxY);
	edge[2].setPoints(maxX, minX, maxY, minY);
	edge[3].setPoints(maxX, minY, minX, minY);
											  
		// create the polygle
	control = new Polyangle(edge, 4);
	
	// calculate the conrolSpace
	int dx = maxX - minX;
	int dy = maxY - minY;

	controlSpace = dx * dy;
}

void Application::generatePontsSet()
{
	Point p;
	for (int i = 0; i < controlSpace * 2 / 3; i++)
	{
		p.x = m_rundom->generate();
		p.y = m_rundom->generate();
		pointSet.push_back(p);
	}
	pointSet.pop_back();
}
// /private