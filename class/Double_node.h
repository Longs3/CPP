//
// Created by LONG on 12/18/2022.
//

#ifndef DOUBLE_NODE_H
#define DOUBLE_NODE_H

template<class T>
class Double_node {
public:
    Double_node<T> *next, *prev;   // Pointer to the next and previous node
    T data;     // Data of the current node
    Double_node() : next(NULL), prev(NULL), data(NULL) {}   // When an object is initialized everything is NULL
};


#endif //DOUBLE_NODE_H
