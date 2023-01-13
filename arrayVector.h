#ifndef ARRAYVECTOR_H
#define ARRAYVECTOR_H

#include<iostream>
using namespace std;

template<class T>
class arrayVector {
private:
    int capacity, n;
    T* V;
public:
    arrayVector();
    arrayVector(int);
    int size() const;      // Return the number of elements in V
    bool empty() const;       // Return true if V is empty and false otherwise
    void resize(int);       // Resize V, so that it has space for n elements
    void reserve(int);       // Request that the allocated storage space be large enough to hold n elemnets.
    T& operator[](int);     // Return a reference to the ith elemnt of V
    T& at(int) const;          // Same as V[i], but throw an out_of_range exception if i is out of bounds.
    T& front() const;
    T& back() const;
    void push_back(T);
    void pop_back();
    void earse(int i);
};
template<class T>
arrayVector<T>::arrayVector(): capacity(0), n(0), V(NULL) {}

template<class T>
arrayVector<T>::arrayVector(int size): capacity(size), n(0), V(NULL) {}
template<class T>
T arrayVector<T>::operator[](int i) const { return V[i];}
template<class T>
int arrayVector<T>::size() const { return this->n;} 
template<class T>
bool arrayVector<T>::empty() const { return size() == 0; }
template<class T>



#endif