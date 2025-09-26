#include <iostream>

class rectangleType {
    friend void rectangleFriend(rectangleType recObject);
    friend std::ostream& operator<<(std::ostream&, const rectangleType&);
    friend std::istream& operator>>(std::istream&, rectangleType&);
public:
    void setDimension(double l, double w);
    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;
    void print() const;

    rectangleType operator+(const rectangleType&) const;
        //Overload the operator +
    rectangleType operator*(const rectangleType&) const;
        //Overload the operator *
    bool operator==(const rectangleType&) const;
        //Overload the operator ==
    bool operator!=(const rectangleType&) const;
        //Overload the operator !=

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
private:
    double length;
    double width;
};