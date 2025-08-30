#include <iostream>
#include <string>

class personType // This code is taken from the textbook Eighth Edition C++ PROGRAMMING D.S. Malik
{
public:
std::string phoneNumber;

 void print() const;
 //Function to output the first name and last name
 //in the form firstName lastName.

 void setName(std::string first, std::string last);
 //Function to set firstName and lastName according
 //to the parameters.
 //Postcondition: firstName = first; lastName = last
 std::string getFirstName() const;
 //Function to return the first name.
 //Postcondition: The value of firstName is returned.
 std::string getLastName() const;
 //Function to return the last name.
 //Postcondition: The value of lastName is returned.
 personType(std::string first = "", std::string last = "", std::string phoneNumber = "1234567890");
 //Constructor
 //Sets firstName and lastName according to the parameters.
 //The default values of the parameters are null strings.
 //Postcondition: firstName = first; lastName = last

 std::string firstName; //variable to store the first name
 std::string lastName; //variable to store the last name
};

void personType::print() const
{
 std::cout << firstName << " " << lastName;
}
void personType::setName(std::string first, std::string last)
{
 firstName = first;
 lastName = last;
}

std::string personType::getFirstName() const
{
 return firstName;
}
std::string personType::getLastName() const
{
 return lastName;
}
 //constructor
// This code is taken from the textbook Eighth Edition C++ PROGRAMMING D.S. Malik