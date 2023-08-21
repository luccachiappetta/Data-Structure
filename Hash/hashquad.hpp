#ifndef HASHQUAD_HPP
#define HASHQUAD_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Node
{
    int key;
    struct Node* next;
};

class HashTable
{
    private:
        int tableSize;
        int numOfCollisions;
        int numSearchCollisions;
        Node* *table;
        
    public:
        // Constructor
        HashTable(int bsize);

        // hash function to map values to key
        unsigned int hashFunction(int key);

        //traversal functions
        void insert(int key);
        Node* search(int key);
        void printTable();

        int getNumOfCollision();
        int getNumOfSearchCollision();
};
#endif