#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>



using  namespace std;

class People
{
public:
	string fio;
	string birthday;
	string tel;
	string adress;
};

class Librarian : public People
{
private:
	int ID;
	string email;
public:
	void addUser();
	void delUser();
	void addBook();
	void delBook();
	void giveBook();
	void takeBook();
};