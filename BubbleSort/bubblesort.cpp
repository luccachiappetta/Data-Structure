#include<iostream>
#include "bubblesort.hpp"
using namespace std;

BubbleSort::BubbleSort(int cap){
    size = 0;
    capacity = cap;
    bubbleArr = new int[capacity];
}

void BubbleSort::resize(){
    int newCapacity = 100 + capacity;

	int *newArray = new int[newCapacity];

	capacity = newCapacity;
	bubbleArr = newArray;
}

bool BubbleSort::isFull(){
    return(capacity == size);
}
void BubbleSort::insert(int key){
    if(!isFull()){
        bubbleArr[size] = key;
        size++;
    }
}
int BubbleSort::search(int key){
    for(int i = 0; i < size; i++){
        if(key == bubbleArr[i])
            return i;
    }
    return -1;
}
void BubbleSort::print(){
    for(int i = 0; i < size; i++){
        cout << bubbleArr[i] << endl;
    }
}
void BubbleSort::sort(){
    int temp;
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++){
            if (bubbleArr[j] >= bubbleArr[i]){
                temp = bubbleArr[i];
                bubbleArr[i] = bubbleArr[j];
                bubbleArr[j] = temp;
            }
        }
    }
}
int BubbleSort::getCapacity(){
    return capacity;
}
int BubbleSort::getSize(){
    return size;
}