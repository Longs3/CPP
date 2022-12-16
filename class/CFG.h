#ifndef CFG_H
#define CFG_H
#include<iostream>
using namespace std;

struct sentence {
    struct NP nounph;
    struct VP verbph;
    friend ostream& operator<<(sentence& sen) {}
};

struct NP {
    string adj, noun;
};

struct VP {
    string verb;
    struct NP nounph;
};

#endif