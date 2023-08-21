#include "bubblesort.hpp"
#include <iostream>
#include <chrono>
using namespace std::chrono;

int main(int argc, char* argv[]){
    int testData[10000];
    float sortArr[100];

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

    BubbleSort bubble(100); //create bubble arr
    high_resolution_clock::time_point start, end; //create and restart time
    duration <double> execTime;

    for (int i = 0; i < 100; i++){ //first for loop to store at indices
        //cout <<  "capacity: " << bubble.getCapacity() << " size: " << bubble.getSize() << endl;
        if(bubble.isFull()){
            bubble.resize();
        }
        for (int j = 0; j < i * 100; j++){ //insert 100 numbers at a time
            bubble.insert(testData[j]);
        }

        start = high_resolution_clock::now(); //start time 
        bubble.sort();
        end = high_resolution_clock::now(); //stop time

        execTime = duration_cast<nanoseconds>(end - start); //calc execute time
        sortArr[i] = execTime.count();
    }

    ofstream toFile;
    toFile.open("bubbleSortData.csv"); //create search time file
    if(toFile.is_open()){
        toFile << "Iterations,Time" << endl;
        for(int i = 0; i < 100; i++){
            toFile << i << ", " << sortArr[i] << endl; //iterate through array and write to file
        }
    }
    toFile.close();
}
//g++ -std=c++11 bubblesort.cpp bubblesortdriver.cpp -o bubblesortdriver.o
//./bubblesortdriver.o dataSetA.csv