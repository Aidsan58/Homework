int numQuickAssignments = 0; // to be used to find the number of assignments
int numQuickComparisons = 0; // to be used to find the number of comparisons

// To be used on list 1
// Largely unchanged from the texbook, save for assignment and comparison counter variables.
template <class elemType>
void swap(elemType list[], int first, int second)
{
 elemType temp;
 temp = list[first];
 list[first] = list[second];
 numQuickAssignments += 1; // Increase number of assignments
 list[second] = temp;
 numQuickAssignments += 1; // Increase number of assignments
} //end swap

template <class elemType>
int partition(elemType list[], int first, int last)
{
 elemType pivot;
 int smallIndex;
 swap(list, first, (first + last) / 2);
 pivot = list[first];
 smallIndex = first;
 for (int index = first + 1; index <= last; index++)
 if (list[index] < pivot)
 {
 smallIndex++;
 swap(list, smallIndex, index);
 numQuickComparisons += 1; // Increase number of comparisons
 }
 swap(list, first, smallIndex);
 return smallIndex;
}

template <class elemType>
void recQuickSort(elemType list[], int first, int last)
{
 int pivotLocation;
 if (first < last)
 {
 pivotLocation = partition(list, first, last);
recQuickSort(list, first, pivotLocation - 1);
recQuickSort(list, pivotLocation + 1, last);
 }
} //end recQuickSort

template <class elemType>
void quickSort(elemType list[], int length)
{
 recQuickSort(list, 0, length - 1);
} //end quickSort