#pragma once
#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;

class Literature {
public:
string title;
string author;
string year;
};

class Books : public Literature {
public:
void showAvailable();
};
