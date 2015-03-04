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
        return;
    }

    stream >> _count;
    while( ! stream.eof() ){
        stream >> _cross.x;
        stream >> _cross.y;
        _vertex.push_back(_cross);
    }
    _vertex.pop_back();
    _vertex.pop_back(); // I d't understand - "WHAT?" ...
    stream.close();
}

void PiPFormat::saveToFile(std::string fileName)
{
    std::ofstream stream( fileName.data() );
    if( ! stream.is_open() ){
		throw wasntSave();
        return;
    } 
    stream << _count << std::endl;
    for(int i = 0; i < _vertex.size(); ++i ){
        stream << _vertex.at(i).x << " " << _vertex.at(i).y << std::endl;
    }
    stream << _cross.x << " " << _cross.y;
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
int PiPFormat::getVerticesCount()
{				  
	return _count;
}

std::vector<Point> PiPFormat::getVector()
{
	return _vertex;
}

Point PiPFormat::getCrossPoint()
{
	return _cross;
}
