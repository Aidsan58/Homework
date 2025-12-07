#pragma once

#include <iostream>
#include <unordered_set>
#include <string>

struct HashSet {
    std::unordered_set<std::string> table;   // store the words

    void hashInsert(const std::string& entry);
    bool spellCheck(const std::string& word);
};
