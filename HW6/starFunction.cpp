#include <iostream>
#include <string>

void starFunction(int myNum, int u) {
    if (u == 0) {
        return;
    }
    else {
        for (int i = 0; i < u; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    starFunction(myNum, u - 1);
}