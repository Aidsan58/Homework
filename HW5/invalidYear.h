#ifndef INVALID_YEAR_H
#define INVALID_YEAR_H

#include <iostream>

class invalidYear {
public:

    // Class constructor
    invalidYear() {
    message = "The input year is invalid.";
    }

    // Overloaded constructor with msg string parameter
    invalidYear(std::string msg) {
    message = msg;
    }

    std::string what() {
    return message;
    }

    private:
    std::string message;
};

#endif