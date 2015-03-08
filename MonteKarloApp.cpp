#include "MonteKarloApp.h"

// publice
MonteKarloApp::MonteKarloApp()
{
	Space = 0;
	testing = nullptr;
	control = nullptr;
}


MonteKarloApp::~MonteKarloApp()
{
	delete[] testing;
	delete[] control;
}

void MonteKarloApp::setShape(std::vector<Point> dots)
{
	testing = new Polyangle(dots.data(), dots.size());
}

void MonteKarloApp::setShape(Polyangle *shape)
{
	testing = new Polyangle(*shape);
}

void MonteKarloApp::setShape(Polyangle shape)
{
	testing = new Polyangle(shape);
}


// /public

// protected
std::vector<int> MonteKarloApp::calculateExtremumCoords(Polyangle *shape)
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

void MonteKarloApp::generateControlShape()
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

void MonteKarloApp::generatePontsSet()
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

int MonteKarloApp::calculateAmountPointsInShape(Polyangle *polygon)
{
	int count = 0;

	for (int i = 0; i < pointSet.size(); i++)
	{
		if (polygon->inside(pointSet.data()[i]))
			count++;
	}

	return count;
}				

int MonteKarloApp::calculateSpase()
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