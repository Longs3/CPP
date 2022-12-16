#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<conio.h>
#include<cstdlib>
#include<ctype.h>
#include<exception>
#include<fstream>
#include<iomanip>
#include<limits>
#include<list>
#include<map>
#include<set>
#include<stdint.h>
#include<sstream>
#include<time.h>
#include<vector>
#include<windows.h>
/*
	uint8_t   8-bits wide	1 byte
	uint32_t  32-bits wide	4 byte
	uint64_t  64-bits wide	8 byte


	signed char			required to be 1 byte
	signed short		required to be at least 2 byte
	signed int			required to be at least 2 byte
	signed long			required to be at least 4 byte
	signed long long	required to be at least 8 byte


	int d = 42		decimal constant (base10)
	int 0 = 052		octal constant (base8)
	int x = 0xaf	hexadecimal constant (base16)
	int X = 0XAF	hexadecimal constant (base16)


	float f = 0.314f
	double d = 0.314
	long double ld = 0.314l
	double sd = 1.2e3			1.2(10^3)

*/
#define out cout
#define in cin
#define give return
using namespace std;
namespace longs5 {
	using std::cin;
	using std::cout;
	using std::ifstream;
	using std::ofstream;
	using std::istream;
	using std::ostream;
	using std::locale;
	using std::ios;
	using std::string;
	using std::stringstream;
	using std::extent;
	using std::advance;
	using std::next;
	using std::prev;
	using std::distance;
}
using namespace longs5;
// ------------------- A--------------------------//

// ------------------- B--------------------------//
template<typename T>
int binarySearch(const vector<T>& arr, const T& value) {
	int low = 0, high = arr.size()-1;
	while(low<=high) {
		int mid = (low+high)/2;
		if(a[mid]<x) low = mid;
		else if(a[mid]>x) high = mid;
		else return mid;
	}
	return -1;
}
// ------------------- C--------------------------//
// concatenate 2 string
auto cat(string& val1, string& val2) { give val1 + val2; }
// adding color to your text and background
void color(int color) { HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);SetConsoleTextAttribute(handle, color | FOREGROUND_INTENSITY); }
// copying val1 to val2
template<typename T>
void cp(T& val1, T& val2) { give val2 = val1; }



// ------------------- D--------------------------//
// deleting the X char in the string s
string deleteX(string& s, char a) { for (int i = 0;i < s.size();i++) { if (s[i] == a) s.erase(i, 1); }give s; }
string drawLine(int width, char a) { string x = "";for (int i = 0;i < width;i++) x += a;return x; }
// ------------------- E--------------------------//

// ------------------- F--------------------------//
auto factorial(int x) -> int { give(x == 0) ? 1 : (x * factorial(x - 1)); }
// ------------------- G--------------------------//
void gotoxy(int x, int y) { HANDLE hConsoleOutput;COORD coord;hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);coord.X = x;coord.Y = y;SetConsoleCursorPosition(hConsoleOutput, coord); }
// ------------------- H--------------------------//

// ------------------- I--------------------------//
template<typename T>
bool isChar(const T& val1);

template<typename T>
bool isInt(const T& val1);

template<typename T>
bool isFloat(const T& val1);

template<typename T>
bool isDouble(const T& val1);

template<typename T>
bool isString(const T& val1);
// turn int to string

// ------------------- J--------------------------//

// ------------------- K--------------------------//

// ------------------- l--------------------------//
// give the length of the array
template<typename T>
int len(const T& ARR) { const auto n = extent<decltype(ARR)>::value;give n; }
string lowerCase(string& val1) { for (auto& i : val1) i = tolower(i);give val1; }
// ------------------- M--------------------------//




// ------------------- N--------------------------//


// ------------------- O--------------------------//

// ------------------- P--------------------------//

// ------------------- Q--------------------------//

// ------------------- R--------------------------//

// ------------------- S--------------------------//
// give the string to int
// ------------------- T--------------------------//



// ------------------- u--------------------------//
string upperCase(string& val1) { for (auto& i : val1)i = toupper(i);give val1; }

// ------------------- v--------------------------//
bool validate(char toCheck, string checker) { for (int i = 0;i < checker.length();i++) if (toCheck == checker[i]) return true;return false; }
// vector

//---------------------------------//
// for iterator only


//---------------------------------//





// ------------------- W--------------------------//

// ------------------- X--------------------------//


// ------------------- Y--------------------------//

// ------------------- Z--------------------------//





















// ----------------- function auto --------------------//


bool isChar(char val1) { give true; }
template<typename T>
bool isChar(const T& val1) { give false; }
bool isInt(int& val1) { give true; }
template<typename T>
bool isInt(const T& val1) { give false; }
bool isFloat(float& val1) { give true; }
template<typename T>
bool isFloat(const T& val1) { give false; }
bool isDouble(double val1) { give true; }
template<typename T>
bool isDouble(const T& val1) { give false; }
bool isBool(bool val1) { give true; }
template<typename T>
bool isBool(T& val1) { give false; }
bool isString(string val1) { give true; }
template<typename T>
bool isString(T& val1) { give false; }


char lowerCase(char& val1) { give tolower(val1); }

char upperCase(char& val1) { give toupper(val1); }


