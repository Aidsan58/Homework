#include "stackType.h"
#include <iostream>


int main() {
    int decimalNum;
    int base;
    base = 2; // Binary is base 2
    std::cout << "Enter number in decimal: ";
    std::cin >> decimalNum;
    std::cout << std::endl;
    std::cout << "Decimal " << decimalNum << " = ";

    stackType<int> myStack; // Instantiation of stackType with int type
    int myNum = decimalNum; // We don't want to change the value of decimalNum so we make myNum as a temp value
    while (myNum > 0) {
        myNum = myNum / base; // First step in converting base 10 to base 2
        myStack.push(myNum); // Add value to stack
        std::cout << myStack.top() % base; // Return the modulus of the top of the stack divided by the base (which is 2, of course)
    }
    std::cout << " binary" << std::endl;
    return 0;
}