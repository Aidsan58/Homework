#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream> // for file reading
#include <cstdlib> // for exit()
#include "trie.h"
#include "hashTable.h"
#include "heap.h"


void loadFile(const std::string& filename, HashSet& set, Trie& trie);
void processUserInput(HashSet& set, Trie& trie);

int main() {

    
    HashSet set;
    Trie trie;

    //loadFile("dictionary.txt", set, trie);

    while (true) {
        processUserInput(set, trie);
    }

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

    // LOAD [filename]
    if (command.rfind("LOAD ", 0) == 0) {
        std::string filename = input.substr(5); // the filename should be the characters after "LOAD "

        // trim filename
        //filename.erase(0, filename.find_first_not_of(" \t"));
        //filename.erase(filename.find_first_not_of(" \t") + 1);

        if (filename.empty()) {
            std::cerr << "No filename found." << std::endl;
            return;
        }

        loadFile(filename, set, trie);
    }

    // CHECK [word]
    else if (command.rfind("CHECK ", 0) == 0) {
        std::string word = input.substr(6); // the word should be the characters after "CHECK "

        // trim word
        //word.erase(0, word.find_first_not_of(" \t"));
        //word.erase(word.find_first_not_of(" \t") + 1);

        if (set.spellCheck(word) == false) {
            std::cout <<  word << " is misspelled." << std::endl;
            return;
        }
        if (set.spellCheck(word) == true) {
            std::cout << word << " is spelled correctly." << std::endl;
            return;
        }


    }

    // SUGGEST [prefix]
    else if (command.rfind("SUGGEST ", 0) == 0) {
        std::string prefix = input.substr(8); // the suggestion should be the characters after "SUGGEST "

        // trim prefix
        //prefix.erase(0, prefix.find_first_not_of(" \t"));
        //prefix.erase(prefix.find_first_not_of(" \t") + 1);

        Heap heap; // make a heap for the suggestions

        std::vector<std::string> suggestion = trie.suggest(prefix); // write suggestions to the heap

        heap.printHeap(suggestion); // prints suggestions

        return;

    }

    // HELP
    else if (command.rfind("HELP", 0) == 0) {
        std::cout << "Here is a list of commands: " << std::endl;

        std::cout << "LOAD [filename]: Load dictionary data from a specified text file (see Section III) into both the Trie and the Hash Table.\nCHECK [word]:\
 Perform a spell check.\
\nSUGGEST [prefix]: Use the Trie to find and print up to 5 suggested words that start with the given prefix.\nHELP: Display a list of available commands.\nEXIT: \
Terminate the program." << std::endl;

         return;
    }

    // EXIT
    else if (command.rfind("EXIT", 0) == 0) {
        std::cout << "Exiting program." << std::endl;
        exit(0);
    }

    else 
        std::cout << "Unknown command." << std::endl;
}