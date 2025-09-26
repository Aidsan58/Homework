#include "rectangleType.h"
#include <iostream>


void rectangleFriend(rectangleType recFriendObject) {
    std::cout << "recFriendObject area: " << recFriendObject.area()
    << std::endl;
    recFriendObject.length = recFriendObject.length + 5;
    recFriendObject.width = recFriendObject.width + 5;
    std::cout << "After increasing length and width by 5 units "
    << "each, \n recFriendObject area: "
    << recFriendObject.area() << std::endl;
}

void rectangleType::setDimension(double l, double w) {
    if (l >= 0)
        length = l;
    else
        length = 0;
    if (w >= 0)
        width = w;
    else
        width = 0;
}

double rectangleType::getLength() const {
 return length;
}

double rectangleType::getWidth() const {
 return width;
}

double rectangleType::area() const {
 return length * width;
}

double rectangleType::perimeter() const {
 return 2 * (length + width);
}

void rectangleType::print() const {
 std::cout << "Length = " << length
 << "; Width = " << width;
}

rectangleType::rectangleType(double l, double w) {
 setDimension(l, w);
}

rectangleType::rectangleType() {
 length = 0;
 width = 0;
}

rectangleType& rectangleType::setLength(double l) {
 length = l;
 return *this;
}

rectangleType& rectangleType::setWidth(double w) {
 width = w;
 return *this;
}

rectangleType rectangleType::doubleDimensions() {
    length = 2 * length;
    width = 2 * width;
 
    return *this;
}