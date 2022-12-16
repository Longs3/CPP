#ifndef SET_H
#define SET_H
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Set {
private:
    vector<T> set;
public:
    // finding the size of the set
    auto len() -> int const { return set.size(); }
    // finding the index of the value
    int indexOf(T value) const { int ctr = 0; for (auto i : set) { if (i == value) return ctr;else ctr++; } return -1; }
    // return the value at the specified index
    T valueOf(int at) { return set[at]; }
    // adding value to the set if the value exist somewhere in the set it will not be added
    void add(T value) { for(auto i: set) if(ctr==value)return;set.push_back(value);sort(set.begin(), set.end());}
    
};

#endif