#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include "polyangle.h"
#include "grn.h"

class Application
{
private:
	// fields
	int	Space;
	int controlSpace;
	Polyangle* testing;
	Polyangle* control;
	std::vector<Point> pointSet;
	grn* m_rundom;

	//methods
		// generations
	void generatePontsSet();   // genereate set of points for calculations
	void generateControlShape();	   // generate the shape with known space for calculations

		// calculations
	int calculateAmountPointsInShape(Polyangle *polygon); // in dependence an amount of the points in a shape,
	void calculateSpase();								  // calculating the space of this shape

public:
	Application();
	~Application();

	//methods
		// settings
	void setShape(std::string path);				// take a shape for 
	void setShape(std::vector<int> coordinates);		// calculate her spase
		// returning
	int getSpace();
};

