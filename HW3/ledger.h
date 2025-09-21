#ifndef LEDGER_H
#define LEDGER_H

class ledger {
    public:
    double value = 0;
    enum class TransactionType { WITHDRAWAL, DEPOSIT, CHECK }; // we create an enum so we can differentiate between the three transaction types
    TransactionType type;                                      // CHECK won't be used by some classes, but this is fine

    ledger() {  // default constructor
    // empty
}

    ledger(double value, enum TransactionType type); // constructor

};

#endif