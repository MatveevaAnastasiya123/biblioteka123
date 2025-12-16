#include "biblioteka.L.h"

User::User() {
	userID = -1;
}

void User::login()
{
	cout << "Введите ФИО: ";
	getline(cin, fio);

	ifstream file("users.txt");
	string line;
	userID = -1;

	while (getline(file, line)) {
		if (line.find("ID: ") == 0) {
			int id = stoi(line.substr(4));
			getline(file, line);
			if (line == fio) {
				userID = id;
				break;
			}
		}
	}
	file.close();

	if (userID == -1)
		cout << "Пользователь не найден!" << endl;
	else
		cout << "Вход успешен! ID: " << userID << endl;
}

void User::showBooks() {
	if (userID == -1)
		return;

	ifstream file("books_to_users.txt");
	string line;

	cout << "Книги пользователя " << fio << ":" << endl;

	while (getline(file, line)) {
		if (line == "ID: " + to_string(userID)) {
			getline(file, line);
			getline(file, line);
			cout << "- " << line.substr(7) << endl;
			getline(file, line);
			getline(file, line);
		}
	}
	file.close();
}
