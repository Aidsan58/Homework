#include <iostream>
#include <fstream>
#include <string>
#include "binarySearchTree.h"
#include "dvdType.h"
#include "customerBinaryTreeType.h"

int main()
{
    customerBTreeType<dvdType> myCustomer; // customer instantiation
    while (true) { // true as long as user wants to rent something
        std::cout << "Press 1 to rent an item: " << std::endl;
        std::string response;
        cin >> response;
        std::cin.ignore( 1, '\n' ); // clears istream so we can get user response again.
        if (response == "1") {
            std::cout << "What item are you renting?" << std::endl;
            dvdType myItem; // name of item user will rent.
            cin >> myItem;
            myCustomer.rentItem(myItem);
        }
        else break;
    }
    dvdType newDvd; // customer rents Bill the Lobster to showcase renting and returning functionality.
    newDvd.dvdTitle = "Bill the Lobster";
    myCustomer.rentItem(newDvd);
    std::cout << "Rented Bill the Lobster on DVD." << std::endl;
    myCustomer.returnItem(newDvd); // Since Bill the Lobster is being returned, it won't be counted when getNumItemsRented is run.
    std::cout << "Returned Bill the Lobster on DVD." << std::endl;

    std::cout << "Here is the amount of items you have rented: " << std::endl;
    std::cout << myCustomer.getNumItemsRented();


return 0;
}