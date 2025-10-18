#ifndef ADDRESS_BOOK_LIST_H
#define ADDRESS_BOOK_LIST_H

#include "addressType.h"

struct Node {
    addressType info;
    Node *next;

    Node(const addressType& myAddress) { // Constructor for adding an address (as in home address) as a node
        info = myAddress;
        next = nullptr;
    }
};

class addressBookList {
    private: Node* head = nullptr; // We declare the head of the list and initialize it to nullptr to prevent undefined behavior
    public:
        void insertAddress(const addressType& newAddress); // Declare insertMember function to add a new address to the linked list
        void deleteAddress(const addressType& removeAddress); // Declare deleteMember function to remove a given address from the linked list
        void print(); // Prints the street address of all the entries
};

#endif