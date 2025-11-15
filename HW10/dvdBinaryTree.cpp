#include "dvdBinaryTree.h"

void dvdBinaryTree::searchDVDList(string title,
 bool& found,
 nodeType<dvdType>* &current) const
{
 found = false;

 dvdType temp;
 temp.setDVDInfo(title, "", "", "", "", "", 0);
 if (root == nullptr) //tree is empty
 cout << "Cannot search an empty list. " << endl;
 else
 {
 current = root; //set current point to the root node
 //of the binary tree
 found = false; //set found to false
 while (current != nullptr && !found) //search the tree
 if (current->info == temp) 
 found = true; //item is found
 else if (current->info > temp)
 current = current->lLink;
 else
 current = current->rLink;
 } //end else
} //end searchDVDList
void dvdBinaryTree::inorderTitle
 (nodeType<dvdType> *p) const
{
 if (p != nullptr)
 {
 inorderTitle(p->lLink);
 p->info.printTitle();
 inorderTitle(p->rLink);
 }
}
void dvdBinaryTree::dvdPrintTitle() const
{
 inorderTitle(root);
}