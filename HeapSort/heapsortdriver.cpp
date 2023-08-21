#include "heapsort.hpp"
#include<iostream>
#include <chrono>
using namespace std::chrono;

int main(int argc, char* argv[]){

    int testData[10000];
    float sortArr[100];
    
    //insert in array
    int index;
    string line;
    ifstream myFile;
    myFile.open(argv[1]); //takes in file name through command line
    if(myFile.is_open()){
        while(getline(myFile,line,',')){
            testData[index] = stoi(line); //place each number in each slot of array
            index++;
        }
    }

    MinHeap myHeap(10000);
    high_resolution_clock::time_point start, end; //create and restart time
    duration <double> execTime;

    for (int i = 0; i < 100; i++){ //first for loop to store at indices
        myHeap.destroyHeap(); //empty heap to insert 100 times index

        start = high_resolution_clock::now(); //start time
        for (int j = 0; j < (i * 100) + 100; j++){ //run 100 sorts and times it
            myHeap.insert(testData[j]); //insert and sorts into the heap
        }
        end = high_resolution_clock::now(); //stop time

        execTime = duration_cast<nanoseconds>(end - start); //calc execute time
        sortArr[i] = execTime.count();
    }
    //myHeap.printHeap();

    //sort
    ofstream toFile;
    toFile.open("heapSortData.csv"); //create search time file
    if(toFile.is_open()){
        toFile << "Iterations,Time" << endl;
        for(int i = 0; i < 100; i++){
            toFile << i << ", " << sortArr[i] << endl; //iterate through array and write to file
        }
    }
    toFile.close();
}
//g++ -std=c++11 heapsort.cpp heapsortdriver.cpp -o heapsortdriver.o
//./heapsortdriver.o dataSetA.csv