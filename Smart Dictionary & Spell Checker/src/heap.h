#pragma once

#include <string>
#include <vector>
#include <iostream>

class Heap {
    void heapify(std::vector<std::string>& suggestion, int n, int i);
    void heapSort(std::vector<std::string>& suggestion);
    void printHeap(std::vector<std::string>& suggestion);
};