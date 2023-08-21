#include<iostream>
#include "heapsort.hpp"
using namespace std;

//Private Functions
void MinHeap::minHeapify(int i){ //fix
    int left = leftChild(i);
    int right = rightChild(i);
    int smallest = i;
    if(left < currSize && heap[left] < heap[i])
        smallest = left;
    if(right < currSize && heap[right] < heap[i])
        smallest = right;
    
    if(smallest == i)
        return;
    else if(smallest != i){
        swap(heap[i],heap[smallest]);
        minHeapify(smallest);
    }

}
int MinHeap::parent(int index){
    return (index - 1) / 2;
}
int MinHeap::rightChild(int index){
    return 2 * (index + 2);
}
int MinHeap::leftChild(int index){
    return 2 * (index + 1);
}

//Public Functions
MinHeap::MinHeap(int cap){
    currSize = 0;
    capacity = cap;
    heap = new int[capacity];
}
void MinHeap::insert(int key){
    if(currSize < capacity){
        heap[currSize] = key;
        int i = currSize;
        while(currSize != 0 && heap[parent(i)] > heap[i]){
            //repair
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
        currSize++;
    }
    else{
        cout << "Full capacity." << endl;
        return;
    }
}
bool MinHeap::search(int key){
    for (int i = 0; i < currSize; i++){
        if(heap[i] == key)
            return true;
    }
    return false;
}
void MinHeap::printHeap(){
    if(currSize == 0){
        cout << "Heap is Empty. Cannot print" << endl;
        return;
    }
    for (int i = 0; i < currSize; i++){
        cout << heap[i] << endl;
    }
}
void MinHeap::destroyHeap(){
    currSize = 0;
}
int MinHeap::getSize(){
    return currSize;
}
int MinHeap::getCap(){
    return capacity;
}