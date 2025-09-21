#ifndef LEDGER_H
#define LEDGER_H

#include "bankAccount.h"

class ledger {
    public:
    int ledgerIndex = 0;
    double value;
    enum class TransactionType { WITHDRAWAL, DEPOSIT, CHECK };
    TransactionType type;

    ledger(); // default constructor
    ledger(double value, enum TransactionType type); // constructor
    void ledger::printLedger(bankAccount* ptr, ledger myLedger[]);

};

#endif