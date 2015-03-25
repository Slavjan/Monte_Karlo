#pragma once
#include "MonteKarloApp.h"

// publice
MonteKarloApp::MonteKarloApp()
{
	Space = 0;
	controlSpace = 0;
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

float MonteKarloApp::getSpace()
{
	return calculateSpase();
}
// /public

// protected
std::vector<int> MonteKarloApp::calculateExtremumCoords(Polyangle *shape)
{
	std::vector<int> Extremum;
	Extremum.push_back(shape->getMaxX());
	Extremum.push_back(shape->getMaxY());
	Extremum.push_back(shape->getMinX());
	Extremum.push_back(shape->getMinY());
	
	status(1, 1, "MonteKarloApp::calculateExtremumCoords");
		
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

	status(1, 1, "MonteKarloApp::generateControlShape");
}

void MonteKarloApp::generatePontsSet()
{
	Point p;
	std::vector<int> tExtremum = calculateExtremumCoords(testing);
	int maxX = tExtremum.at(0),
		maxY = tExtremum.at(1);
	int minX = tExtremum.at(2),
		minY = tExtremum.at(3);

	int end = controlSpace * 2 / 3;
	
	for (int i = 0; i < (end < 0 ? -end : end); i++)
	{
		p.x = m_rundom->getInRange(minX, maxX);
		p.y = m_rundom->getInRange(minY, maxY); 
		pointSet.push_back(p);
		status(i-1, (end < 0 ? -end : end), "MonteKarloApp::generateControlShape");
	}
	pointSet.pop_back(); 
	status((end < 0 ? -end : end), (end < 0 ? -end : end), "MonteKarloApp::generateControlShape");
}

int MonteKarloApp::calculateAmountPointsInShape(Polyangle *polygon)
{
	int count = 0;

	for (int i = 0; i < pointSet.size(); i++)
	{
		try
		{
			if (polygon->inside(pointSet.data()[i]))
				count++;
		}
		catch (Polyangle::isLine())
		{
			std::cout << "Enteret isn`t Shape, this is line, she can`t have a space!" << std::endl;
		}
	}

	return count;
}				

float MonteKarloApp::calculateSpase()
{
	int p_i_cShape, // amount of points in control Shape
		p_i_tShape;	// amount of Points In testing Shape

	status(1, 3, "MonteKarloApp::calculateSpase");

	p_i_cShape = calculateAmountPointsInShape(control);
	p_i_tShape = calculateAmountPointsInShape(testing);

	status(2, 3, "MonteKarloApp::calculateSpase");

	float ratio = p_i_tShape / p_i_cShape;
	float space = ratio * controlSpace;

	status(3, 3, "MonteKarloApp::calculateSpase");

	return space;
}
// /protected