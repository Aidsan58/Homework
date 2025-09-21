// Derived from checkingAccount

#ifndef NO_SERVICE_CHARGE_CHECKING_H
#define NO_SERVICE_CHARGE_CHECKING_H

#include "checkingAccount.h"

class noServiceChargeChecking : public checkingAccount {
    public:
    double monthlyServiceCharge;
    double interest;
    double minimumBalance;

    // creates Ledger instance
    ledger myLedger[100];
    int ledgerIndex = 0;


    void writeCheck() override {
        double checkSize;
        std::cout << "How much money are you writing the check for?" << std::endl;
        std::cin >> checkSize;
        if ((balance - checkSize) >= minimumBalance) {
            balance -= checkSize;
            std::cout << "Your account balance is now $" << balance << "." << std::endl;
            checkCount += 1;  // Increases the check count to be used by createMonthlyStatement
            myLedger[ledgerIndex] = ledger(checkSize, TransactionType::CHECK);
            ledgerIndex++;
        }
        else {
            std::cout << "You don't have enough funds to write this check." << std::endl;
        }
    }

    void withdrawMoney() override {
        double withdrawalSize;
        std::cout << "How much money do you wish to withdraw?" << std::endl;
        std::cin >> withdrawalSize;
        if ((balance - withdrawalSize) >= minimumBalance) { 
            balance -= withdrawalSize;
            std::cout << "Your account balance is now $" << balance << "." << std::endl;
            withdrawalCount += 1;// Increases the withdrawal count to be used by createMonthlyStatement
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
        std::cout << "You made " << withdrawalCount << " withdrawals, " << depositCount << " deposits, and you wrote " << checkCount << " checks this month." << std::endl;
        std::cout << "Your account balance is now $" << (balance - interest) << "." << std::endl;
    }

    void printLedger();
};

#endif