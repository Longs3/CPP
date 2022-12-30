#ifndef SET_H
#define SET_H
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Set {
private:
    vector<T> set;
public:
    Set();
    Set(const Set<T>& );
    T pop();
    void add(T);
    void add(const Set<T>&);
};

#endif