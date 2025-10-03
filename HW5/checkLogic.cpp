#include <string>
#include <iostream>

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
    if ((year < 1900) || (year > 2025)) { // We assume nobody over 125 is using this program, and anyone who doesn't exist yet wouldn't be using the program
        return "invalid";
    }
    else return "valid";
}