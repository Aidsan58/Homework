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

    std::string getName();
    std::string getAccountNumber();
    double getBalance();

    virtual void makeDeposit() = 0;
    virtual void withdrawMoney() = 0;
    virtual void createMonthlyStatement() = 0;

    ~bankAccount() = default;

};

#endif