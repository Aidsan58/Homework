#ifndef RECTANGLE_TYPE_H
#define RECTANGLE_TYPE_H

#include <iostream>

class rectangleType {
    friend void rectangleFriend(rectangleType recObject);
    friend std::ostream& operator<<(std::ostream&, const rectangleType&);
    friend std::istream& operator>>(std::istream&, rectangleType&);
public:
    rectangleType(int length, int width) {
        this->length = length;
        this->width = width;
    }
    void setDimension(double l, double w);
    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;

    rectangleType operator+(const rectangleType&) const;
        //Overload the operator +
    rectangleType operator*(const rectangleType&) const;
        //Overload the operator *
    bool operator==(const rectangleType&) const;
        //Overload the operator ==
    bool operator!=(const rectangleType&) const;
        //Overload the operator !=
    rectangleType& operator++();
        //Overload the operator ++
    rectangleType& operator--();
        //Overloads the operator --
    rectangleType operator-(const rectangleType&) const;
        //Overloads the operator -
    bool operator>(const rectangleType&) const;
        //Overload the operator greater than
    bool operator<(const rectangleType&) const;
        //Overload the operator less than

    rectangleType& setLength(double l);
    //Function to set the length.
    //Postcondition: length = l
    // After setting the length, a reference to the object,
    // that is, the address of the object, is returned.
    rectangleType& setWidth(double w);
    //Function to set the width.
    //Postcondition: width = w
    // After setting the width, a reference to the object,
    // that is, the address of the object, is returned.
    rectangleType(double l = 0.0, double w = 0.0);
    // This member function doubles the dimensions of the rectangle
    rectangleType doubleDimensions();
protected:
    double length;
    double width;
};

#endif