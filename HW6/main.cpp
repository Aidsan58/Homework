#include <iostream>
#include <string>

int main() {
    int myNum;
    std::cout << "Enter the number of lines as an integer you want printed: ";
    std::cin >> myNum;
    std::cout << std::endl;

    int u = myNum;
    starFunction(myNum, u);
}