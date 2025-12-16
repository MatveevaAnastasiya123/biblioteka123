#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class User {
public:
	string fio;
	int userID;

	User();

	void login();
	void showBooks();
};