#include "addressBookType.h"

void addressBookSort(addressBookType addressBook[]) { // Uses a lambda function with std::sort from the algorithm library to sort by last name.
    std::sort(addressBook, addressBook + 500, [](const personType& a, const personType& b) {
        return a.getLastName() < b.getLastName();
    });
}

int addressBookSearch(std::string inquiry, addressBookType addressBook[]) { // Searches by last name.
    for (int i = 0; i < 500; i++) {
        if (addressBook[i].getLastName() == inquiry) {
            std::cout << "Last name has been found." << std::endl;
            int index = i;
            return index; // returns early if last name found.
        }
    }
    std::cout << "No matching last name found." << std::endl;
    return -1; // Not found
}

void printInformation(int index, addressBookType addressBook[]) { // Print the address, phone number, and date of birth of a person.
    std::cout << "Name: " << addressBook[index].firstName << " " << addressBook[index].lastName << std::endl;
    std::cout << "Address: " << addressBook[index].streetAddress << ", " << addressBook[index].city << ", " << addressBook[index].state << ", " << addressBook[index].zipCode << std::endl;
    std::cout << "Phone number: " << addressBook[index].phoneNumber << std::endl;
    std::cout << "Date of birth: " << addressBook[index].dMonth << "-" << addressBook[index].dDay << "-" << addressBook[index].dYear << std::endl;
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
    if (firstLocation == -1 || secondLocation == -1) {
    std::cout << "One or both names not found." << std::endl;
    return;
    }
    if (firstLocation > secondLocation) { // Switches the two locations if the first location is greater than the second location.
        int given = firstLocation;
        firstLocation = secondLocation;
        secondLocation = given;
    }
    for (int i = firstLocation + 1; i < secondLocation; i++) {
        std::cout << addressBook[i].firstName << " " << addressBook[i].lastName << std::endl;
    }
}

void printRelations(int index, addressBookType addressBook[]) { // Depending on the user’s request, print the names of all family members, friends, or business associates.
    std::cout << "Do you wish to print the names of family members, friends, or associates? Type family or friend or associate" << std::endl;
    std::string result;
    std::cin >> result;
    for (int j = 0; j < 500; j++) {
        if (result == "family") {
        if (addressBook[index].isFamilyMember == true) {
        std::cout << addressBook[index].extFirstName << " " << addressBook[index].extLastName << std::endl;
        return;
    }
    }
    if (result == "friend") {
        if (addressBook[index].isFriend == true) {
        std::cout << addressBook[index].extFirstName << " " << addressBook[index].extLastName << std::endl;
        return;
    }
    }
    if (result == "associate") {
        if (addressBook[index].isBusinessAssociate == true) {
        std::cout << addressBook[index].extFirstName << " " << addressBook[index].extLastName << std::endl;
        return;
            }
        }
    }
        std::cout << "None found." << std::endl;
}

int main() {
    addressBookType addressBook[500];

    addressBook[0].setName("Jiminy", "Cricket");
    addressBook[0].setDate(10, 4, 2001);
    addressBook[0].phoneNumber = "7073333333";
    addressBook[0].setAddress("657 Earnest Way", "Copperopolis", "CA", "95722");
    addressBook[0].extPersonTypeSet("Saul", "Goodman", false, false, true, "9293476666");


    addressBookSort(addressBook);
    int index = addressBookSearch("Cricket", addressBook);
    printInformation(index, addressBook);
    givenMonth(10, addressBook);
    printRelations(0, addressBook);


    return 0;
}