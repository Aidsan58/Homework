#include <iostream>
#include <string>
#include "starFunction.h" // recursive function code

int main() {
    int myNum;
    std::cout << "Enter the number of lines as an integer you want printed: ";
    std::cin >> myNum;
    std::cout << std::endl;
    while (myNum < 1) { // If myNum isn't a positive integer, we prompt the user to try again
        std::cout << "Not a valid input, the integer should be positive and nonzero. Try again: ";
        std::cin >> myNum;
        std::cout << std::endl;
    }
    /*
    int goesDown = myNum;
    int goesUp = 0; // When goesDown reaches zero, then this number starts incrementing, that way we get the intended output with the stars
    starFunction(myNum, goesDown, goesUp);
    */

    int whiteSpace = 0;
    int spaceNum = ((myNum * 2) - 1);
    starFunction(whiteSpace, spaceNum);

    return 0;
}