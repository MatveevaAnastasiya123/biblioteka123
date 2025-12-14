#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace User
{
	class People
	{
	private:
		int userID;
	public:
		People(int ID);

		void ShowBooksCstslog();
		void ShowMyBooks();
	};
}
