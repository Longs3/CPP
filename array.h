/*
    Written by: Seng Long
    Version: 1.0.0
*/

/*
    Description
        This header consist of a class that is used
        for array manipulation.

        The initialization for the object of this class
        take zero or one parameter. If there is zero
        parameter then it will create an empty array.
        If there is one parameter then the argument
        will be reformatted to a vector so that it is
        consistence with the methods inside the class.
*/

// this nee to be recheck
#ifndef ARRAY_H
#define ARRAY_H

#include<bits/stdc++.h>
using namespace std;
// #include"number.h"
/**
 * This list will be all contain the methods inside the class Array
 * for further description read the comment on top of each method
 *
 *
 * append          done
 * assign       done
 * charInt      done
 * indexOf      done
 * insert       done
 * intChar      done
 * len          done
 * permutation  done
 * pop       done
 * reverse      done
 * sort         done
 * split        done
 * swap         done
 * unique       done
 * valueAt      done
 *
 */

template<class T>
class Array {
private:
    vector<T> arr;
public:
    // constructor
    Array() {}
    Array(const vector<T>&);
    Array(T*);
    // destructor
    ~Array();

    // function for the array
    void append(T); /*This append value at the back of the object's array. */
    void append(vector<int>&);
    void assign(int, T);/*The first perameter is to specify the location at which the value is to be place inside the object's array. The second is the value itself.*/
    /*This method will take the object's array(char) and return an object's array(int) if possible. If not, it will return an object's array contain a zero*/
    Array<int> charInt() { Array<char> ans({ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' });Array<int> output, outp({ 0 }); output.pop();for (auto& i : arr) { output.append(ans.indexOf(i)); if (ans.indexOf(i) == -1) return  outp; } return output; }
    int indexOf(T); /*This method will search through the object's array and try to find the value if the value is not found it will return -1.*/
    void insert(int, T); /*This method takes two arguments. The first one is for the position that is to be inserted. If the position is greater than the array length, then the value will be appended to the last index. The second one is the value that is to be inserted*/
    /*This will use the object's array and return an array if the value is convertable else it will return an empty array*/
    Array<char> intChar() { Array<char> ans({ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }), outp;Array<int> check({ 0,1,2,3,4,5,6,7,8,9 }); for (auto& i : arr) if (check.indexOf(i) == -1) return outp; for (auto& i : arr) { outp.append(ans.valueAt(i)); } return outp; }
    int len(); /*This will return the object's array length*/
    vector<vector<T>> permutation();    // This method return all the posible permutation of the current array
    void pop(int);/*This will pop the array item at a specific location. If the location is not specify, it will pop the last item of the object's array.*/
    /*This will reverse the object's array*/
    void reverse() { int ctr = len(); for (int i = 0;i < ctr / 2;i++) { swap(i, ctr - 1 - i); } }

    /*This method will sort the array in ascending order*/
    void sort() { int ctr = len(); for (int i = 0;i < ctr;i++) for (int j = 0;j < ctr - 1;j++) if (valueAt(j) > valueAt(j + 1)) swap(j, j + 1); }

    /*This will take the whole number and convert it into an array of sigle digit*/
    Array<int> split(int x) { Array<int> output;for (;;) { if (x < 10) { output.append(x);break; }output.append(x % 10);x /= 10; }output.reverse();return output; }

    /*This will take the whole string and convert it into an array of character*/
    Array<char> split(string x) { Array<char> output; int ctr = x.length(); for (int i = 0;i < ctr;i++) output.append(x[i]); return output; }
    /*This method swap two item in the array at the two specify locations.*/
    void swap(int , int );
    /*this method will find all the unique item in the array*/
    Array<T> unique();
    /*return the value at the specify index.*/
    T valueAt(int at);
};
template<class T>
Array<T>::Array(const vector<T>& array) {
    for (auto i : array) append(i);
}
template<class T>
Array<T>::Array(T* arr) { int ctr = extent<decltype(arr)>::value;for (int i = 0;i < ctr;i++) this->arr.push_back(arr[i]); }
template<class T>
Array<T>::~Array() { arr.clear(); }
template<class T>
void Array<T>::assign(int at, T value) { arr[at] = value; }
template<class T>
void Array<T>::append(T value) { arr.push_back(value); }
template<class T>
void Array<T>::append(const vector<int>& arr) { for (auto i : arr) this->arr.push_back(i); }
template<class T>
int Array<T>::indexOf(T value) { int ctr = 0; for (auto& i : arr) { if (i == value) return ctr;ctr++; } return -1; }
template<class T>
void Array<T>::insert(int at, T value) { int ctr = len();arr.push_back(valueAt(ctr - 1)); for (int i = ctr - 1;i > at;i--) swap(i, i - 1);assign(at, value); }
template<class T>
int Array<T>::len() { return this->arr.size(); }
template<class T>
void Array<T>::swap(int at, int where) { float temp = valueAt(at); assign(at, valueAt(where));assign(where, temp); }
template<class T>
vector<vector<T>> Array<T>::permutation() {
    int ctr = len(), fac = 1;
    for (int i = 3;i <= ctr;i++) fac *= i;
    vector<vector<T>> temp;temp.push_back(arr);
    for (int i = 0;i < fac - 1;i++) {
        if (valueAt(i) != valueAt(i + 1)) {
            swap(i % ctr, (i + 1) % ctr);
            temp.push_back(arr);
        }
    }
    ctr = temp.size();
    for (int i = 0;i < ctr;i++) {
        Array<T> arra(temp[i]);
        bool isthere = false;
        arra.reverse();
        for (int j = 0;j < temp.size();j++) {
            if (arra.arr == temp[j]) isthere = true;
        }
        if (!isthere)
            temp.push_back(arra.arr);
    }
    return temp;
}
template<class T>
Array<T> Array<T>::unique() { Array<T> temp;int check = 0, ctr = len(), ctr1 = 1;for (int i = 0;i < ctr;i++) { if (temp.len() == 0) temp.append(valueAt(i));for (int j = 0;j < ctr1;j++) { check = temp.indexOf(valueAt(i));if (check == -1) { ctr1++; break; } }if (check == -1)  temp.append(valueAt(i)); }return temp; }
template<class T>
T Array<T>::valueAt(int at) { return arr[at]; }
template<class T>
void Array<T>::pop(int at = -1) { if (at == -1) { arr.pop_back(); return; } int ctr = len(); if (at >= ctr) { arr.pop_back(); return; } for (int i = at;i < ctr - 1;i++) { swap(i, i + 1); } arr.pop_back(); }
#endif