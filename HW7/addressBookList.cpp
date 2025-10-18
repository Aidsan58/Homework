#include "addressBookList.h"

void addressBookList::insertAddress(const addressType& newAddress) {
    Node *newNode = new Node(newAddress); //create newNode
    if (!head) {
        head = newNode; // If the head of the list hasn't been defined (this should mean the list is empty), we make newAddress the head of the linked list
    }
    else {              // If the head has been defined, we insert newAddress after whatever the last entry is
        Node* p = head; // Temporary variable that maps to head
        while (p->next) { // We keep iterating until p->next is invalid, which probably means it returns nullptr
            p = p->next;
        }
        p->next = newNode; // Once we reach the end, we insert newNode at the end
    }

}

void addressBookList::deleteAddress(const addressType& removeAddress) {
        Node* p = head; // Temp var
        Node* prev = nullptr;

        while (p != nullptr && p->info.streetAddress != removeAddress.streetAddress) { // Checks to see if p matches the address we want to remove
            prev = p;                                                                  // if not found, keeps searching
            p = p->next;
        }

        if (p == nullptr) { // If the address doesn't point to anything, we know we've reached the end, and the address we want to remove has not been located
            std::cout << "Address not found." << std::endl;
            return;
        }

        if (prev == nullptr) {
            head = p->next; // Define the head (there's obviously no previous entry because this is the first)
        } else {
            prev->next = p->next; // If we found the address we're looking for, we basically pop it out of the list by linking the previous entry and the next entry together
        }

        std::cout << "Deleted street address: " << removeAddress.streetAddress << std::endl;
        delete p; // Clears temporary variable from memory
}

void addressBookList::print() {
        Node* p = head;
        if (p == nullptr) { // If the linked list is empty
            std::cout << "Address book is empty." << std::endl;
            return;
        }

        while (p != nullptr) { // While p is not nullptr
            std::cout << "Address: " << p->info.streetAddress << std::endl; // Prints the address of an entry
            p = p->next; // Goes to the next entry
        }
    }