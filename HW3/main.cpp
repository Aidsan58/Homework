#include "bankAccount.h"
#include "savingsAccount.h"
#include "highInterestChecking.h"
#include "certificateOfDeposit.h"
#include "highInterestSavings.h"
#include "noServiceChargeChecking.h"
#include "checkingAccount.h"
#include "serviceChargeChecking.h"

bankAccount* setAccount() {
    std::cout << "What bank account do you wish to open?" << std::endl;
    std::cout << "Press 1 for service charge checking." << std::endl;
    std::cout << "Press 2 for no service charge checking." << std::endl;
    std::cout << "Press 3 for high interest checking." << std::endl;
    std::cout << "Press 4 for certificate of deposit account." << std::endl;
    std::cout << "Press 5 for savings account." << std::endl;
    std::cout << "Press 6 for high interest savings." << std::endl;

    int variable;
    std::cin >> variable;

    for (int i = 1; i < 7; i++) {
        if (i == variable) {
            return new serviceChargeChecking();
        }
        if (i == variable) {
            return new noServiceChargeChecking();
        }
        if (i == variable) {
            return new highInterestChecking;
        }
        if (i == variable) {
            return new certificateOfDeposit;
        }
        if (i == variable) {
            return new savingsAccount;
        }
        if (i == variable) {
            return new highInterestSavings;
        }
        else {
            std::cout << "Option not available" << std::endl;
            return nullptr;
        }
    }
}

int main () {


    

    bankAccount* ptr = &myAccount;

    ptr->name = "Aidan";
    std::cout << "Name: " << ptr->getName() << std::endl;
    ptr->makeDeposit();
    ptr->makeDeposit();

    return 0;
}