#include "trie.h"

void Trie::insert(const std::string& word) {
    Node* current = root;

    for (char c : word) {
        if (!current->child) {
            current->child = new Node(c);
            current = current->child; // current node is now the child that the node was pointing to
        }
        else {
            current = findSibling(current->child, c);
        }
    }
    current->isEndOfWord = true; // when the for loop is done, we quality the last node with a 'true' which says that character is the end of the word
}

Node* Trie::findSibling(Node* node, char c) {
    Node* previous = nullptr;
    Node* current = node;

    while (current && current->letter != c) {
        previous = current;
        current = current->sibling;
    }

    if (current) {
        return current;
    }

    current = new Node(c); // if not found we make a new sibling
    previous->sibling = current;
    return current;
}

std::vector<std::string> Trie::suggest(const std::string& prefix) {
std::vector<std::string> results;

Node* node = searchPrefix(root, prefix);
if (!node) return results;

collectWords(node->child, prefix, results);

// limit to 5 suggestions
if (results.size() > 5)
    results.resize(5);

return results;
}

void Trie::collectWords(Node* node,std::string current, std::vector<std::string>& results) {
if (!node) return;

current.push_back(node->letter);

if (node->isEndOfWord)
    results.push_back(current);

collectWords(node->child, current, results);
collectWords(node->sibling, current.substr(0, current.size() - 1), results);
}

Node* Trie::searchPrefix(const std::string& prefix) {
Node* current = root;

for (char c : prefix) {
    current = current->child;

    // search among siblings
    while (current && current->letter != c)
        current = current->sibling;

    if (!current)
        return nullptr;
}

return current; // last character node of prefix
}