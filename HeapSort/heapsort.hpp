#ifndef MINHEAP_HPP
#define MINHEAP_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class MinHeap{
    private:
        int* heap;
        int capacity;
        int currSize;
        void minHeapify(int index);
        int parent(int index);
        int rightChild(int index);
        int leftChild(int index);

    public:
        MinHeap(int cap);
        void destroyHeap();
        void insert(int key);
        bool search(int key);
        void printHeap();
        int getSize();
        int getCap();
};
#endif