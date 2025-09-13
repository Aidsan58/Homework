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

    if (variable == 1) {
        return new serviceChargeChecking();
    }
    if (variable == 2) {
        return new noServiceChargeChecking();
    }
    if (variable == 3) {
        return new highInterestChecking();
    }
    if (variable == 4) {
        return new certificateOfDeposit();
    }
    if (variable == 5) {
        return new savingsAccount();
    }
    if (variable == 6) {
        return new highInterestSavings();
    }
    std::cout << "Option not available" << std::endl;
    return nullptr;
}

int main () {

    bankAccount* ptr = setAccount();
    ptr->setData("Aidan", "109402353");


    std::cout << "Name: " << ptr->getName() << std::endl;
    std::cout << "Account number: " << ptr->getAccountNumber() << std::endl;
    ptr->makeDeposit();
    ptr->withdrawMoney();

    checkingAccount* myPtr = dynamic_cast<checkingAccount*>(ptr); // If the user has a checking account, the program makes a dynamic cast conversion from *bankAccount to *checkingAccount
    if (myPtr) {
        myPtr->writeCheck();
        myPtr->createMonthlyStatement();
        return 0;
    }
    ptr->createMonthlyStatement();

    return 0;
}