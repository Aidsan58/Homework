#include <iostream>
#include <string>

void starFunction(int whiteSpace, int spaceNum, int myNum, int firstHalfNum) {
    if (firstHalfNum != ((myNum * 2) - 1)) { // We begin by adding stars each call
        for (int k = 0; k < whiteSpace; ++k) {
                std::cout << " "; // We have leading whitespaces so the stars alignn and we end up with a diamond shape
        }
        for (int j = 1; j <= spaceNum; ++j) {
            if (j % 2 != 0) { // If j is odd
                std::cout << "*";
            }
            else { // If the number (j) is even
                std::cout << " ";
            }
        }
        std::cout << std::endl;
        starFunction(whiteSpace - 1, spaceNum + 2, myNum, firstHalfNum + 2);
    }
    else { // if (firstHalfNum == ((myNum * 2) - 1)) We start going backwards (reducing stars) after this, firstHalfNum stops increasing and doesn't match up with spaceNum any longer, this is the only use for firstHalfNum
        if (spaceNum < 1) return; // By this point everything should be printed and we can then terminate the program
        for (int k = 0; k < whiteSpace; ++k) {
                std::cout << " ";
        }
        for (int j = 1; j <= spaceNum; ++j) {
            if (j % 2 != 0) { // If j is odd
                std::cout << "*";
            }
            else { // If the number (j) is even
                std::cout << " ";
            }
        }
        std::cout << std::endl;
        starFunction(whiteSpace + 1, spaceNum - 2, myNum, firstHalfNum); // We no longer change firstHalfNum, and the other variables start going in the opposite direction as before
        }
    
}