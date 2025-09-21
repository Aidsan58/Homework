#include <iostream>
#include "ledger.h"

void ledger::insertEnd(int insertItem, double value, enum TransactionType type)
{
    list[length] = insertItem; //insert the item at the end
    length++; //increment the length
    this->value;
    this->type;
}

ledger::ledger() {
    // empty
}

ledger::ledger(int size) // Taken from page 884 of textbook (C++ Programming)
 : ledger(size)
{
} //end constructor