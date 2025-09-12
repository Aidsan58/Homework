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
        }
        else {
            std::cout << "You don't have enough funds to withdraw this cash." << std::endl;
        }

    }
};

#endif