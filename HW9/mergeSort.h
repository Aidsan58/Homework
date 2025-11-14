// For merge sort, we only need to find the number of comparisons.
int numMergeComparisons = 0; // to be used to find the number of comparisons

// To be used on list 3
template <class elemType>
void divideList(elemType list[], int length)
{
 nodeType<Type>* middle;
 nodeType<Type>* current;
 if (first1 == nullptr) //list is empty
 first2 = nullptr;
 else if (first1->link == nullptr) //list has only one node
 first2 = nullptr;
 else
 {
 middle = first1;
 current = first1->link;
 if (current != nullptr) //list has more than two nodes
 current = current->link;
 while (current != nullptr)
 {
 middle = middle->link;
 current = current->link;
 if (current != nullptr)
 current = current->link;
 } //end while
 first2 = middle->link; //first2 points to the first
 //node of the second sublist
 middle->link = nullptr; //set the link of the last node
 //of the first sublist to nullptr
 } //end else
} //end divideList

template <class elemType>
void mergeList(elemType list[], int length)
{
 nodeType<Type> *lastSmall; //pointer to the last node of
 //the merged list
 nodeType<Type> *newHead; //pointer to the merged list
 if (first1 == nullptr) //the first sublist is empty
 return first2;
 else if (first2 == nullptr) //the second sublist is empty
 return first1;
 else
 {
 if (first1->info < first2->info) //compare the
 //first nodes
 {
 newHead = first1;
 first1 = first1->link;
 lastSmall = newHead;
 }
 else
 {
 newHead = first2;
 first2 = first2->link;
 lastSmall = newHead;
 }
 while (first1 != nullptr && first2 != nullptr)
 {
 if (first1->info < first2->info)
 {
 lastSmall->link = first1;
 lastSmall = lastSmall->link;
 first1 = first1->link;
 }
 else
 {
 lastSmall->link = first2;
 lastSmall = lastSmall->link;
 first2 = first2->link;
 }
 } //end while
 if (first1 == nullptr) //first sublist exhausted first
 lastSmall->link = first2;
 else //second sublist exhausted first
 lastSmall->link = first1;
 return newHead;
 }
}//end mergeList

template <class elemType>
void recMergeSort(elemType list[], int length)
{
 nodeType<Type> *otherHead;
 if (head != nullptr) //if the list is not empty
 if (head->link != nullptr) //if the list has more than
 //one node
 {
 divideList(head, otherHead);
 recMergeSort(head);
 recMergeSort(otherHead);
 head = mergeList(head, otherHead);
 }
} //end recMergeSort

template <class elemType>
void mergeSort(elemType list[], int length)
{
 recMergeSort(first);
 if (first == nullptr)
 last = nullptr;
 else
 {
 last = first;
 while (last->link != nullptr)
 last = last->link;
 }
} //end mergeSort