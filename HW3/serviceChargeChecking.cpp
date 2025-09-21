#include "serviceChargeChecking.h"

// prints alll the array elements in ledger
void serviceChargeChecking::printLedger() {
    for (int i = 0; i < ledgerIndex; i++) {
        if (myLedger[i].type == ledger::TransactionType::WITHDRAWAL) {
            std::cout << getName() << " withdrew $" << myLedger[i].value << "." << std::endl;
        }
        if (myLedger[i].type == ledger::TransactionType::DEPOSIT) {
            std::cout << getName() << " deposited $" << myLedger[i].value << " into their account." << std::endl;
        }
        if (myLedger[i].type == ledger::TransactionType::CHECK) {
            std::cout << getName() << " wrote a check for $" << myLedger[i].value << "." << std::endl;
        }
    }
}