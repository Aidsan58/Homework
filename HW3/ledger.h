#ifndef LEDGER_H
#define LEDGER_H

class ledger {
    double value;
    enum class TransactionType { WITHDRAWAL, DEPOSIT, CHECK };
    TransactionType type;

    ledger(double value, enum TransactionType type);
};

#endif