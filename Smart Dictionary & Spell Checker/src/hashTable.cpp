#include "hashTable.h"



void HashSet::hashInsert(std::unordered_set<std::string> hashSet, std::string entry) {
    hashSet.insert(entry);
}