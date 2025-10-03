#include <algorithm>

class dateType // This code is taken from the textbook Eighth Edition C++ PROGRAMMING D.S. Malik
{
public:
 void setDate(int month, int day, int year);
 //Function to set the date.
 //The member variables dMonth, dDay, and dYear are set
 //according to the parameters.
 //Postcondition: dMonth = month; dDay = day;
 // dYear = year;
 bool isLeapYear(int month);
 //Determines if the year is a leap year
 //Returns true if the year is a leap year, and false if the year is not a leap year.
 int getDay() const;
 //Function to return the day.
 //Postcondition: The value of dDay is returned.
 int getMonth() const;
 //Function to return the month.
 //Postcondition: The value of dMonth is returned.
 int getYear() const;
 //Function to return the year.
 //Postcondition: The value of dYear is returned.
 void printDate() const;
 //Function to output the date in the form mm-dd-yyyy.
int dMonth; //variable to store the month
int dDay; //variable to store the day
int dYear; //variable to store the year
 dateType(int month = 1, int day = 1, int year = 1900) {
    dMonth = month;
    dDay = day;
    dYear = year;
 }
 //Constructor to set the date
 //The member variables dMonth, dDay, and dYear are set
 //according to the parameters.
 //Postcondition: dMonth = month; dDay = day; dYear = year;
 // If no values are specified, the default
 // values are used to initialize the member
 // variables.
 
}; // This code is taken from the textbook Eighth Edition C++ PROGRAMMING D.S. Malik

void dateType::setDate(int month, int day, int year) {

    dYear = year;

    if ((month >= 1) && (month <= 12)) {
        dMonth = month;
    }
    if ((month == 4) | (month == 6) | (month == 9) | (month == 11)) {
        if ((day >= 1) && (day <= 30)) {
            dDay = day;
    }
    }

    if ((month == 1) | (month == 3) | (month == 4) | (month == 5) | (month == 7) | (month == 8) | (month == 10) | (month == 12)) {
        if ((day >= 1) && (day <= 31)) {
            dDay = day;
    }
    }
    if ((month == 2) && (isLeapYear(year) == true)) {
        if ((day >= 1) && (day <= 29)) {
            dDay = day;
    }
    }
    if (month == 2) {
        if ((day >= 1) && (day <= 28)) {
            dDay = day;
    }
    }

}

bool dateType::isLeapYear(int year) { // A leap year is dvisible by 4, but not by 100, unless it is also divisible by 400. Source: https://www.mathsisfun.com/leap-years.html
    if ((year % 4) == 0) {
        if ((year % 400) == 0) {
            return true;
    }
        if ((year % 100) != 0) {
            return true;
        }
    }
    return false;
}