#include "binarySearchTree.h"

template <class elemType>
class customerBTreeType: public bSearchTreeType<elemType>
{
 public:
 // customer can rent a DVD. calls insert()
 void rentItem(const elemType& insertItem);
 // gets the number of items rented per customer. calls treeNodeCount()
 int getNumItemsRented();
};