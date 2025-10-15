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

    int firstHalfNum = 1;
    int whiteSpace = myNum - 1; // We start (and end) with whitespaces being equal to one less than the number of lines (represented by myNum)
    int spaceNum = firstHalfNum; // At first spaceNum and firstHalfNum are the same, but spaceNum diverges from firstHalfNum when we get to the second half of the diamond shape
    starFunction(whiteSpace, spaceNum, myNum, firstHalfNum);

    return 0;
}