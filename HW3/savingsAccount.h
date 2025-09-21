// Derives from bankAccount, highInterestSavings is derived from here

#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "bankAccount.h"

class savingsAccount : public bankAccount {
    public:
    double interest = 5;

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
        depositCount += 1; // Increases the deposit count to be used by createMonthlyStatement
        myLedger[ledgerIndex] = ledger(depositSize, TransactionType::DEPOSIT);
        ledgerIndex++;
    }

    void createMonthlyStatement() override {
        std::cout << "You made " << withdrawalCount << " withdrawals and " << depositCount << " deposits." << std::endl;
        std::cout << "Your account balance is now $" << (balance + interest) << "." << std::endl; // We add interest at the end
    }

    void printLedger();

};

#endif