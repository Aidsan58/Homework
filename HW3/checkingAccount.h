// serviceChargeChecking and noServiceChargeChecking are derived from here
// Abstract class

#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "bankAccount.h"

class checkingAccount : public bankAccount {
    virtual void writeCheck() = 0;
};

#endif