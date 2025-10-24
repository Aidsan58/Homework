#include "stackType.h"
#include <iostream>


int main() {
    int decimalNum; // Converting user-input base 10 value to binary value
    int base;
    base = 2; // Binary is base 2
    std::cout << "Enter number in decimal: ";
    std::cin >> decimalNum;
    std::cout << std::endl;
    std::cout << "Decimal " << decimalNum << " = ";

    stackType<int> myStack; // Instantiation of stackType with int type
    int myNum = decimalNum; // We don't want to change the value of decimalNum so we make myNum as a temp value
    while (myNum > 0) {
        int remainder = myNum % base; // First step in converting base 10 to base 2. Return the modulus of the top of the stack divided by the base (which is 2, of course)
        myStack.push(remainder); // Add value of remainder to stack
        myNum = myNum / base; // Divide the value of myNum by 2
    }
    while (myStack.isEmptyStack() == false) { // We want to print in reverse of the order that we added
        std::cout << myStack.top(); // Print the value at the top of the stack
        myStack.pop(); // Pop the top from the stack and go back to the start of the loop until we have no more entries in the stack
    }
    std::cout << " binary" << std::endl;
    return 0;
}