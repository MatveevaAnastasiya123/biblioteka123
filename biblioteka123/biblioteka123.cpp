#include "biblioteka.M.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a;
	do {
		cout << "=====МЕНЮ БИБЛИОТЕКАРЯ=====" << endl;
		cout << "1) Добавить пользователя" << endl;
		cout << "2) Удалить пользователя" << endl;
		cout << "3) Добавить книгу" << endl;
		cout << "4) Удалить книгу" << endl;
		cout << "5) Выдать книгу" << endl;
		cout << "0) Выйти" << endl;
		cout << "Введите номер нужной функции(1-5): ";
		cin >> a;
		Librarian lib;
		cin.ignore();
		switch (a) {
		case 1: lib.addUser(); break;
		case 2: lib.delUser(); break;
		case 3: lib.addBook(); break;
		case 4: lib.delBook(); break;
		case 5: lib.giveBook(); break;
		}
	} while (a != 0);

	return 0;
}