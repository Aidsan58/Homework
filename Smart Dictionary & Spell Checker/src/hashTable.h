#pragma once

#include <iostream>
#include <unordered_set>
#include <string>

struct HashSet {
    private:
    std::unordered_set<std::string> table;   // store the words
    public:
    void hashInsert(const std::string& entry);
    bool spellCheck(const std::string& word);
};
