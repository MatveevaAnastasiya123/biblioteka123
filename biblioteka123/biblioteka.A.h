#pragma once

<iostream>
#include <string>
#include <windows.h>
using namespace std;

class Literature {
private:
	string title;
	string author;
	int year;

public:
	Literature();
	Literature(string t, string a, int y);


	void display();
	void setInfo(string t, string a, int y);

	string getTitle();
	string getAuthor();
	int getYear();
};

class Magazine : public Literature {
private:
	int issue;
	string category;

public:
	Magazine();
	Magazine(string t, string a, int y, int i, string c);

	void displayMagazine();
	void setMagazineInfo(string t, string a, int y, int i, string c);
	void nextIssue();

	int getIssue();
	string getCategory();

	void setIssue(int i);
	void setCategory(string c);
};
