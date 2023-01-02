#ifndef DOUBLE_NODE_H
#define DOUBLE_NODE_H

template<class T>
class Double_node {
private:
    Double_node<T>* next, * prev;   // Pointer to the next and previous node
    T data;     // Data of the current node
public:
    Double_node(): data(NULL), next(NULL), prev(NULL) {}
    T getData() const;      // Retrieving the data of the current node
    void setData(T);        // Setting the data of the current node
    Double_node<T>* getNext() const;    // Retriving the next pointer of the current node
    Double_node<T>* getPrev() const;    // Retriving the prev pointer of the current node
    void setNext(Double_node<T>*);      // Setting the next pointer to a specific node
    void setPrev(Double_node<T>*);      // Setting the prev pointer to a specific node
};

template<class T>
T Double_node<T>::getData() const { return data; }
template<class T>
void Double_node<T>::setData(T value) { this->data = value; }
template<class T>
Double_node<T>* Double_node<T>::getNext() const { return next; }
template<class T>
Double_node<T>* Double_node<T>::getPrev() const { return prev; }
template<class T>
void Double_node<T>::setNext(Double_node<T>* next) { this->next = next; }
template<class T>
void Double_node<T>::setPrev(Double_node<T>* prev) { this->prev = prev; }

#endif //DOUBLE_NODE_H
