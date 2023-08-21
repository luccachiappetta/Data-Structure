#include "hashquad.hpp"
#include <chrono>
using namespace std::chrono;

int randomNumbers(int min, int max) { //random number function
    return (rand() % (max-min+1)) + min;
}

int main(int argc, char* argv[]){
    int testData[10000];
    float insertArr[100];
    float searchArr[100];
    int searchCol[100];
    int insertCol[100];

    //insert in array
    int index;
    string line;
    ifstream myFile;
    myFile.open(argv[1]); //open file
    if(myFile.is_open()){
        while(getline(myFile,line,',')){ //place each number in each slot of array
            testData[index] = stoi(line);
            index++;
        }
    }


    //insert into hash and calc
    HashTable myTable(40009); //create hash table with size
    high_resolution_clock::time_point start, end; //create 
    duration <double> execTime;

    for (int i = 0; i < 100; i++){ //first for loop to store at indices
        //insert
        start = high_resolution_clock::now(); //start clock
        for (int j = i * 100; j < (i * 100) + 100; j++){ //second for loop to track time per 100 inserts
            myTable.insert(testData[j]); //insert into hash
        }
        end = high_resolution_clock::now(); //stop clock
        execTime = duration_cast<nanoseconds>(end - start); //calc execute time
        insertArr[i] = execTime.count() / (float) 100; //insert into the array at index from first loop

        if(i == 0)
            insertCol[i] = myTable.getNumOfCollision();
        else
            insertCol[i] = myTable.getNumOfCollision() - insertCol[i - 1]; //subtracts number of collisions from previous loop


        //search
        start = high_resolution_clock::now(); //start clock
        for (int i = 0; i < 100; i++){
            int randNum = randomNumbers(0, ((i * 100) + 100) - 1); //number generator that increments based on the first loop
            myTable.search(testData[randNum]);//search
        }
        end = high_resolution_clock::now(); //end clock

        execTime = duration_cast<nanoseconds>(end - start); //calc execute time
        searchArr[i] = execTime.count() / (float) 100; //insert into the array at index from first loop
        if(i == 0)
            searchCol[i] = myTable.getNumOfSearchCollision();
        else
            searchCol[i] = myTable.getNumOfSearchCollision() - searchCol[i - 1]; //subtracts number of collisions from previous loop
    }

    //search file
    ofstream toFile;
    toFile.open("hashData.csv"); //create file for search times
    if(toFile.is_open()){
        toFile << "Iterations,Search,Insert" << endl;
        for(int i = 0; i < 100; i++){
            toFile << i << "," << searchArr[i] << "," << insertArr[i] << endl; //write index and stored times to file
        }
    }
    toFile.close();

    //search collisions
    ofstream toFile3;
    toFile3.open("hashCollisions.csv"); //create file for search collisions
    if(toFile3.is_open()){
        toFile3 << "Iterations,Search Collisions,Insert Collisions" << endl;
        for(int i = 0; i < 100; i ++){
            toFile3 << i << "," << searchCol[i] << "," << insertCol[i] << endl; //write index per 100 and stored collisions to file
        }
    }
    toFile3.close();
}
//g++ -std=c++11 hashquad.cpp hashquaddriver.cpp -o hashquaddriver.o
//./hashquaddriver.o dataSetA.csv