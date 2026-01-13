// intlist.cpp
// Implements class IntList
// Jaden Yang/ 1/12/2026

#include "intlist.h"

#include <iostream>
using std::cout;

using namespace std;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;

    head = new Node();
    head->next = nullptr;

    Node* curr_dupe = head;
    Node* source_curr = source.head;

    while(source_curr->next){
        curr_dupe->info = source_curr->info;
        curr_dupe->next = new Node();
        curr_dupe = curr_dupe->next;
        source_curr = source_curr->next;
    }
    curr_dupe->info = source_curr->info;
    tail = curr_dupe;
}

// destructor deletes all nodes
IntList::~IntList() {

    if(!head){
        return;
    }

    Node* iterator = head;
    Node* iterator_dupe = head;
    while(iterator_dupe){
        iterator_dupe = iterator_dupe->next;
        delete iterator;
        iterator = iterator_dupe;
    }
    head = nullptr;
    tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {

    if(!head){
        return 0;
    }

    Node* iterator = head;
    int sum = 0;
    while(iterator){
        sum += iterator->info;
        iterator = iterator->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* iterator = head;
    while(iterator){
        if(iterator->info == value){
            return true;
        }
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(!head){
        return 0;
    }
    Node* iterator = head;
    int max = iterator->info;
    while(iterator){
        if(iterator->info > max){
            max = iterator->info;
        }
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(!head){
        return 0.0;
    }

    return (double(max()) / double(count())); // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    if(head == nullptr){
        head = new Node();
        head->info = value;
        head->next = nullptr;
        tail = head;
    }
    else{
        Node* new_Node = new Node();
        new_Node->info = value;
        new_Node->next = head;
        head = new_Node;
    }
    // IMPLEMENT
}

// append value at end of list
void IntList::push_back(int value) {
    // IMPLEMENT
    if(head == nullptr){
        head = new Node();
        head->info = value;
        head->next = nullptr;
        tail = head;
    }

    else{
        Node* new_Node = new Node();
        new_Node->info = value;
        new_Node->next = nullptr;
        tail->next = new_Node;
        tail = new_Node;
    }
}

// return count of values
int IntList::count() const {
    Node* iterator = head;
    int size = 0;
    while(iterator){
        size++;
        iterator = iterator->next;
    }
   return size;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if(this == &source){
        return *this;
    }
    Node* iterate = head->next;
    Node* before = head;
    while(iterate){
        delete before;
        before = iterate;
        iterate = iterate->next;
    }
    delete before;
    head = nullptr;
    tail = nullptr;

    if(source.head == nullptr){
        return *this;
    }

    Node* source_head = source.head;
    Node* source_tail = source.tail;
    
    head = new Node();
    Node* iterate_head = head;
    while(source_head->next){
        iterate_head->info = source_head->info;
        iterate_head->next = new Node();
        source_head = source_head->next;
        iterate_head = iterate_head->next;
    }

    tail = new Node();
    tail->info = source_head->info;
    tail->next = nullptr;
    iterate_head->next = tail;
    return *this;
    //IMPLEMENT THIS
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = head;
    //IMPLEMENT THIS 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

