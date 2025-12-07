#pragma once

#include <string>
#include <vector>

struct Node {
    char letter;
    bool isEndOfWord;

    Node* child;
    Node* sibling;

    Node(char c) {
        letter = c;
        isEndOfWord = false;
        child = nullptr;
        sibling = nullptr;
    }
};

// Left Child Right Sibling Trie
class Trie {
public:
    Node* root;

    Trie() {
        root = new Node('0');
    }

    void insert(const std::string& word);
    Node* findSibling(Node* node, char c);
    Node* searchPrefix(const std::string& prefix);
    void collectWords(Node* node,std::string current, std::vector<std::string>& results);
    std::vector<std::string> suggest(const std::string& prefix);



};