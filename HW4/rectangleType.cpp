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

std::ostream& operator<< (std::ostream& osObject, const rectangleType& rectangle) {
    osObject << "Length = " << rectangle.length
    << "; Width = " << rectangle.width;
    return osObject;
}

std::istream& operator>> (std::istream& isObject, rectangleType& rectangle) {
    isObject >> rectangle.length >> rectangle.width;
    return isObject;
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

rectangleType rectangleType::operator+(const rectangleType& rectangle) const {
    rectangleType tempRect;
    tempRect.length = length + rectangle.length;
    tempRect.width = width + rectangle.width;
    return tempRect;
}

rectangleType rectangleType::operator*(const rectangleType& rectangle) const {
    rectangleType tempRect;
    tempRect.length = length * rectangle.length;
    tempRect.width = width * rectangle.width;
    return tempRect;
}

bool rectangleType::operator==(const rectangleType& rectangle) const {
    rectangleType tempRect;
    return (tempRect.area() == rectangle.area()); // Redefined operator to check for area instead of width and length individually
}

bool rectangleType::operator!=(const rectangleType& rectangle) const {
    rectangleType tempRect;
    return (tempRect.area() != rectangle.area()); // Redefined operator to check for area instead of width and length individually
}

rectangleType& rectangleType::operator++() {
    length++;
    width++;
    return *this; // Our return value points to rectangleType with updated values
}

rectangleType& rectangleType::operator--() {
    length--;
    width--;
    return *this; // Our return value points to rectangleType with updated values
}

rectangleType rectangleType::operator-(const rectangleType& rectangle) const {
    rectangleType tempRect;
    if (tempRect.length > rectangle.length && tempRect.width > rectangle.width) { // If the first rectangle does not have both length and width greater than the second rectangle, the action is not performed
        tempRect.length = length - rectangle.length;
        tempRect.width = width - rectangle.width;
    }
    else std::cout << "This action can't be performed." << std::endl; // If the action fails, we let the user know
    return tempRect; // We return the new value
}

bool rectangleType::operator>(const rectangleType& rectangle) const {
    rectangleType tempRect;
    return (tempRect.area() > rectangle.area()); // Redefined operator to check for area instead of width and length individually
}

bool rectangleType::operator<(const rectangleType& rectangle) const {
    rectangleType tempRect;
    return (tempRect.area() < rectangle.area()); // Redefined operator to check for area instead of width and length individually
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