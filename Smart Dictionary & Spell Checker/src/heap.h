#pragma once

#include <string>
#include <vector>
#include <iostream>

class Heap {
    public:
    void printHeap(std::vector<std::string>& suggestion);
    private:
    void heapify(std::vector<std::string>& suggestion, int n, int i);
    void heapSort(std::vector<std::string>& suggestion);
    
};