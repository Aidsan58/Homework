#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

int main() {
    int *p;
    char *name;
    std::string *str;

    p = new int;

    *p = 28;

    name = new char[5];

    strcpy(name, "John");

    str = new std::string;

    *str = "Sunny Day";

    std::cout << *p << std::endl;

    return 0;


}