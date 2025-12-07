#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include "trie.h"
#include "hashTable.h"
#include "heap.h"


void loadFile(const std::string& filename, HashSet& set, Trie& trie);

int main() {

    
    HashSet set;
    Trie trie;
    Heap heap;

    loadFile("dictionary.txt", set, trie);
    std::vector<std::string> suggestion = trie.suggest("exx");
    heap.heapSort(suggestion);
    heap.printHeap(suggestion);

    return 0;
}

void loadFile(const std::string& filename, HashSet& set, Trie& trie) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file: " << filename << std::endl;
        return; // return early if we don't have a valid file or there is some other issue
    }

    std::unordered_set<std::string> hashSet; // hash set that we use to write to our class

    std::string line;
    while (std::getline(inputFile, line)) {
        set.hashInsert(hashSet, line);
        trie.insert(line);
    }
}
