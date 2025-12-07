#include "heap.h"

// Here we sort the five (or fewer) suggestions so that they are in alphabetical order
void Heap::heapify(std::vector<std::string>& suggestion, int n, int i) {
    
    // initialize largest as root
    int largest = i;

    // left index
    int llink = 2 * i + 1;

    // right index
    int rlink = 2 * i + 2;

    // if left child is larger than root
    if (llink < n && suggestion[llink] > suggestion[largest])
        largest = llink;
    
    // if right child is larger than largest
    if (rlink < n && suggestion[rlink] > suggestion[largest])
        largest = rlink;

    // if largest is not root
    if (largest != i) {
        swap(suggestion[i], suggestion[largest]);
        heapify(suggestion, n, largest); // recursive function call
    }

}

void Heap::heapSort(std::vector<std::string>& suggestion) {

    int n = suggestion.size();

    // build heap to rearrange vector
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(suggestion, n, i);

    // extract elements from heap element by element
    for (int i = n - 1; i > 0; i--) {
        swap(suggestion[0], suggestion[i]); // move current root to end
        heapify(suggestion, i, 0); // call max heapify on reduced heap
    }

}

void Heap::printHeap(std::vector<std::string>& suggestion) {
    std::cout << "Here is the list of suggestions: " << std::endl;
    for (int i = 0; i < suggestion.size(); i++) {
        std::cout << suggestion[i] << std::endl;
    }
}