#ifndef ANTHEADERPLUSPLUS_H
#define ANTHEADERPLUSPLUS_H

#include<windows.h>
#include<stdlib.h>
#include<iostream>
#include<sstream>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
using namespace std;
/*void swap(int (*a)[2], int (*b)[2])
{
	int temp[sizeof(*a)/sizeof((*a)[0])];
	memcpy(temp,a,sizeof(temp));
	memcpy(a,b,sizeof(*a));
	memcpy(b,temp,sizeof(*b));
}*/


void delay(int milliseconds) {
	long pause;
	clock_t now, then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	now = then = clock();
	while ((now - then) < pause)
		now = clock();
}


void gotoxy(int x, int y) { HANDLE hConsoleOutput;COORD coord;hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);coord.X = x;coord.Y = y;SetConsoleCursorPosition(hConsoleOutput, coord); }





void setcursor(bool visible, DWORD size) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (size == 0) {
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

void clrXY(int x, int y, int count) {
	COORD topLeft = { (short)x,(short)y };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;
	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(console, '\0', count, topLeft, &written);//replace with count(ex:80 characters) NULL at this line
	FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	SetConsoleCursorPosition(console, topLeft);
}


void ShowMenu(string menus[], int n, int index, int x, int y) {
	for (int i = 0; i < n; i++) {
		clrXY(x - 4, y + i, menus[i].length() + 4);
		if (i != index) {
			gotoxy(x, y + i);
			foreColor(3);
			cout << menus[i];
		}
		else {
			gotoxy(x - 4, y + i);
			foreColor(3);
			cout << "==> " << menus[i];
		}
	}
}


string formatCurrency(const long double& currency, const unsigned int& precision = 6) {
	ostringstream stm;
	stm << fixed << setprecision(precision) << currency;
	string money = stm.str();
	int i = money.find('.');
	if (i > 0) {
		i -= 3;
		while (i > 0) {
			money.insert(i, ",");
			i -= 3;
		}
	}
	return money;
}
//8.
long double eraseFormatCurrency(const string& currency) {
	string money = currency;
	int i = money.find('.');
	if (i > 0) {
		i -= 4;
		while (i > 0) {
			money.erase(i, 1);
			i -= 4;
		}
	}
	stringstream stm(money);
	long double tmp = 0;
	stm >> tmp;
	return tmp;
}
#endif
