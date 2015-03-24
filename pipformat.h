#pragma once
#ifndef FILESTRUCT_H
#define FILESTRUCT_H

#include "point.h"
#include "polyangle.h"
#include <vector>
#include <fstream>
#include <iostream>

class PiPFormat
{
    int		_count;
    std::vector<Point> _vertex;
    Point	_cross;
public:
    PiPFormat();
    PiPFormat(int count, std::vector<Point> &vertex, Point& cross);

    void	loadFromFile(std::string fileName);
    void	saveToFile(std::string fileName, std::string format);

	int			getVerticesCount();
	std::vector<Point>	getVector();
	Point 		getCrossPoint();

    void print();

	// exceptions
	class notFound{};
	class wasntSave{};
};

#endif // FILESTRUCT_H
