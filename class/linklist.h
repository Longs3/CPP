#ifndef LINKLIST_H
#define LINKLIST_H

#include<iostream>
using namespace std;

template<typename T>
class LinkList {
private:
    T data;
    LinkList<T>* next;
public:
    LinkList(T value) : next(NULL), data(value) {}
    LinkList() : next(NULL) {}
    ~LinkList() { while (!isEmpty()) removeFront(); }
    void addFront(T value) { LinkList<T>* v = new LinkList(data); v->next = next;next = v;data = value; }
    bool isEmpty() { return next == NULL; }
    LinkList<T>* getNext() { return next; }
    T value() { return data; }
    void removeFront() {
        data = next->data;
        next = next->next;
        delete next->next;
    }
    int indexOf(T value) {
        LinkList<T>* temp= next;
        while(temp->data != value || temp->getNext() != NULL) {
            
        }
    }
    friend ostream& operator<<(ostream& os, LinkList<T>& demo) {
        os << demo.value();
        LinkList<T>* temp = demo.getNext();
        while (temp->getNext() != NULL) {
            os << "->" << temp->value();
            temp = temp->getNext();
        }
        return os;
    }
};
#endif

