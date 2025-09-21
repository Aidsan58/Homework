#ifndef BANK_ACCOUNT_CPP
#define BANK_ACCOUNT_CPP

#include "bankAccount.h"

void bankAccount::setData(const std::string& name, const std::string& accountNumber) {
    this->name = name; // The 'name' parameter has the same value as 'name' in bankAccount. 'this' is  a pointer to bankAccount
    this->accountNumber = accountNumber;
} // We take care of balance separately in the class body itself

std::string bankAccount::getName() {
    return name;
}

std::string bankAccount::getAccountNumber() {
    return accountNumber;
}

double bankAccount::getBalance() {
    return balance;
}

/*void bankAccount::printLedger() {
    // empty

}*/

#endif