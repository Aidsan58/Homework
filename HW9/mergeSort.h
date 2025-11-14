// For merge sort, we only need to find the number of comparisons.
int numMergeComparisons = 0; // to be used to find the number of comparisons

// To be used on list 3
// We change all the functions so that they work for arrays rather than linked lists. I moved them around to make more sense to me
template <class elemType>
void mergeSort(elemType list[], int length)
{
 recMergeSort(list, 0, length - 1);
} //end mergeSort

// Recursive function
template <class elemType>
void recMergeSort(elemType list[], int left, int right)
{
 if (left < right) 
 {
 int mid = (left + right) / 2;
 recMergeSort(list, left, mid);
 recMergeSort(list, mid + 1, right);
 mergeList(list, left, mid, right);
 }
} //end recMergeSort

template <class elemType>
void mergeList(elemType list[], int left, int mid, int right)
{
 int size1 = mid - left + 1;
 int size2 = right - mid;

 // temporary arrays
 elemType* tempList1 = new elemType[size1];
 elemType* tempList2 = new elemType[size2];

 // Copy over the data
 for (int i = 0; i < length i++) {
    if (i < size1) {
        tempList1[i] = list[i];
    }
    else {
        tempList2[i - size1] = list[i]; // Once we exceed the size of size1, we start copying to tempList2
    }
 }

 // merge back into list[left..right]
  for (int i = 0; i < length i++) {
    if (i < size1) {
        list[i] = tempList1[i];
    }
    else {
        list[i] = tempList2[i - size1]; // Once we exceed the size of size1, we start copying from tempList2
    }
 }

 // copy the leftover elements
 delete tempList1;
 delete tempList2;

}//end mergeList