#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H
#include<iostream>
using namespace std;

template<typename T>
struct doublelinklist {
    T data;
    doublelinklist<T>* next, * back;
};
template<typename T>
class DoubleLinkList {
    public:
    doublelinklist<T> * front, * rear;
    DoubleLinkList() { front = rear = NULL; }
    void insert(T n);
    void deleteitem(int);
    void displayrev();
    void display();
    ~DoubleLinkList();
};
template<typename T>
void DoubleLinkList<T>::insert(T n) {
    doublelinklist<T>* temp = new doublelinklist<T>;
    if (temp == NULL) {
        cout << "Overflow" << endl;
        return;
    }
    temp->data = n;
    temp->next = temp->back = NULL;
    if(front==NULL) {
        front = rear = temp;
    } else {
        front->back = temp;
        temp->next = front;
        front = temp;
    }
    cout << n << " has been added\n";
}
template<typename T>
void DoubleLinkList<T>::deleteitem(int at=0) {
    if(at ==0) {
        DoubleLinkList<T>* temp = 
    }
}


#endif