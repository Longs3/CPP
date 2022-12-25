#ifndef LINKLIST_H
#define LINKLIST_H

#include<iostream>
using namespace std;

template<class T>
class Node {
    public:
    T data;
    Node<T>* prev;

};


template<class T>
class Stack {
private:
    Node<T>* stack_tail;
    int len;
public:
    Stack();
    Stack(const Stack<T>&);
    ~Stack();
    int size()const;
    bool isEmpty() const;
    T top() const;        // returning the data at the top of the stack
    Node<T>* tail()const;    // returning the pointer to the last item of the stack
    int count(T)const;   // returning the number of time this value occure
    void display()const;
    void add(T);
    void pop();
    template<class E>
    friend ostream& operator<<(ostream& os, const Stack<E>& stack);
};

template<class T>
Stack<T>::Stack(): stack_tail(NULL), len(0) {}
template<class T>
Stack<T>::Stack(const Stack<T>& stack) {
    Node<T>* temp = new Node<T>;
    temp = tail();
    while (temp) {
        add(temp->data);
        temp = temp->prev;;
    }
}
template<class T>
Stack<T>::~Stack() {
    while (!isEmpty()) pop();
}
template<class T>
int Stack<T>::size() const { return this->len; }
template<class T>
bool Stack<T>::isEmpty() const { return !size();}
template<class T>
T Stack<T>::top() const { return tail()->data; }
template<class T>
Node<T>* Stack<T>::tail() const { return stack_tail; }
template<class T>
int Stack<T>::count(T value) const {
    if(isEmpty()) return 0;
    Node<T>* temp = new Node<T>;
    int ctr =0;
    temp = tail();
    while(temp) {
        if(temp->data == value) ctr++;
        temp = temp->prev;;
    }
}
template<class T>
void Stack<T>::display() const {
    if(isEmpty()) return;
    Node<T>* temp = new Node<T>;
    temp = tail();
    cout << "--> (" << temp->data << ") <";
    temp = temp->prev;;
    while(temp) {
        cout << "--" << temp->data;
        temp = temp->prev;;
    }    
    if(size()==1) cout << "--";
    cout << endl;
}
template<class T>
void Stack<T>::add(T value) {
    Node<T>* temp = new Node<T>;
    temp->data = value;
    temp->prev = stack_tail;
    stack_tail = temp;
    len++;
}
template<class T>
void Stack<T>::pop() {
    if(isEmpty()) return;
    Node<T>* temp = new Node<T>;
    temp = tail();
    stack_tail = temp->prev;
    delete temp;
    len--;
}
template<class E>
ostream& operator<<(ostream& os, const Stack<E>& stack) {
    stack.display();
    return os;
}

#endif