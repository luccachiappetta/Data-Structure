#include<iostream>
#include "dll.hpp"
using namespace std;

dll::dll(){
    head = NULL;
}

bool dll::isEmpty(){
    return (head == NULL);
}

void dll::insertNode(int key){
    Node* node = new Node;
    node->key = key;
    if(head == NULL){ //if head
        head = node;
        head->next = NULL;
        return;
    }
    else{ //if not head
        Node* curr = head;
        while(curr != NULL){
            if(curr->next == NULL){
                curr->next = node;
                node->prev = curr;
                node->next = NULL;
                return;
            }
            curr = curr->next;
        }
    }
}

void dll::deleteNode(int key){
    if(isEmpty()){ // if empty
        cout<< "List is already empty"<<endl;
        return;
    }
    Node* curr = head;
    Node* prev = NULL;
    //if head
    if(curr->key == key){
        curr = curr->next;
        delete curr;
        return;
    }
    //if not head
    while(curr != nullptr){
        if(curr->key == key){
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    //not found
    cout << "Building does not exist." << endl;
}

Node* dll::search(int key){
    Node* curr = head;
    Node* prev = NULL;
    while(curr != nullptr){
        if(curr->key == key)
            return curr;
        prev = curr;
        curr = curr->next;
    }
    return nullptr;
}

void dll::print(){
    cout << "== CURRENT PATH ==" << endl;
    if(isEmpty()){
        cout << "nothing in path" << endl << "===" << endl;
        return;
    }
    Node* current = head;
    while(current != nullptr){
        cout << current->key << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl << "===" << endl;
}