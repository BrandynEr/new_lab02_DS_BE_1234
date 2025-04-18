// intlist.cpp
// Implements class IntList
// Brandyn Er, April 14, 2025

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) { //source is passed by reference (not as a pointer); another IntList object
    if (source.head == nullptr){
        head = nullptr;
        return;
    }

    //Copy 1st node
    head = new Node;
    head->info = source.head->info;
    head->next = nullptr;
    Node* current = head;
    Node* nextvalue = source.head->next;

    //Copy rest of the nodes
    while (nextvalue != nullptr){
        current->next = new Node;
        current->next->info = nextvalue->info;
	current->next->next = nullptr;
	
	
	current = current->next;
        nextvalue = nextvalue->next;
    }

    tail = current; //Set tail to last node created; current is pointing to nullptr from the while loop
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* current = head;

    while (current != nullptr){
        sum = sum + current->info;
        current = current->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* current = head;

    while (current != nullptr){
        if (current->info == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (head == nullptr){
        return 0;
    }

    int max = head->info;
    Node* current = head->next;

    while (current != nullptr){
        if (current->info > max) {
            max = current->info;
        }
        current = current->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (head == nullptr){
        return 0;
    }

    double sum = 0;
    double count = 0;
    Node* current = head;

    while (current != nullptr){
        sum = sum + current->info;
        count += 1;
        current = current->next;
    }
    return sum / count;
}

// inserts value as new node at beginning of list    
void IntList::push_front(int value) {
    // IMPLEMENT
}

// append value at end of list
void IntList::push_back(int value) {
    // IMPLEMENT
 
}

// return count of values
int IntList::count() const {
   //IMPLEMENT THIS
   return 0;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
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
