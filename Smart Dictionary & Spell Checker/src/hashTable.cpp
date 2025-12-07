#include "hashTable.h"

void HashSet::hashInsert(const std::string& entry) {
    table.insert(entry);    // insert into the member hash table, insert() does the same thing but we want to write to the table that the class 'owns'
}

bool HashSet::spellCheck(const std::string& word) {
    return table.find(word) != table.end();
}
