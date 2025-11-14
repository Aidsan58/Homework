// For merge sort, we only need to find the number of comparisons according to the homework specifications.
int numMergeComparisons = 0; // to be used to find the number of comparisons

// To be used on list 3
// We change all the functions so that they work for arrays rather than linked lists.
// I used the following article as a basis for understanding the algorithm: https://www.geeksforgeeks.org/dsa/merge-sort/
template <class elemType>
void mergeList(elemType list[], int left, int mid, int right)
{
 int size1 = mid - left + 1; // Left is first defined as zero, the index of the first item in the array.
 int size2 = right - mid; // right is defined as the index of the last item in the array, represented by (length - 1).

 // temporary arrays ; these will be deleted when the function has run. We use new because we don't know the size they will be before runtime, so dynamic memory allocation is our friend.
 elemType* tempList1 = new elemType[size1];
 elemType* tempList2 = new elemType[size2];

 // Copy over the data
 for (int i = 0; i < size1; i++) // copy to tempList1
 {
 tempList1[i] = list[left + i];
 }
 for (int i = 0; i < size2; i++) // copy to tempList2
 {
 tempList2[i] = list[mid + i + 1];
 }
 // merge temp arrays back into list
 int i = 0;      // index for tempList1
 int j = 0;      // index for tempList2
 int k = left;   // index for original list
 while (i < size1 && j < size2)
 {
     if (tempList1[i] <= tempList2[j]) // for tempList1
     {
         list[k] = tempList1[i];
         i += 1;
     }
     else // for tempList2
     {
         list[k] = tempList2[j];
         j += 1;
     }
    numMergeComparisons += 1;
 }
 // copy the leftover elements
 while (i < size1) // copy from tempList1 to list
 {
        list[k] = tempList1[i];
        i += 1;
        k += 1;
 }
    while (j < size2) // copy from tempList2 to list
{
        list[k] = tempList2[j];
        j += 1;
        k += 1;
}
 // Clean up memory
 delete[] tempList1;
 delete[] tempList2;
}//end mergeList

// Recursive function
template <class elemType>
void recMergeSort(elemType list[], int left, int right)
{
 if (left < right) 
 {
 int mid = (left + right) / 2; // define the midpoint, which will be moved up as the recursive function is called again and again. This essentially replaces divideList
 recMergeSort(list, left, mid);
 recMergeSort(list, mid + 1, right);
 mergeList(list, left, mid, right);
 }
} //end recMergeSort

template <class elemType>
void mergeSort(elemType list[], int length)
{
 recMergeSort(list, 0, length - 1); // left = 0 and right = length - 1
} //end mergeSort