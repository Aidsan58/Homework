#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "binaryTreeType.h"

template <class elemType>
class bSearchTreeType: public binaryTreeType<elemType>
{
public:
 bool search(const elemType& searchItem) const;
 //Function to determine if searchItem is in the binary
 //search tree.
 //Postcondition: Returns true if searchItem is found in
 // the binary search tree; otherwise,
 // returns false.
 void insert(const elemType& insertItem);
 //Function to insert insertItem in the binary search tree.
 //Postcondition: If there is no node in the binary search
 // tree that has the same info as
 // insertItem, a node with the info
 // insertItem is created and inserted in the
 // binary search tree.
 void deleteNode(const elemType& deleteItem);
 //Function to delete deleteItem from the binary search tree
 //Postcondition: If a node with the same info as
 // deleteItem is found, it is deleted from
 // the binary search tree.
 // If the binary tree is empty or deleteItem
 // is not in the binary tree, an appropriate
 // message is printed.
private:
 void deleteFromTree(nodeType<elemType>* &p);
 //Function to delete the node to which p points is
 //deleted from the binary search tree.
 //Postcondition: The node to which p points is
 // deleted from the binary search tree.
};

#endif