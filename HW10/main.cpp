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
        std::cin.ignore( 1, '\n' ); // clears istream
        if (response == "1") {
            std::cout << "What item are you renting?" << std::endl;
            dvdType myItem; // name of item user will rent
            cin >> myItem;
            myCustomer.rentItem(myItem);
        }
        else break;
    }
    std::cout << myCustomer.getNumItemsRented();


return 0;
}