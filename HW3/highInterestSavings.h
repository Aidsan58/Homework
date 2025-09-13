// Derived from savingsAccount

#ifndef HIGH_INTEREST_SAVINGS_H
#define HIGH_INTEREST_SAVINGS_H

#include "savingsAccount.h"

class highInterestSavings : public savingsAccount {
    public:
    double interest = 8;


    void withdrawMoney() override {
        double withdrawalSize;
        std::cout << "How much money do you wish to withdraw?" << std::endl;
        std::cin >> withdrawalSize;
        if ((balance - withdrawalSize) >= 0) { 
            balance -= withdrawalSize;
            std::cout << "Your account balance is now $" << balance << "." << std::endl;
            withdrawalCount += 1;
        }
        else {  // If the withdrawal would bring the account balance to less than minimumBalance, the transaction is denied
            std::cout << "You don't have enough funds to withdraw this cash." << std::endl;
        }
    }

    void makeDeposit() override {
        double depositSize;
        std::cout << "How much money do you wish to deposit?" << std::endl;
        std::cin >> depositSize;
        balance += depositSize;
        std::cout << "Your account balance is now $" << balance << "." << std::endl;
        depositCount += 1;
    }

    void createMonthlyStatement() override {
        std::cout << "You made " << withdrawalCount << " withdrawals and " << depositCount << " deposits." << std::endl;
        std::cout << "Your account balance is now $" << (balance + interest) << "." << std::endl;
    }
};

#endif