// Syntax of an operator function heading:
// returnType operator operatorSymbol(formal parameter list)

#include "rectangleType.h"
#include <iostream>

int main() {

    rectangleType yard1 = rectangleType(10, 8); // Instantiated yard1
    std::cout << "yard1: ";
    std::cout << yard1; // Prints yard1
    std::cout << std::endl;
    rectangleType yard2 = rectangleType(7, 6); // Instantiated yard2
    std::cout << "yard2: ";
    std::cout << yard2; // Prints yard2
    std::cout << std::endl;

    // Add yard1 and yard 2
    std::cout << "Add yard1 and yard2: ";
    rectangleType yard3 = yard1 + yard2; // Instantiated yard3
    std::cout << yard3; // Prints yard3
    std::cout << std::endl;

    // Subtract yard2 from yard3
    std::cout << "Subtract yard2 from yard3: ";
    yard3 = yard3 - yard2; // The value of yard3 is now changed
    std::cout << yard3;
    std::cout << std::endl;

    // Check for equivalency between yard1 and yard3
    std::cout << "Check for equivalency between yard1 and yard3 (which has had yard2 subtracted from it): ";
    bool equivalence = yard1 == yard3;
    if (equivalence == 0) {
        std::cout << "false";
    }
    else std::cout << "true";
    std::cout << std::endl;

    // Check if yard1 is greater than yard2
    std::cout << "Check if yard1 is greater than yard2: ";
    bool greaterItem = yard1 > yard2;
    if (greaterItem == 0) { // If yard1 is not greater than yard2
        std::cout << "false";
    }
    else std::cout << "true";
    std::cout << std::endl;

    // Check if yard1 is greater than yard3
    std::cout << "Check if yard1 is greater than yard3: ";
    greaterItem = yard1 > yard3;
    if (greaterItem == 0) { // If yard1 is not greater than yard3
        std::cout << "false";
    }
    else std::cout << "true";
    std::cout << std::endl;


    return 0;
}