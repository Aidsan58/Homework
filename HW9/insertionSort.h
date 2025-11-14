int numInsertAssignments = 0; // to be used to find the number of assignments
int numInsertComparisons = 0; // to be used to find the number of comparisons

// To be used on list 2
template <class elemType>
void insertionSort(elemType list[], int length)
{
 for (int firstOutOfOrder = 1; firstOutOfOrder < length;
 firstOutOfOrder++)
 if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
 {
 elemType temp = list[firstOutOfOrder];
 int location = firstOutOfOrder;
 numInsertComparisons += 1;
 do
 {
 list[location] = list[location - 1];
 numInsertAssignments += 1;
 location--;
 }
 while(location > 0 && list[location - 1] > temp);
 list[location] = temp;
 numInsertAssignments += 1;
 numInsertComparisons += 1;
 }
} //end insertionSort