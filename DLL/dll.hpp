#ifndef DLL_HPP
#define DLL_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


struct Node{
    int key;
    Node* next;
    Node* prev;
};

class dll {
    private:
        Node* head;

    public:
        dll();
        bool isEmpty();
        void insertNode(int key);
        void deleteNode(int key);
        Node* search(int key);
        void print();
};
#endif