#ifndef LEDGER_H
#define LEDGER_H

#include "bankAccount.h"

class ledger {
    public:
    double value = 0;
    enum class TransactionType { WITHDRAWAL, DEPOSIT, CHECK };
    TransactionType type;

    ledger() {  // default constructor
    // empty
}

    ledger(double value, enum TransactionType type); // constructor

};

#endif