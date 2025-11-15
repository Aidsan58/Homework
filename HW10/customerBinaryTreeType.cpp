#include "customerBinaryTreeType.h"

template <class elemType>
void customerBTreeType<elemType>::rentItem(const elemType& insertItem)
{
insert(InsertItem);
} //end rentItem

template <class elemType>
int customerBTreeType<elemType>::getNumItemsRented() 
{
return treeNodeCount();
} //end getNumItemsRented
