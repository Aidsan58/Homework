#pragma once

#include <string>

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
        root = new Node('origin');
    }

    void insert(const std::string& word) {
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

    Node* findSibling(Node* node, char c) {
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

}