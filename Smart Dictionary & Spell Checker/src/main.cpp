#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include "trie.h"
#include "hashTable.h"
#include "heap.h"


void loadFile(const std::string& filename, HashSet& set, Trie& trie);
void processUserInput(HashSet& set, Trie& trie);

int main() {

    
    HashSet set;
    Trie trie;
    Heap heap;

    loadFile("dictionary.txt", set, trie);
    std::vector<std::string> suggestion = trie.suggest("app");
    heap.printHeap(suggestion);

    return 0;
}

void loadFile(const std::string& filename, HashSet& set, Trie& trie) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file: " << filename << std::endl;
        return; // return early if we don't have a valid file or there is some other issue
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        set.hashInsert(line);
        trie.insert(line);
    }
}

void processUserInput(HashSet& set, Trie& trie) {
    std::string input;

    std::cout << ">";
    std::getline(std::cin, input);

    std::string command = input;

    if (command.rfind("LOAD ", 0) == 0) {
        std::string filename = input.substr(5); // the filename should be the characters after "LOAD "

        // trim filename
        filename.erase(0, filename.find_first_not_of("\t"));
        filename.erase(filename.find_first_not_of("\t") + 1);

        if (filename.empty()) {
            std::cerr << "No filename found." << std::endl;
            return;
        }

        loadFile(filename, set, trie);
    }
    else 
        std::cout << "Unknown command." << std::endl;
}