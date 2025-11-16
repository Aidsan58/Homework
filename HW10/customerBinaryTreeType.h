#ifndef CUSTOMER_BINARY_TREE_TYPE_H
#define CUSTOMER_BINARY_TREE_TYPE_H

#include "binarySearchTree.h"

template <class elemType>
class customerBTreeType: public bSearchTreeType<elemType>
{
 public:
 // customer can rent a DVD. calls insert()
 void rentItem(const elemType& insertItem);
 // gets the number of items rented per customer. calls treeNodeCount()
 int getNumItemsRented();
 // allows the customer to return a DVD. uses deleteNode
 void returnItem(const elemType& deleteItem);
 //Default constructor
 customerBTreeType();
};

template <class elemType>
void customerBTreeType<elemType>::rentItem(const elemType& insertItem)
{
this->insert(insertItem);
} //end rentItem

template <class elemType>
int customerBTreeType<elemType>::getNumItemsRented() 
{
return this->treeNodeCount(); // specify declaration
} //end getNumItemsRented

template <class elemType>
void customerBTreeType<elemType>::returnItem(const elemType& deleteItem) 
{
this->deleteNode(deleteItem);
} //end getNumItemsRented

template <class elemType>
customerBTreeType<elemType>::customerBTreeType() {}

#endif