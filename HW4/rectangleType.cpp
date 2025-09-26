#include "rectangleType.h"


rectangleType& rectangleType::setLength(double l)
{
 length = l;
 return *this;
}

rectangleType& rectangleType::setWidth(double w)
{
 width = w;
 return *this;
}

rectangleType rectangleType::doubleDimensions()
{
    length = 2 * length;
    width = 2 * width;
 
    return *this;
}