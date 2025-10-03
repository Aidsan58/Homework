#ifndef INVALID_MONTH_H
#define INVALID_MONTH_H

#include <iostream>

class invalidMonth {
public:

    // Class constructor
    invalidMonth() {
    message = "The input year is invalid.";
    }

    // Overloaded constructor with msg string parameter
    invalidMonth(std::string msg) {
    message = msg;
    }

    std::string what() {
    return message;
    }

    private:
    std::string message;
};

#endif