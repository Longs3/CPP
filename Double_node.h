//
// Created by LONG on 12/18/2022.
//

#ifndef DOUBLE_NODE_H
#define DOUBLE_NODE_H

template<class T>
class Double_node {
private:
    Double_node<T> *next, *prev;   // Pointer to the next and previous node
    T data;     // Data of the current node
public:
    T getData() const;
    Double_node<T>* getNext();
    Double_node<T>* getPrev();
    void setNext(Double_node<T>*);
    void setPrev(Double_node<T>*);
};

template<class T>
T Double_node<T>::getData() const { return data; }
template<class T>
Double_node<T>* Double_node<T>::getNext() { return next; }
template<class T>
Double_node<T>* Double_node<T>::getPrev() { return prev; }
template<class T>
void Double_node<T>::setNext(Double_node<T>* next) { this->next = next; }
template<class T>
void Double_node<T>::setPrev(Double_node<T>* prev) { this->prev = prev; }

#endif //DOUBLE_NODE_H
