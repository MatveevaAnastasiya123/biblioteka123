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

	cout << "\nВАШИ КНИГИ:\n";

	while (getline(file, line)) {

		if (line.find("Выдана(кому): " + fio) == 0) {
			
			getline(file, line);
			string bookName = line.substr(7); 
			cout << "- " << bookName << endl;

		
			getline(file, line); 
			getline(file, line); 
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