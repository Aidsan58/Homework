#include <iostream>
#include "ledger.h"

ledger::ledger() {
    // empty
}

ledger::ledger(double value, enum TransactionType type) {
    this->value;
    this->type;
}

// Ledger
void ledger::printLedger(bankAccount* ptr, ledger myLedger[]) {
    for (int i = 0; i < 100; i++) {
        if (myLedger[i].type == ledger::TransactionType::WITHDRAWAL) {
            std::cout << ptr->getName() << " withdrew $" << myLedger[i].value << "." << std::endl;
        }
        if (myLedger[i].type == ledger::TransactionType::DEPOSIT) {
            std::cout << ptr->getName() << " deposited $" << myLedger[i].value << " into their account." << std::endl;
        }
        if (myLedger[i].type == ledger::TransactionType::CHECK) {
            std::cout << ptr->getName() << " wrote a check for $" << myLedger[i].value << "." << std::endl;
        }
    }
}