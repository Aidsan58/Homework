#ifndef LEDGER_CPP
#define LEDGER_CPP

#include <iostream>
#include "ledger.h"


ledger::ledger(double value, enum TransactionType type) {
    this->value = value;
    this->type = type;
}

#endif