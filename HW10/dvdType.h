#ifndef DVD_TYPE_H
#define DVD_TYPE_H

#include <iostream>
#include <string>
using namespace std;

class dvdType
{
friend istream& operator>>(istream& in, dvdType& myDvd)
{
    getline(in, myDvd.dvdTitle); // we use getLine for titles with spaces
    return in;
} // for user input as dvdType. 
public:
 //Overload relational operators
 bool operator==(const dvdType&) const;
 bool operator!=(const dvdType&) const;
 bool operator<(const dvdType&) const;
 bool operator<=(const dvdType&) const;
 bool operator>(const dvdType&) const;
 bool operator>=(const dvdType&) const;
private:
 string dvdTitle;
 string movieStar1;
 string movieStar2;
 string movieProducer;
 string movieDirector;
 string movieProductionCo;
 int copiesInStock;
};

//Overload the relational operators
bool dvdType::operator==(const dvdType& right) const
{
 return (dvdTitle == right.dvdTitle);
}
bool dvdType::operator!=(const dvdType& right) const
{
 return (dvdTitle != right.dvdTitle);
}
bool dvdType::operator<(const dvdType& right) const
{
 return (dvdTitle < right.dvdTitle);
}
bool dvdType::operator<=(const dvdType& right) const
{
 return (dvdTitle <= right.dvdTitle);
}
bool dvdType::operator>(const dvdType& right) const
{
 return (dvdTitle > right.dvdTitle);
}
bool dvdType::operator>=(const dvdType& right) const
{
 return (dvdTitle >= right.dvdTitle);
}

#endif