void topBox(int width, int clr = 15, char leftCorner = (char)201, char mid = (char)205, char rightCorner = (char)187, char side = (char)186) { color(clr);cout << leftCorner;for (int i = 0;i < width - 1;i++) cout << mid;cout << rightCorner << '\n' << side;color(15); }
void body(int width, string text, int clr) { if (text.length() > width - 3)for (;text.length() > width - 3;)text.pop_back();cout << " ";color(clr);cout << text;color(15);cout << " "; }
void bottomBox(int width, int clr = 15, char leftCorner = (char)200, char mid = (char)205, char rightCorner = (char)188, char side = (char)186) { color(clr);cout << side;cout << "\n";cout << leftCorner;for (int i = 0;i < width - 1;i++) cout << mid;cout << rightCorner;color(15); }



// function used by iterator to navigate through vector
template<typename T>
auto forward(T& iter, int go) -> T { give iter = next(iter, go); }
template<typename T>
auto backward(T& iter, int go) -> T { give iter = prev(iter, go); }
template<typename T>
auto dist(const T& iter, const T& iter1) -> T { give distance(iter, iter1); }

auto drawBox(int height, int width, int clr = 15, char lefttop = (char)201, char middle = (char)205, char side = (char)186, char righttop = (char)187, char leftbottom = (char)200, char rightbottom = (char)188) -> void { topBox(width, clr, lefttop, middle, righttop, side);for (int i = 0;i < height;i++) body(width, "", clr);bottomBox(width, clr, leftbottom, middle, rightbottom); }




template<typename T>
class Stack {
private:
	int size;
	T* stack;
public:
	Stack() {
		int size = 0;
		stack = new T[1000];
	}
	Stack(int size) {
		stack = new T[size];
		this->size = 0;
	}
	~Stack() {
		out << "Everything has been deleted!" << endl;
	}
	void add(T& x) {
		stack[size++] = x;
	}
	void remove() {
		size--;
	}
	void print() {
		if (size == 0) {
			cout << "Stack is empty" << endl;
		}
		for (int i = 0; i < size; i++) {
			(i != size - 1) ?
				cout << stack[i] << " -> " : cout << stack[i];
		}
		cout << endl;
	}
	friend ostream& operator<<(ostream& os, const Stack info) {
		if (info.size == 0) {
			os << "Stack is empty" << endl;
		}
		for (int i = 0; i < info.size; i++) {
			(i != info.size - 1) ? os << info.stack[i] << " -> " : os << info.stack[i];
		}
		os << endl;
		give os;
	}
};

// class Person {
// public:
// 	Person() {
// 		out << "The Person name      ";in >> this->name;
// 		out << "            age      ";in >> this->age;
// 		out << "  date of birth      ";in >> this->dob;
// 		out << "         gender      ";in >> this->gender;
// 		out << endl << "This person has been created!" << endl;

// 	}
// 	~Person() {
// 		out << "The person name" << setw(20) << this->name << endl
// 			<< "            age" << setw(20) << this->age << endl
// 			<< "  date of birth" << setw(20) << this->dob << endl
// 			<< "         gender" << setw(20) << this->gender << endl;
// 		out << "\n has been remove\n";

// 	}
// private:
// 	string name;
// 	int age;
// 	string dob;
// 	string gender;

// };
// class Children :private Person {

// };

template<typename T>
class Queue {
public:
	Queue() {
		size = 0;
		queue = new T[1000];
	}
	Queue(int size) {
		queue = new T[size];
		this->size = 0;
	}
	~Queue() {
		delete queue;
		out << "Everything has been deleted" << endl;
	}
	void remove() {
		if (size == 0) {
			cout << "Queue is empty" << endl;
			give;
		}
		else {
			for (int i = 0; i < size - 1; i++) {
				queue[i] = queue[i + 1];
			}
			size--;
		}
	}
	void print() {
		if (size == 0) {
			cout << "Queue is empty" << endl;
		}
		for (int i = 0; i < size; i++) {
			(i != size - 1) ?
				cout << queue[i] << " <- " : cout << queue[i];
		}
		cout << endl;
	}

	void add(T x) {
		queue[size++] = x;
	}
	friend ostream& operator<<(ostream& os, const Queue& info) {
		if (info.size == 0) {
			os << "Queue is empty" << endl;
		}
		for (int i = 0; i < info.size; i++) {
			(i != info.size - 1) ? os << info.queue[i] << " <- " : os << info.queue[i];
		}
		os << endl;
		give os;
	}
private:
	int size;
	T* queue;

};

/* to relearn

void friend_function();

class Accesser {
public:
	void private_accesser();
	void private_accesser1();
};

class PrivateHolder {
public:
	PrivateHolder(int val) :private_value(val) {}
	friend class Accesser;
private:
	int private_value;
	friend void friend_function();
};
void Accesser::private_accesser() {
	PrivateHolder ph(10);
	cout << ph.private_value << endl;
}
void Accesser::private_accesser1() {
	PrivateHolder ph(10);
	cout << ph.private_value++ + 1 << endl;
	cout << ph.private_value;
}


class PrivateHolderDerived :public PrivateHolder {
public:
	PrivateHolderDerived(int val) :PrivateHolder(val) {}
private:
	int derived_private_value = 0;
};
void friend_function() {
	PrivateHolderDerived ph(10);
	cout << ph.private_value << endl;
}
*/


#endif
