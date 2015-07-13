#pragma once
#include "pipformat.h"

PiPFormat::PiPFormat()
{
    _count = 0;
}

PiPFormat::PiPFormat(int count, std::vector<Point> &vertex, Point &cross)
{
    _count  = count;
    _vertex = vertex;
    _cross  = cross;
}

void PiPFormat::loadFromFile(std::string fileName)
{
    std::ifstream stream( fileName.data() );
    if( ! stream.is_open() ){
		throw notFound();
    }

    //stream >> _count;
    while( ! stream.eof() ){
        stream >> _cross.x;
        stream >> _cross.y;
        _vertex.push_back(_cross);
    }
    //_vertex.pop_back();
	_count = _vertex.size();

    stream.close();
}

void PiPFormat::saveToFile(std::string fileName, std::string format)
{
    std::ofstream stream( fileName.data() );
    if( ! stream.is_open() ){
		throw wasntSave();
    } 
    stream << format.data() << std::endl;
    stream.close();
}

void PiPFormat::print()
{
    std::cout << "PiPFormat:" << std::endl;
    std::cout << "Count: " << _count << std::endl;
    std::cout << "Cross: "; _cross.print(); std::cout << std::endl;
    std::cout << "Vertex.Size: " << _vertex.size() << std::endl;
    std::cout << "Vertices:" << std::endl;

    for(int i = 0; i < _vertex.size(); ++i ){
        std::cout << "[" << i << "]"; _vertex.at(i).print(); std::cout << std::endl;
    }
    std::cout << std::endl;
}


//getting data
int PiPFormat::getVerticesCount() const
{				  
	return _count;
}

std::vector<Point> PiPFormat::getVector() const
{
	return _vertex;
}

Point PiPFormat::getCrossPoint() const
{
	return _cross;
}
