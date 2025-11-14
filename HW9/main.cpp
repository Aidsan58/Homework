#include <iostream>
//C++11: Random number generator.
#include <random>

//header files
#include "quickSort.h"
#include "insertionSort.h"
//#include "mergeSort.h"

int main()
{
    int list1[5000]; // uses quick sort
    int list2[5000]; // uses insertion sort
    int list3[5000]; // uses merge sort

    // Use a random number generator to make an unsorted array of integers between one and 5000.
    std::random_device rdevice{};
    std::default_random_engine num{ rdevice() };
    std::uniform_int_distribution<unsigned int> randomNum{1, 5000};

    // Assigns a value using the random number generator we just defined to the array, one by one.
    for (unsigned int count = 0; count < 5000; count++) {
        list1[count] = randomNum(num);
    }

    // Once list1 is generated, set list2 and list3 equal to list1
    list2[5000] = list1[5000];
    list3[5000] = list1[5000];

    // Sort list1 using quick sort
    quickSort(list1, 5000);
    std::cout << "Number of assignments using quick sort: " << numQuickAssignments << std::endl;
    std::cout << "Number of comparisons using quick sort: " << numQuickComparisons << std::endl;

    // Sort list2 using insertion sort
    insertionSort(list2, 5000);
    std::cout << "Number of assignments using insertion sort: " << numInsertAssignments << std::endl;
    std::cout << "Number of comparisons using insertion sort: " << numInsertComparisons << std::endl;

    return 0;
}