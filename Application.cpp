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

// protected
std::vector<int> Application::calculateExtremumCoords(Polyangle *shape)
{
	int maxX = 0, maxY = 0;
	int minX = 0, minY = 0;

	std::vector<int> Extremum;

	for (int i = 0; i < shape->getVerticesCount()/2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			maxX = maxNumber(shape->getEdges()[i].getDotX(j), maxX);
			maxY = maxNumber(shape->getEdges()[i].getDotY(j), maxY);
							 
			minX = minNumber(shape->getEdges()[i].getDotX(j), maxX);
			minY = minNumber(shape->getEdges()[i].getDotY(j), maxY);
		}
	}

	Extremum.push_back(maxX);
	Extremum.push_back(maxY);
	Extremum.push_back(minX);
	Extremum.push_back(minY);
	Extremum.pop_back();

	return Extremum;
}

void Application::generateControlShape()
{	// calcelate the coordinates for control Shape
	std::vector<int> tExtremum = calculateExtremumCoords(testing);
	int maxX = tExtremum.at(0), 
		maxY = tExtremum.at(1);
	int minX = tExtremum.at(2), 
		minY = tExtremum.at(3);
	
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
	std::vector<int> tExtremum = calculateExtremumCoords(testing);
	int maxX = tExtremum.at(0),
		maxY = tExtremum.at(1);
	int minX = tExtremum.at(2),
		minY = tExtremum.at(3);


	for (int i = 0; i < controlSpace * 2 / 3; i++)
	{
		p.x = m_rundom->genInRange(minX, maxX);
		p.y = m_rundom->genInRange(minY, maxY); 
		pointSet.push_back(p);
	}
	pointSet.pop_back();
}

int Application::calculateAmountPointsInShape(Polyangle *polygon)
{
	int count = 0;

	for (int i = 0; i < pointSet.size(); i++)
	{
		if (polygon->inside(pointSet.data()[i]))
			count++;
	}

	return count;
}				

int Application::calculateSpase()
{
	int p_i_cShape, // amount of points in control Shape
		p_i_tShape;	// amount of Points In testing Shape

	p_i_cShape = calculateAmountPointsInShape(control);
	p_i_tShape = calculateAmountPointsInShape(testing);

	float ratio = p_i_tShape / p_i_cShape;
	int space = ratio * controlSpace;

	return space;
}
// /protected