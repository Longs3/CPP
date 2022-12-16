#ifndef DATASTRUCTRUE_H
#define DATASTRUCTRUE_H
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
class Solution {
    
    // Problem 1    light bulbs
    int swichBult(const vector<bool>& arr) {
        int times = 0;
        for(auto i: arr) {
            if (times%2!=0) i = !i;

            if (i == 0) times +=1 ;
        }
    }

    // Problem 2    find highest product of n element in an array arr
    long high(vector<double> arr, int n) {
        int size = arr.size();  // finding the size of the array
        if (size < n) return 0;
        long value = 0, temp;   // for storing temp value and highest value
        sort(arr.begin(), arr.end());       // sorting an arry
        for (int i = 0;i < n;i++) {         // loop through all the possible cases
            temp = 1;
            for (int j = 0;j < n;j++) {     // finding the sum in each cases
                temp *= arr[(size + i - n + j) % size];
            }
            value = max(value, temp);       // replacing value with the highest between the current value and the temp value
        }
        return value;   // returning the highest value in the array
    }
    
};


#endif