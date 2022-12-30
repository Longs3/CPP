#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include<iostream>
#include "Double_node.h"
using namespace std;

template<class T>
class Double_list {
private:
    Double_node<T>* list_head, * list_tail;  // Pointer to the head and tail node
    int len = 0;    // The current size of the list
public:
    Double_list() {}      // Initializing an object with no parameter
    Double_list(const Double_list<T>& temp);    // Initializing an object with the parameter of the object type
    ~Double_list();     // Destructor for deleting the pointer in the list
    int size() const;      // Return the size of the list
    bool empty() const;      // Return true if the list is emtpy and false otherwise
    T front() const;    // Returning the data of the head node
    T back() const;     // Returning the data of the tail node
    Double_node<T>* head() const;   // Returning a pointer of the head node
    Double_node<T>* tail() const;   // Returning a pointer of the tail node
    int count(T) const;     // return the number of node that has that value
    void displayList() const;       // displaying the list from head to tail
    void displayListReverse() const;    // displaing the list from tail to head
    void push_back(T value);        // adding a node at the back of the linked list
    T pop_front();       // removing the first node in the linked list
    void swap(Double_list<T>&);
    int erase(const T&);   // remove the first node that has the same value as the parameter 
    void setHead(Double_node<T>*);
    void setTail(Double_node<T>*);
    template<class E>
    friend ostream& operator<<(ostream& os, Double_list<E>& list);      // displaing the list from head to tail
};

template<class T>
Double_list<T>::Double_list(const Double_list<T>& temp) {       // constructor for copying the linked list
    Double_node<T>* tem = new Double_node<T>;   // creating a new pointer object
    tem = temp.head();      // assigning the pointer object to the argument
    while (tem) {
        push_back(tem->getData());       // adding the node value of the pointer to the new create object
        tem = tem->getNext();        // iterating through the linked list
    }
}

template<class T>
Double_list<T>::~Double_list() { while (!empty()) pop_front(); }    // poping every node untill the list is empty

template<class T>
int Double_list<T>::size() const { return this->len; }      // return the current length of the list

template<class T>
bool Double_list<T>::empty() const { return !len; }     // return true if the list is empty and false otherwise

template<class T>
T Double_list<T>::front() const {       // returning the value of the first node
    if (empty()) cout << "Underflow" << endl;
    return list_head->getData();
}

template<class T>
T Double_list<T>::back() const {        // returning the value of the last node
    if (empty()) cout << "Underflow" << endl;
    return list_tail->getData();
}

template<class T>
Double_node<T>* Double_list<T>::head() const { return list_head; }  // returning a pointer to the first node in the list

template<class T>
Double_node<T>* Double_list<T>::tail() const { return list_tail; }  // returning a pointer to the last node in the list


template<class T>
int Double_list<T>::count(T value) const {      // return the number of node that has that value
    if (empty()) return 0;      // return 0 if the current list is empty
    int ctr = 0;        // create a variable to store the number node that has its data equal the value
    Double_node<T>* temp = new Double_node<T>;      // creating a pointer to iterate through the linked list
    temp = head();      // assigning the pointer to the head of the list
    while (temp) {
        if (temp->getData() == value) ctr++;     // if the node's data has the same value it will increment the ctr
        temp = temp->getNext();      // moving to the next node
    }
    return ctr;
}

template<class T>
void Double_list<T>::displayList() const {      // displaying the list from head to tail
    if (empty()) return;    // end the function if the list is empty
    int ctr = 1;
    Double_node<T>* temp = head();  // assigning the pointer to the head of the list
    cout << "(" << ctr++ << ") " << temp->getData();
    temp = temp->getNext();
    while (temp) {
        cout << " ==> (" << ctr++ << ") " << temp->getData();
        temp = temp->getNext();      // iterating through the list
    }
    cout << endl;
}

template<class T>
void Double_list<T>::displayListReverse() const {   // displaying the list from tail to head
    if (empty()) return;    // end the function if the list is empty
    int ctr = size();
    Double_node<T>* temp = tail();      // assigning the pointer to the tail of the list
    cout << "(" << ctr-- << ") " << temp->getData();
    temp = temp->getPrev();
    while (temp) {
        cout << " <== (" << ctr-- << ") " << temp->getData();
        temp = temp->getPrev();      // iterating through the list
    }
    cout << endl;
}

