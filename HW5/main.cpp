#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "invalidDay.h"
#include "invalidMonth.h"
#include "invalidYear.h"

bool isLeapYear(int year) { // A leap year is dvisible by 4, but not by 100, unless it is also divisible by 400. Source: https://www.mathsisfun.com/leap-years.html
    if ((year % 4) == 0) { // Divisible by 4
        if ((year % 400) == 0) { // Divisible by 400, automatically returns true
            return true;
    }
        if ((year % 100) != 0) { // If year is divisible by 4, but not 100, then it is a leap year
            return true;
        }
    }
    return false;
}

std::string checkDay(int day, int month, int year) { // If the logic determines the day is valid, then we return "valid". 
                                                     // This function has the most complicated logic, as we need to account for leap years and different months having different rules

    if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) { // Months where 31 days is not valid, but 30 days is
        if ((day >= 1) && (day <= 30)) {
            return "valid";
        }
    }

    if ((month == 1) || (month == 3) || (month == 4) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) { // Months where 31 days is valid
        if ((day >= 1) && (day <= 31)) {
            return "valid";
        }
    }
    if ((month == 2) && (isLeapYear(year) == true)) { // We need separate logic for February when it's a leap year
        if ((day >= 1) && (day <= 29)) { // If it is a leap year
            return "valid";
        }
    }
    if (month == 2) { // more February logic
        if ((day >= 1) && (day <= 28)) { // If it is not a leap year
            return "valid";
        }
    }
    return "invalid"; // If none of these if statements return valid, then the day must be invalid
}

std::string checkMonth(int month) { // Obviously, a month can't be less than 1, or more than twelve, so we return "invalid" if this happens
    if ((month < 1) || (month > 12)) { // Very simple logic
        return "invalid";
    }
    else return "valid";
}

std::string checkYear(int year) {
    if ((year < 1900) || (year > 2025)) { // We assume nobody over 125 is using this program, and anyone who doesn't exist yet isn't using the program
        return "invalid";
    }
    else return "valid";
}

int main() {

    std::string input;
    int day;
    int month;
    int year;

    do { // We want at least one execution, so we use a do/while loop
        std::cout << "Please enter your date of birth in the format 'dd-mm-yyyy': "; // We want this to run repeatedly as long as the date the user inputs is not valid
        std::getline(std::cin, input); // std::cin - user input

        std::stringstream ss(input); // We use stringstream for parsing and making sure the user made a valid input. i.e. it can be read as an int and not just as a string
        std::string item;
        std::vector<int> dateOfBirth; // We make a vector so we can parse the user inputs later

        while (std::getline(ss, item, '-')) { // We use '-' to separate the date month and year
            try { // There is a possibility that the user inputs something that can't be parsed as a date, so we account for that in our try catch blocks
                dateOfBirth.push_back(std::stoi(item)); // std::stoi() to convert stream value to int
            }
            catch (...) { // We use the generic error handler because we can
                std::cout << "Error converting string to integer, the format is invalid. Please try again." << std::endl;
                continue; // The input is invalid so we terminate this iteration of the loop
            }
            
        }

        if (dateOfBirth.size() != 3) { // We can't have more than three parameters for the date of birth, so we make sure its size is 3 so we don't get out of bounds errors
            std::cout << "Error converting string to integer, the format is invalid. Please try again." << std::endl;
            continue; // The input is invalid so we terminate this iteration of the loop
        }

        day = dateOfBirth[0];
        month = dateOfBirth[1];
        year = dateOfBirth[2];

        try {                                               // Our repetitive try catch blocks. We have three try blocks (day, month, year), 
            if (checkMonth(month) == "invalid") {  // and three catch blocks. Having the classes makes this a lot simpler, and we just have to
                throw invalidMonth();                         // Call their what() functions in our catch block.
            }                                                 // We check the month first because the day logic will override it.
            if (checkDay(day, month, year) == "invalid") {
                throw invalidDay();
            }
            if (checkYear(year) == "invalid") {
                throw invalidYear();
            }
        }
        catch(invalidMonth invalidMonthObject) {
            std::cout << invalidMonthObject.what() << std::endl;
        }
        catch(invalidDay invalidDayObject) {
            std::cout << invalidDayObject.what() << std::endl;
        }
        catch(invalidYear invalidYearObject) {
            std::cout << invalidYearObject.what() << std::endl;
        }

    } 
    while (checkDay(day, month, year) == "invalid" || checkMonth(month) == "invalid" || checkYear(year) == "invalid"); // The condition on which the loop keeps running

    
    std::string spelledMonth;
    if (month == 1) spelledMonth = "January";
    if (month == 2) spelledMonth = "February";
    if (month == 3) spelledMonth = "March";
    if (month == 4) spelledMonth = "April";
    if (month == 5) spelledMonth = "May";
    if (month == 6) spelledMonth = "June";
    if (month == 7) spelledMonth = "July";
    if (month == 8) spelledMonth = "August";
    if (month == 9) spelledMonth = "September";
    if (month == 10) spelledMonth = "October";
    if (month == 11) spelledMonth = "November";
    if (month == 12) spelledMonth = "December";

    std::cout << "Your date of birth is " << spelledMonth << " " << day << ", " << year << "." << std::endl;
    return 0;
}