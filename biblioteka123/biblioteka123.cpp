#include "biblioteka.B.h"
#include "biblioteka.M.h"
#include "biblioteka.L.h"
#include "biblioteka.A.h"
#include "biblioteka.Lat.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int vhod;
    cout<<"=====ВХОД====="<<endl;
    cout<<"1) Войти как библиотекарь"<<endl;
    cout<<"2) Войти как пользователь"<<endl;
	cout<<"3) Посмотреть каталог книг"<<endl;
	cout<<"4) Посмотреть каталог журналов"<<endl;
	cout<<"5) Посмотреть каталог электронной литературы"<<endl;
    cout<<"Выберите: ";
    cin>>vhod;
    cin.ignore();
	if(vhod == 1){
	int a;
	do {
		cout << "=====МЕНЮ БИБЛИОТЕКАРЯ=====" << endl;
		cout << "1) Добавить пользователя" << endl;
		cout << "2) Удалить пользователя" << endl;
		cout << "3) Добавить книгу" << endl;
		cout << "4) Удалить книгу" << endl;
		cout << "5) Выдать книгу" << endl;
		cout << "6) Вернуть книгу" << endl;
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
		case 6: lib.takeBook(); break;
		case 0: break;
        default: cout << "Неверный выбор!" << endl;
		}
	} while (a != 0);
	}
	if(vhod == 2){
    User user;
    user.login();
    if (user.userID != -1) { 
            int choice; 
            do {
                cout << "=====МЕНЮ ПОЛЬЗОВАТЕЛЯ=====" << endl;
                cout << "ФИО: " << user.fio << endl; 
                cout << "ID: " << user.userID << endl; 
                cout << "1. Показать ваши книги" << endl;
                cout << "2. Выйти" << endl; 
                cout << "Выберите действие: ";
                cin >> choice;
                cin.ignore();
                
                switch (choice) {
                    case 1:
                        cout << "=====ВАШИ КНИГИ=====" << endl;
                        user.showBooks(); break;
                    case 2: break;
                    default: cout << "Неверный выбор!" << endl;

                }
            } while (choice != 2);
        }
    }
if(vhod==3){
	Books books;
	books.showAvailable();
}
if(vhod==4){
	Magazine magazines;
	magazines.showAvailable();
}
if(vhod==5){
	ELiter ELiter;
	ELiter.showAvailable();
}
	return 0;
}
