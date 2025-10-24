#include "stackType.h"
#include <iostream>


int main() {
    int decimalNum;
    int base;
    base = 2;
    std::cout << "Enter number in decimal: ";
    std::cin >> decimalNum;
    std::cout << std::endl;
    std::cout << "Decimal " << decimalNum << " = ";

    stackType<int> myStack; // Instantiation of stackType with int type
    int myNum = decimalNum;
    while (myNum > 0) {
        myNum = myNum / base;
        myStack.push(myNum);
        std::cout << myStack.top() % base;
    }
    std::cout << " binary" << endl;
    return 0;
}