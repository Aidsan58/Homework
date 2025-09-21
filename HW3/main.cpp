#include "bankAccount.h"
#include "bankAccount.cpp"
#include "savingsAccount.h"
#include "highInterestChecking.h"
#include "certificateOfDeposit.h"
#include "highInterestSavings.h"
#include "noServiceChargeChecking.h"
#include "checkingAccount.h"
#include "serviceChargeChecking.h"
#include "ledger.cpp"

bankAccount* setAccount() { // Returns a pointer to bankAccount. The type depends on user input which determines the return value
    std::cout << "What bank account do you wish to open?" << std::endl;
    std::cout << "Press 1 for service charge checking." << std::endl;
    std::cout << "Press 2 for no service charge checking." << std::endl;
    std::cout << "Press 3 for high interest checking." << std::endl;
    std::cout << "Press 4 for certificate of deposit account." << std::endl;
    std::cout << "Press 5 for savings account." << std::endl;
    std::cout << "Press 6 for high interest savings." << std::endl;

    int variable;
    std::cin >> variable; // user input

    if (variable == 1) { // Checks to see if user input matches the value for the account type. Does this for every account type until the right one is found
        return new serviceChargeChecking(); // Memory is allocated when the program executes rather than at compile time, so the keyword 'new' is used
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
    return nullptr; // if the user didn't input a valid option the function returns a pointer pointing to nothing
}

int main () {

    // creates Ledger instance
    ledger myLedger[100];

    bankAccount* ptr = setAccount();
    ptr->setData("Aidan", "109402353");


    std::cout << "Name: " << ptr->getName() << std::endl;
    std::cout << "Account number: " << ptr->getAccountNumber() << std::endl;
    ptr->makeDeposit();
    ptr->withdrawMoney();

    checkingAccount* myPtr = dynamic_cast<checkingAccount*>(ptr); // If the user has a checking account, the program makes a dynamic cast conversion from *bankAccount to *checkingAccount
    if (myPtr) {                                                  // This way we can call writeCheck()
        myPtr->writeCheck();
        myPtr->createMonthlyStatement(); // There are multiple versions of createMonthlyStatement, but it should only be called once
        return 0;
    }
    ptr->createMonthlyStatement();

    // Ledger
    for (int i = 0; i < 100; i++) {
        if (myLedger[i].type == WITHDRAWAL) {
            std::cout << ptr->getName() << " withdrew $" << myLedger.value << "." << std::endl;
        }
        if (myLedger[i].type == DEPOSIT) {
            std::cout << ptr->getName() << " deposited $" << myLedger.value << " into their account." << std::endl;
        }
        if (myLedger[i].type == CHECK) {
            std::cout << ptr->getName() << " wrote a check for $" << myLedger.value << "." << std::endl;
        }
    }

    delete[] ptr; // deletes the instance of the class from memory

    return 0;
}