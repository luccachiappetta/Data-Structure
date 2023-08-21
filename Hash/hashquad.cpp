#include "hashquad.hpp"
using namespace std;

HashTable::HashTable(int bsize){
    numSearchCollisions = 0;
    numOfCollisions = 0;
    tableSize = bsize;
    table = new Node*[tableSize];
    for(int i = 0; i < bsize; i++)
        table[i] = nullptr;
}

unsigned int HashTable::hashFunction(int key){
    return (key % tableSize);
}

Node* HashTable::search(int key){
    int index = hashFunction(key);

    while(table[index]!= NULL && table[index]->key != key){
        //cout << " not found" << endl;
        numSearchCollisions += 1;
        index = hashFunction(index + 1);
    }
    if(table[index] != NULL && table[index]->key == key){
        //cout << "found" << endl;
        return table[index];
    }
    else
        return NULL;
}

void HashTable::insert(int key){
    int index = hashFunction(key); 
    int count;

    while(table[index] != NULL){
        numOfCollisions++;
        if(table[index]->key == key) //for duplicates
            break;
        count++;
        index = (index + (int)pow(count,2)) % tableSize;
    }
    Node* node = new Node;
    node->key = key;
    node->next = NULL;
    table[index] = node;
}

void HashTable::printTable(){
    for (int i = 0; i <= tableSize; i++) {
        if(table[i] != NULL)
            cout << i << "|" << table[i]->key << "| ";
    }
}
int HashTable::getNumOfCollision(){
    return numOfCollisions;
}

int HashTable::getNumOfSearchCollision(){
    return numSearchCollisions;
}