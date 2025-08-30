#include "addressBookType.h"

void addressBookSort(addressBookType addressBook[]) { // Uses a lambda function with std::sort from the algorithm library to sort by last name.
    std::sort(addressBook, addressBook + 500, [](const personType& a, const personType& b) {
        return a.getLastName() < b.getLastName();
    });
}

void addressBookSearch(std::string inquiry, addressBookType addressBook[]) {
    for (int i = 0; i < 500; i++) {
        if (addressBook[i].getLastName() == inquiry) {
            std::cout << "Last name has been found" << std::endl;
            return; // returns early if last name found.
        }
    }
    std::cout << "No matching last name found." << std::endl;
}


int main() {
    addressBookType addressBook[500];


    return 0;
}