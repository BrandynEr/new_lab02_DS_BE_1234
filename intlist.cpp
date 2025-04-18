// intlist.cpp
// Implements class IntList
// Brandyn Er, April 14, 2025

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) { //source is passed by reference (not as a pointer); another IntList object
    head = nullptr;
    tail = nullptr;
    Node* current = source.head;

    while (current != nullptr) {
        this->push_back(current->info);
        current = current->next;
    }
}


// destructor deletes all nodes
IntList::~IntList() {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr){
        temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
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

//append value at the beginning of the list
void IntList::push_front(int value) {
    Node* newHead = new Node;
    newHead->info = value;
    newHead->next = head;

    head = newHead;

    if (tail == nullptr) {
        tail = newHead;
    }
}


// append value at end of list
void IntList::push_back(int value) {
    Node* end = new Node;
    end->info = value;
    end->next = nullptr;

    if (head == nullptr) {
        head = end;
        tail = end;
        return;
    }

    tail->next = end; // instead of traversing, use tail directly
    tail = end;
}

// return count of values
int IntList::count() const {
    if (head == nullptr){
        return 0;
    }

    int count = 0;
    Node* current = head;

    while (current != nullptr){
        count += 1;
        current = current->next;
    }
    return count;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source) {
    if (this == &source) return *this;  // self-assignment check

    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;

    Node* srcNode = source.head;
    while (srcNode != nullptr) {
        this->push_back(srcNode->info);
        srcNode = srcNode->next;
    }

    return *this;
}



// constructor sets up empty list
IntList::IntList(){ 
   head = nullptr;
   tail = nullptr; 
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
