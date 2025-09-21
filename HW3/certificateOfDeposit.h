// Derived directly from bankAccount

#ifndef CERTIFICATE_OF_DEPOSIT_H
#define CERTIFICATE_OF_DEPOSIT_H

#include "bankAccount.h"

class certificateOfDeposit : public bankAccount {
    public:
    double interestRate = 10;
    int numCDMaturityMonths;
    int currentCDMonth;

    // creates Ledger instance
    ledger myLedger[100];
    int ledgerIndex = 0;

    void withdrawMoney() override {
        double withdrawalSize;
        std::cout << "How much money do you wish to withdraw?" << std::endl;
        std::cin >> withdrawalSize;
        if ((balance - withdrawalSize) >= 0) { 
            balance -= withdrawalSize;
            std::cout << "Your account balance is now $" << balance << "." << std::endl;
            withdrawalCount += 1;
            myLedger[ledgerIndex] = ledger(withdrawalSize, TransactionType::WITHDRAWAL);
            ledgerIndex++;
        }
        else {  // If the withdrawal would bring the account balance to less than zero dollars, the transaction is denied
            std::cout << "You don't have enough funds to withdraw this cash." << std::endl;
        }
    }

    void makeDeposit() override {
        double depositSize;
        std::cout << "How much money do you wish to deposit?" << std::endl;
        std::cin >> depositSize;
        balance += depositSize; // Increases the deposit count to be used by createMonthlyStatement
        std::cout << "Your account balance is now $" << balance << "." << std::endl;
        depositCount += 1;
        myLedger[ledgerIndex] = ledger(depositSize, TransactionType::DEPOSIT);
        ledgerIndex++;
    }

    void createMonthlyStatement() override {
        double interest = interestRate / balance; // Gets the interest for a CD account
        std::cout << "You made " << withdrawalCount << " withdrawals and " << depositCount << " deposits." << std::endl;
        std::cout << "Your account balance is now $" << (balance + interest) << "." << std::endl;
    }

    void printLedger();
};

#endif