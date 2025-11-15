#include <iostream>
using namespace std;

class dvdType
{
 friend ostream& operator<< (ostream&, const dvdType&);
public:
 void setDVDInfo(string title, string star1,
 string star2, string producer,
 string director, string productionCo,
 int setInStock);
 int getNoOfCopiesInStock() const;
 void checkOut();
 void checkIn();
 void printTitle() const;
 void printInfo() const;
 bool checkTitle(string title);
 void updateInStock(int num);
 void setCopiesInStock(int num);
 string getTitle() const;
 dvdType(string title = "", string star1 = "",
 string star2 = "", string producer = "",
 string director = "", string productionCo = "",
 int setInStock = 0);
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