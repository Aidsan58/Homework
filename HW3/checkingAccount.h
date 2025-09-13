// serviceChargeChecking and noServiceChargeChecking are derived from here
// Abstract class

#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "bankAccount.h"

class checkingAccount : public bankAccount {
    public:
    virtual void writeCheck() = 0; // Only classes derived from checkingAccount should have the function writeCheck()

    int checkCount = 0; // This variable is only used in classes derived from checkingAccount. Its value is assigned here

};

#endif