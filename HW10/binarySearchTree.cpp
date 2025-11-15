#include "binarySearchTree.h"

template <class elemType>
void bSearchTreeType<elemType>::insert
 (const elemType& insertItem)
{
 nodeType<elemType> *current; //pointer to traverse the tree
 nodeType<elemType> *trailCurrent = nullptr; //pointer behind current
 nodeType<elemType> *newNode; //pointer to create the node
 newNode = new nodeType<elemType>;
 newNode->info = insertItem;
 newNode->lLink = nullptr;
 newNode->rLink = nullptr;
 if (root == nullptr)
 root = newNode;
 else
 {
 current = root;
 while (current != nullptr)
 {
 trailCurrent = current;
 if (current->info == insertItem)
 {
 cout << "The item to be inserted is already ";
 cout << "in the tree -- duplicates are not "
 << "allowed." << endl;
 return;
 }
 else if (current->info > insertItem)
 current = current->lLink;
 else
 current = current->rLink;
 }//end while
 if (trailCurrent->info > insertItem)
 trailCurrent->lLink = newNode;
 else
 trailCurrent->rLink = newNode;
 }
}//end insert

template <class elemType>
void bSearchTreeType<elemType>::deleteFromTree
 (nodeType<elemType>* &p)
{
 nodeType<elemType> *current; //pointer to traverse the tree
 nodeType<elemType> *trailCurrent; //pointer behind current
 nodeType<elemType> *temp; //pointer to delete the node
 if (p == nullptr)
 cout << "Error: The node to be deleted does not exist."
 << endl;
 else if (p->lLink == nullptr && p->rLink == nullptr)
 {
 temp = p;
 p = nullptr;
 delete temp;
 }
 else if (p->lLink == nullptr)
 {
 temp = p;
 p = temp->rLink;
 delete temp;
 }
 else if (p->rLink == nullptr)
 {
 temp = p;
 p = temp->lLink;
 delete temp;
 }
 else
 {
 current = p->lLink;
 trailCurrent = nullptr;
 while (current->rLink != nullptr)
 {
 trailCurrent = current;
 current = current->rLink;
 }//end while
 ->info = current->info;
 if (trailCurrent == nullptr) //current did not move;
 //current == p->lLink; adjust p
 p->lLink = current->lLink;
 else
 trailCurrent->rLink = current->lLink;
 delete current;
 }//end else
} //end deleteFromTree

template <class elemType>
void bSearchTreeType<elemType>::deleteNode
 (const elemType& deleteItem)
{
 nodeType<elemType> *current; //pointer to traverse the tree
 nodeType<elemType> *trailCurrent; //pointer behind current
 bool found = false;
 if (root == nullptr)
 cout << "Cannot delete from an empty tree."
 << endl;
 else
 {
 current = root;
 trailCurrent = root;
 while (current != nullptr && !found)
 {
 if (current->info == deleteItem)
 found = true;
 else
 {
 trailCurrent = current;
 if (current->info > deleteItem)
 current = current->lLink;
 else
 current = current->rLink;
 }
 }//end while
 if (current == nullptr)
 cout << "The item to be deleted is not in the tree."
 << endl;
 else if (found)
 {
 if (current == root)
 deleteFromTree(root);
 else if (trailCurrent->info > deleteItem)
 deleteFromTree(trailCurrent->lLink);
 else
 deleteFromTree(trailCurrent->rLink);
 }
 else
 cout << "The item to be deleted is not in the tree."
 << endl;
 }
} //end deleteNode