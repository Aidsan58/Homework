#include "binaryTreeType.h"

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
 return (root == nullptr);
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
 root = nullptr;
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
 inorder(root);
}
template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
 preorder(root);
}
template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
 postorder(root);
}
template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
 return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
 return nodeCount(root);
}
template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
 return leavesCount(root);
}
template <class elemType>
void binaryTreeType<elemType>::inorder
 (nodeType<elemType> *p) const
{
 if (p != nullptr)
 {
 inorder(p->lLink);
 cout << p->info << " ";
 inorder(p->rLink);
 }
}
template <class elemType>
void binaryTreeType<elemType>::preorder
 (nodeType<elemType> *p) const
{
 if (p != nullptr)
 {
 cout << p->info << " ";
 preorder(p->lLink);
 preorder(p->rLink);
 }
}
template <class elemType>
void binaryTreeType<elemType>::postorder
 (nodeType<elemType> *p) const
{
 if (p != nullptr)
 {
 postorder(p->lLink);
 postorder(p->rLink);
 cout << p->info << " ";
 }
}
template<class elemType>
int binaryTreeType<elemType>::height
 (nodeType<elemType> *p) const
{
 if (p == nullptr)
 return 0;
 else
 return 1 + max(height(p->lLink), height(p->rLink));
}
template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
 if (x >= y)
 return x;
 else
 return y;
}

// nodeCount function
 //Function to determine the number of nodes in
 //the binary tree to which p points.
 //Postcondition: The number of nodes in the binary
 // tree to which p points is returned.
template <class elemType>
int binaryTreeType<elemType>::nodeCount
 (nodeType<elemType> *p) const
{
int nodeCount = 0;
elemType *myRoot = p;
while (p != nullptr) {
    p = p->lLink;
    nodeCount += 1;
 }
 p = myRoot;
 while (p != nullptr) {
    p = p->lLink;
    nodeCount += 1;
 }
 return nodeCount;
}