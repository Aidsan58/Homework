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
    double balance = 0;

    void setData(const std::string& name, const std::string& accountNumber); // This function is here so we can easily set values for instances of subclasses.

    std::string getName();
    std::string getAccountNumber();
    double getBalance();

    virtual void makeDeposit() = 0; // The following three classes will be overridden by all non-abstract classes that are further down the inheritance hierarchy
    virtual void withdrawMoney() = 0;
    virtual void createMonthlyStatement() = 0;

    int withdrawalCount = 0;
    int depositCount = 0;

};

#endif