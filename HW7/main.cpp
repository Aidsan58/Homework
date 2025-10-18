#include <iostream>
#include <string>
#include "addressType.h"
#include "addressBookList.h"

int main() {
    addressBookList addressBook; // Declared empty linked list

    addressBook.insertAddress(addressType("657 Earnest Way", "Copperopolis", "CA", "95722")); // Adds first address

    addressBook.print(); // Prints all entries

    addressBook.deleteAddress(addressType("657 Earnest Way", "Copperopolis", "CA", "95722")); // Removes address

    addressBook.print();

    return 0;
}