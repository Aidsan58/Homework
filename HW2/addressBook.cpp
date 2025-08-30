#include "addressBookType.h"

void addressBookSort(addressBookType addressBook[]) { // Uses a lambda function with std::sort from the algorithm library to sort by last name.
    std::sort(addressBook, addressBook + 500, [](const personType& a, const personType& b) {
        return a.getLastName() < b.getLastName();
    });
}

int addressBookSearch(std::string inquiry, addressBookType addressBook[]) {
    for (int i = 0; i < 500; i++) {
        if (addressBook[i].getLastName() == inquiry) {
            std::cout << "Last name has been found." << std::endl;
            int index = i;
            return index; // returns early if last name found.
        }
    }
    std::cout << "No matching last name found." << std::endl;
}

void printInformation(int index, addressBookType addressBook[]) { // Print the address, phone number, and date of birth of a person.
    std::cout << "Name: " << addressBook[index].firstName << " " << addressBook[index].lastName << std::endl;
    std::cout << "Address: " << addressBook[index].streetAddress << ", " << addressBook[index].city << ", " << addressBook[index].state << ", " << addressBook[index].zipCode << std::endl;
    std::cout << "Phone number: " << addressBook[index].phoneNumber << std::endl;
    std::cout << "Date of birth: " << addressBook[index].dMonth << ", " << addressBook[index].dDay << ", " << addressBook[index].dYear << std::endl;
}

void givenMonth(int month, addressBookType addressBook[]) { // Prints the names of all people with birthdays in a given month.
    for (int i = 0; i < 500; i++) {
        if (addressBook[i].dMonth == month) {
            std::cout << addressBook[i].firstName << " " << addressBook[i].lastName << " has a birthday in this month." << std::endl;
        }
    }
}

void betweenNames(std::string firstLastName, std::string secondLastName, addressBookType addressBook[]) { // Print the names of all the people between two last names.
    int firstLocation = addressBookSearch(firstLastName, addressBook);
    int secondLocation = addressBookSearch(secondLastName, addressBook);
    if (firstLocation > secondLocation) { // Switches the two locations if the first location is greater than the second location.
        int given = firstLocation;
        firstLocation = secondLocation;
        secondLocation = given;
    }
    for (int i = firstLocation + 1; i < secondLocation; i++) {
        std::cout << addressBook[i].firstName << " " << addressBook[i].lastName << std::endl;
    }
}

int main() {
    addressBookType addressBook[500];


    return 0;
}