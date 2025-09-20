#include <iostream>

int main() {
    int *intList;
    int arraySize;

    std::cout << "Enter array size: ";
    std::cin >> arraySize;
    std::cout << std::endl;

    intList = new int[arraySize];

    delete[] intList;

    return 0;

}

