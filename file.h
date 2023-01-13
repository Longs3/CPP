#ifndef FILE_H
#define FILE_H

#include<iostream>
#include<fstream>
using namespace std;

class File {
private:
    string name;
public:
    File(string);
    bool deleteFile();
};
File::File(string path): name(path){}
bool File::deleteFile() { return !remove(name.c_str()); }
#endif