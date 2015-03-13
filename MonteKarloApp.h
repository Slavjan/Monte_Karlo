#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include "polyangle.h"
#include "grn.h"

class MonteKarloApp
{
protected:
	// fields
	int	Space;
	int controlSpace;
	Polyangle* testing;
	Polyangle* control;
	std::vector<Point> pointSet;
	grn* m_rundom;	 // my _ random

	//methods
		// generations
	void generatePontsSet();   // genereate set of points for calculations
	void generateControlShape();	   // generate the shape with known space for calculations

		// calculations
	std::vector<int> calculateExtremumCoords(Polyangle *shape);
	int calculateAmountPointsInShape(Polyangle *polygon); // in dependence an amount of the points in a shape,
	float calculateSpase();								  // calculating the space of this shape 	

public:															
	MonteKarloApp();
	~MonteKarloApp();

	//methods
		// settings
	void setShape(std::vector<Point> dots);	// calculate her spase
	void setShape(Polyangle *shape);
	void setShape(Polyangle shape);
		// returning
	float getSpace();

		// for derivative class
	virtual bool loadShape() {};	// take a shape for 	 // from file or parameters
	virtual bool readFile(std::string path) {};
	virtual bool readParams() {};
};

