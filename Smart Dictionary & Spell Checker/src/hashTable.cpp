#include "hashTable.h"

void HashSet::hashInsert(std::unordered_set<std::string> hashSet, std::string entry) {
    hashSet.insert(entry); // Uses built-in insert function, but we make our own so inserting in the hash table doesn't get mixed up with inserting in the Trie.
}