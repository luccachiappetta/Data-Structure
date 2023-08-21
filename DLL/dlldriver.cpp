#include "dll.hpp"
#include <chrono>
using namespace std::chrono;

int randomNumbers(int min, int max) {
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

int main(int argc, char* argv[]){
    int testData[10000];
    float insertArr[100];
    float searchArr[100];

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

    //insert into linked list and calc
    dll list;
    high_resolution_clock::time_point start, end; //create and restart time
    duration <double> execTime;
    
    for (int i = 0; i < 100; i++){ //first for loop to store at indices
        //insert
        start = high_resolution_clock::now(); //start time
        for (int j = i * 100; j < (i * 100) + 100; j++){ //run 100 inserts starting at next facor of 100
            list.insertNode(testData[j]);
        }
        end = high_resolution_clock::now(); //stop time
        execTime = duration_cast<nanoseconds>(end - start); //calc execute time
        insertArr[i] = execTime.count() / (float) 100; //insert at index of first loop

        //search
        start = high_resolution_clock::now(); //start timn
        for (int j = 0; j < 100; j++){
            int randNum = randomNumbers(0, ((i * 100) + 100) - 1); //number generator that increments based on the first loop
            list.search(testData[randNum]); //search
        }
        end = high_resolution_clock::now(); //stop time
        execTime = duration_cast<nanoseconds>(end - start); //calc execute time
        searchArr[i] = execTime.count() / (float) 100; //store time
        //cout << " end Exec time: " << execTime.count() << " seconds" << endl;
    }

    ofstream toFile;
    toFile.open("dllData.csv"); //create search time file
    if(toFile.is_open()){
        toFile << "Iterations,Search,Insert" << endl;
        for(int i = 0; i < 100; i++){
            toFile << i << "," << searchArr[i] << "," << insertArr[i] <<endl; //iterate through array and write to file
        }
    }
    toFile.close();
}
//g++ -std=c++11 dll.cpp dlldriver.cpp -o dlldriver.o
//./dlldriver.o dataSetA.csv