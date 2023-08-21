#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class BubbleSort{
    private:
        int size;
        int capacity;
        int* bubbleArr;

    public:
        BubbleSort(int cap);
        void resize();
        void insert(int key); //inserts at end of ptr
        int search(int key); //return index
        void print(); //prints
        void sort(); //sorts array
        bool isFull();
        int getCapacity();
        int getSize();

};
#endif