#include "addressBookType.h"

void addressBookSort(addressBookType addressBook[]) { // Uses a lambda function with std::sort from the algorithm library to sort by last name.
    std::sort(addressBook, addressBook + 500, [](const personType& a, const personType& b) {
        return a.getLastName() < b.getLastName();
    });
}

int main() {
    addressBookType addressBook[500];


    return 0;
}