#include <algorithm>

#ifndef INVALID_DAY_H
#define INVALID_DAY_H

#include <iostream>

class invalidDay {
public:

    // Class constructor
    invalidDay() {
    message = "The input year is invalid.";
    }

    // Overloaded constructor with msg string parameter
    invalidDay(std::string msg) {
    message = msg;
    }

    std::string what() {
    return message;
    }

    private:
    std::string message;
};

#endif