template<class T>
void Double_list<T>::push_back(T value) {    // adding a node at the back of the linked list
    Double_node<T>* temp = new Double_node<T>;      // creating a new pointer object of the class node
    temp->setData(value);         // giving the pointer node's data to the value
    if (empty()) list_head = list_tail = temp;      // if the list is empty the list_head and list_tail is assign to the pointer temp
    else {
        list_tail->setNext(temp);         // assigning the current list_tail next pointer to the temp pointer
        temp->setPrev(list_tail);     // assigning the temp prev pointer to the temp
        list_tail = temp;       // changing the list_tail pointer to the temp pointer
        list_tail->setData(value);
    }
    cout << value << " has been added" << endl;     // display the value of the current list_tail
    len++;      // increment the size of the list
}

template<class T>
T Double_list<T>::pop_front() {      // removing the first node in the linked list
    if (empty()) {
        cout << "Underflow" << endl;
        return NULL;     // exit the function if the list is empty
    }
    Double_node<T>* temp = head();      // assigning the new pointer node object to the head
    list_head = temp->getNext();     // moving the list_head pointer to next pointer
    T data = temp->getData();
    delete list_head->getPrev();   // deleting all the data at the prev
    list_head->setPrev(NULL);     // assigning the prev pointer of the current list_head to NULL
    len--;          // decrement the list size
    return data;
}

template<class T>
void Double_list<T>::swap(Double_list<T>& list) {
    Double_list<T>* temp = new Double_list<T>;   // Creating a temporary Double_list to store the list_head and list_tail pointer 
    temp->setHead(list.head());      // Storing the list_head pointer
    temp->setTail(list.tail());      // Storing the list_tail pointer
    list.setHead(head());        // Changing the list_head pointer of the parameter to this object list_head pointer 
    list.setTail(tail());        // Changing the list_tail pointer of the parameter to this object list_tail pointer
    setHead(temp->head());       // Changing the list_head pointer of this object to the temp list_head pointer 
    setTail(temp->tail());       // Changing the list_tail pointer of this object to the temp list_tail pointer 
}

template<class T>
int Double_list<T>::erase(const T& value) {    // remove the first node that has the same value as the parameter 
    if (empty()) {          // if the list is emtpy the function exit
        cout << "Underflow" << endl;return 0;
    }
    if (head()->getData() == value) {        // if the head data has the same value it will use the function pop_front() to remove the node
        pop_front();
        cout << value << " has beed erase." << endl;        // display the value that has been removed
        return 1;     // exit the function
    }

    Double_node<T>* temp = new Double_node<T>;      // creating a new pointer for iterating and deleting the node data at the temp location
    temp = head()->getNext();     // assigning the temp value equal to the next node after the head pointer
    while (temp) {      // iterating through the list
        if (temp->getData() == value) {      // if the temp data is equal to the value this block is executed
            Double_node<T>* first, * second;        // creating two pointer for the node after and before the current temp node
            first = second = new Double_node<T>;
            first = temp->getPrev();     // assigning the first node to the previous temp node
            second = temp->getNext();    // assigning the second node to the next temp node

            first->setNext(second);     // changing the first node next pointer to the location of the second node
            second->setPrev(first);      // changing the second node prev pointer to the location of the first node
            len--;          // decrement the list size
            delete temp;       // delete all the data at the temp location 
            return 1;     // exit the function
        }
        temp = temp->getNext();      // moving temp to the next node
    }
    return 0;
}
template<class T>
void Double_list<T>::setHead(Double_node<T>* head) {
    list_head = head;
}
template<class T>
void Double_list<T>::setTail(Double_node<T>* tail) {
    list_tail = tail;
}

template<class E>
ostream& operator<<(ostream& os, Double_list<E>& list) {        // can be use to cout << list;
    list.displayList();         // will display the list from head to tail
    return os;      // a return function of the ostream
}

#endif //DOUBLE_LIST_H
