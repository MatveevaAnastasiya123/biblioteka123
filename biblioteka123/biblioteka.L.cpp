#include "biblioteka.L.h"

User::People::People(int ID)
{
	userID = ID;
}

void User::People::ShowBooksCatalog()
{
	ifstream file("books.txt");
	string line;

	if (!file.is_open())
	{
		cout << "Ошибка открытия файла books.txt" << endl;
		return;
	}

	cout << "Каталог книг: " << endl;

	while (getline(file, line))
	{
		cout << line << endl;
	}

	file.close();
}

void User::People::ShowMyBooks()
{
	ifstream file("books_to_users.txt");
	string line;
	
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла books_to_users.txt" << endl;
		return;
	}
	
	cout << "Книги пользователя с ID" << userID << ":" << endl;

	while (getline(file, line))
	{
		int pos = line.find(';');
		int IDFromFile = stoi(line.substr(0, pos));
		string BookName = line.substr(pos + 1);

		if (IDFromFile == userID)
		{
			cout << BookName << endl;
		}
	}
	file.close();
} 

int main()
{
	setlocale(LC_ALL, "Russian");
	int ID;

	cout << "Введите ID пользователя: ";
	cin >> ID;

	User::People user(ID);

	user.ShowBooksCatalog();
	cout << endl;
	user.ShowMyBooks();

	return 0;

}