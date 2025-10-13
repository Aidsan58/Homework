#include <iostream>
#include <string>
#include "starFunction.h" // recursive function code

int main() {
    int myNum;
    std::cout << "Enter the number of lines as an integer you want printed: ";
    std::cin >> myNum;
    std::cout << std::endl;

    int goesDown = myNum;
    int goesUp = 0; // When goesDown reaches zero, then this number starts incrementing, that way we get the intended output with the stars
    starFunction(myNum, goesDown, goesUp);
}