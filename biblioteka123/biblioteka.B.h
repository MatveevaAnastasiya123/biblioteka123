#pragma once
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
