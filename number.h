#ifndef NUMBER_H
#define NUMBER_H

#include<bits/stdc++.h>
using namespace std;

/**
 * random
 * floor
 * number system need alot of fixing
 * prime number
 *
 */
template<typename T>
int indexOf(const vector<T>& arr, const T& value) {
    int ctr = 0, index = -1;
    for (auto x : arr) {
        if (x == value) return ctr;
        ctr++;
    }
    return index;
}


class Number {
public:
    int random(int end) {
        srand(time(0));
        int start = 0;
        if (start < 0 || end < 0) return rand();
        if (start == 0 && end == 0) return  rand();
        else if (start == 0) return rand() % end + 1;
        else return rand() % (end - start) + start;
    }
    int highestDivisor(int x, int y) {
        int rem;
        while(y!=0) {
            rem = x%y;
            x = y;
            y = rem;
        }
        return y;
    }
    int random(int start, int end) {
        srand(time(0));
        if (start < 0 || end < 0) return rand();
        if (start == 0 && end == 0) return  rand();
        else if (start == 0) return rand() % end + 1;
        else return rand() % (end - start) + start;
    }
    int floor(double x) { return (int)x; }
    int ceiling(double x) { return (int)x + 1; }
    bool isPrime(short x) {
        if (x < 2) return false;
        if (x <= 3) return true;
        if (x % 2 == 0) return false;
        for (short i = 5;i * i <= x;i += 6) if (x % i == 0 || x % (i + 2) == 0) return false;
        return true;
    }
    bool isPrime(int x) {
        if (x < 2) return false;
        if (x <= 3) return true;
        if (x % 2 == 0) return false;
        for (int i = 5;i * i <= x;i += 6) if (x % i == 0 || x % (i + 2) == 0) return false;
        return true;
    }
    bool isPrime(long long x) {
        if (x < 2) return false;
        if (x <= 3) return true;
        if (x % 2 == 0) return false;
        for (long long i = 5;i *i<=x;i += 6) if (x % i == 0 || x % (i + 2) == 0) return false;
        return true;
    }
    vector<int> allPrime(int num) { vector<int> arri; for (int i = 2;i <= num;i++) if (isPrime(i))arri.push_back(i);return arri; }
    auto countPrime(int num) { int ctr;for (int i = 2;i <= num;i++) if (isPrime(num))ctr++;return ctr; }
    int factorial(int num) {
        if (num < 0) return 0;
        if (num == 0) return 1;
        for (int i = num - 1;i > 1;i++) {
            num *= i;
        }
        return num;
    }
    int round(double num) { return ((num - (int)num) < 0.5) ? (int)num : (int)num + 1; }
    int stringNum(const string str_number) { stringstream converter(str_number);int result;return converter >> result ? result : 0; }
    template<typename T>
    string numString(const T number) { stringstream converter;converter << number;return converter.str(); }
    vector<int> decimalToBinary(int num) {
        vector<int> arr;
        for (;;) {
            if (num == 1) { arr.push_back(1); break; }
            if (num == 0) break;
            arr.push_back(num % 2);
            num /= 2;
        }
        vector<int> temp;
        for (auto back = rbegin(arr); back != rend(arr); back++)
            temp.push_back(*back);
        return temp;
    }
    vector<int> decimalToOctal(int num) {
        vector<int> arri;
        for (;;) {
            if (num == 0) break;
            if (num < 8) { arri.push_back(num);break; }
            arri.push_back(num % 8);
            num /= 8;
        }
        vector<int> temp;
        for (auto back = rbegin(arri); back != rend(arri); back++)
            temp.push_back(*back);
        return temp;
    }
    vector<char> decimalToHexa(int num) {
        vector<char>ans{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' }, arrc;
        for (;;) {
            if (num == 0) break;
            if (num < 16) { arrc.push_back(ans[num]); break; }
            arrc.push_back(ans[num % 16]);
            num /= 16;
        }
        vector<char> temp;
        for (auto back = rbegin(arrc); back != rend(arrc); back++)
            temp.push_back(*back);
        return temp;
    }
    int binaryToDecimal(vector<int> arr) {
        int ctr = arr.size();
        int value = 0;
        for (int i = 0;i < ctr;i++) {
            if (arr[i] != 1 && arr[i] != 0) return 0;
            value += arr[i] * pow(2, ctr - 1 - i);
        }
        return value;
    }
    int binaryToDecimal(vector<char> arr) {
        vector<int> arri;
        int ctr = arr.size();
        for (int i = 0;i < ctr;i++) {
            if (arr[i] != '1' && arr[i] != '0') return 0;
            (arr[i] == '1') ? arri.push_back(1) : arri.push_back(0);
        }
        return binaryToDecimal(arri);
    }
    vector<int> binaryToOctal(vector<int> arr) { return decimalToOctal(binaryToDecimal(arr)); }
    vector<int> binaryToOctal(vector<char> arr) { return decimalToOctal(binaryToDecimal(arr)); }
    vector<char> binaryToHexa(vector<int> arr) {
        return decimalToHexa(binaryToDecimal(arr));
    }
    vector<char> binaryToHexa(vector<char> arr) {
        return decimalToHexa(binaryToDecimal(arr));
    }

    int octalToDecimal(vector<int> arr) {
        vector<int> ans{ 0,1,2,3,4,5,6,7 };
        int ctr = arr.size();
        for (int i = 0;i < ctr;i++) if (indexOf(ans, arr[i]) == -1) return 0;
        int value = 0;
        int po = 0;
        for (int i = ctr - 1;i >= 0;i--) value += arr[i] * pow(8, po++);
        return value;
    }
    int octalToDecimal(vector<char> arr) {
        vector<int> arri;
        vector<char> ans{ '0', '1', '2', '3', '4', '5', '6', '7' };
        int ctr = arr.size();
        for (int i = 0;i < ctr;i++) if (indexOf(ans, arr[i]) == -1) return 0;
        vector<int> check({ 0,1,2,3,4,5,6,7 });

        for (int i = 0;i < ctr;i++) arri.push_back(check[indexOf(ans, arr[i])]);
        return octalToDecimal(arri);
    }
    vector<int> octalToBinary(vector<int> arr) { return decimalToBinary(octalToDecimal(arr)); }
    vector<int> octalToBinary(vector<char> arr) { return decimalToBinary(octalToDecimal(arr)); }

    vector<char> octalToHexa(vector<int> arr) { return decimalToHexa(octalToDecimal(arr)); }
    vector<char> octalToHexa(vector<char> arr) { return decimalToHexa(octalToDecimal(arr)); }

    int hexaToDecimal(vector<char> arr) {
        vector<char> ans{ '0', '1', '2', '3', '4', '5', '6', '7','8','9', 'a', 'b', 'c', 'd', 'e', 'f' };
        int ctr = arr.size();
        for (int i = 0;i < ctr;i++) if (indexOf(ans, arr[i]) == -1) return 0;
        int value = 0, po = 0;
        for (int i = ctr - 1;i >= 0;i--) value += indexOf(ans, (char)tolower(arr[i])) * pow(16, po++);
        return value;
    }
    int hexaToDecimal(vector<int> arr) {
        vector<int> ans{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
        int ctr = arr.size();
        for (int i = 0;i < ctr;i++) if (indexOf(ans, arr[i]) == -1) return 0;
        int value = 0, po = 0;
        for (int i = ctr - 1;i >= 0;i--) value += indexOf(ans, arr[i]) * pow(16, po++);
        return value;
    }
    vector<int> hexaToBinary(vector<char> arr) { return decimalToBinary(hexaToDecimal(arr)); }
    vector<int> hexaToOctal(vector<char> arr) { return decimalToOctal(hexaToDecimal(arr)); }


}number;




#endif
