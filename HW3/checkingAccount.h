// serviceChargeChecking and noServiceChargeChecking are derived from here
// Abstract class

#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "bankAccount.h"

class checkingAccount : public bankAccount {
    public:
    virtual void writeCheck() = 0;

    int checkCount = 0;

    // Default destructor
    ~checkingAccount() = default;
};

#endif