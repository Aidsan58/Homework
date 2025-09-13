// The one from which all others derive
// Abstract class

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <string>

class bankAccount {
    public:
    std::string name;
    std::string accountNumber;
    double balance;

    void setData(const std::string& name, const std::string& accountNumber);

    std::string getName();
    std::string getAccountNumber();
    double getBalance();

    virtual void makeDeposit() = 0;
    virtual void withdrawMoney() = 0;
    virtual void createMonthlyStatement() = 0;

    int withdrawalCount = 0;
    int depositCount = 0;

};

void bankAccount::setData(const std::string& name, const std::string& accountNumber) {
    this->name = name;
    this->accountNumber = accountNumber;
}

std::string bankAccount::getName() {
    return name;
}

std::string bankAccount::getAccountNumber() {
    return accountNumber;
}

double bankAccount::getBalance() {
    return balance;
}

#endif