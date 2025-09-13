// Derived from checkingAccount

#ifndef SERVICE_CHARGE_CHECKING_H
#define SERVICE_CHARGE_CHECKING_H

#include "checkingAccount.h"

class serviceChargeChecking : public checkingAccount {
    public:
    double monthlyServiceCharge;



    void writeCheck() override {
        double checkSize;
        std::cout << "How much money are you writing the check for?" << std::endl;
        std::cin >> checkSize;
        if ((balance - checkSize) >= 0) {
            balance -= checkSize;
            std::cout << "Your account balance is now $" << balance << "." << std::endl;
            checkCount += 1;
        }
        else {
            std::cout << "You don't have enough funds to write this check." << std::endl;
        }
    }

    void withdrawMoney() override {
        double withdrawalSize;
        std::cout << "How much money do you wish to withdraw?" << std::endl;
        std::cin >> withdrawalSize;
        if ((balance - withdrawalSize) >= 0) { 
            balance -= withdrawalSize;
            std::cout << "Your account balance is now $" << balance << "." << std::endl;
            withdrawalCount += 1;
        }
        else {  // If the withdrawal would bring the account balance to less than zero dollars, the transaction is denied
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
        std::cout << "You made " << withdrawalCount << " withdrawals, " << depositCount << " deposits, and you wrote " << checkCount << " checks this month." << std::endl;
        std::cout << "Your account balance is now $" << balance << "." << std::endl;
    }
};

#endif