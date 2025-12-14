#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

namespace User
{
	class People
	{
	private:
		int userID;
	public:
		People(int ID);

		void ShowBooksCatalog();
		void ShowMyBooks();
	};
}
