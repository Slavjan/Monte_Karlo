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
        throw std::string("File is not open!");
        return;
    }
    Point p;
    stream >> _count;
    while( stream.eof() ){
        stream >> p.x;
        stream >> p.y;
        _vertex.push_back(p);
    }
    _vertex.pop_back();
    _cross = p;
    stream.close();
}

void PiPFormat::saveToFile(std::string fileName)
{
    std::ofstream stream( fileName.data() );
    if( ! stream.is_open() ){
        throw std::string("File is not open!");
        return;
    }
    while( false ){

    }
    stream.close();
}

void PiPFormat::print()
{
    std::cout << "PiPFormat:" << std::endl;
    std::cout << "Count: " << _count << std::endl;
    std::cout << "Cross: "; _cross.print(); std::cout << std::endl;
    std::cout << "Vetrex's:" << std::endl;
    for(int i = 0; i < _vertex.size(); ++i ){
        std::cout << "[" << i << "]"; _vertex.at(i).print(); std::cout << std::endl;
    }
    std::cout << std::endl;
}
