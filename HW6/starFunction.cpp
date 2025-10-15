#include <iostream>
#include <string>


/*
void starFunction(int myNum, int goesDown, int goesUp) {
    if (goesDown != 0) {
        for (int i = 0; i < goesDown; ++i) {
            std::cout << "*"; // Prints the number of stars that goesDown is equal to
        }
        std::cout << std::endl;
        starFunction(myNum, goesDown - 1, goesUp); // goesDown is decreased by 1 every call
    }
    else { // If goesDown is equal to zero
        if (goesUp == myNum) return; // Return early if goesUp is already the same as myNum. By this point everything should be printed and we can then terminate the program
        ++goesUp; // goesUp should be at least one here
        for (int i = 0; i < goesUp; ++i) {
            std::cout << "*"; // Number of stars printed is now based on goesUp instead of goesDown
        }
        std::cout << std::endl;
        starFunction(myNum, goesDown, goesUp); // We already increased goesUp, so we don't need to change any numbers in the function call
    }
    
}
    */

void starFunction(int whiteSpace, int spaceNum) {
    if (spaceNum < 1) return; // By this point everything should be printed and we can then terminate the program
    for (int j = 1; j <= spaceNum; ++j) {
        if (j % 2 != 0) { // If j is odd
            std::cout << "*";
        }
        else { // If the number (j) is even
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    starFunction(whiteSpace + 1, spaceNum - 2);

}