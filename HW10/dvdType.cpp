#include "dvdType.h"

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