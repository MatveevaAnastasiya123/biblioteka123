#include "biblioteka.M.h"

void Librarian::addUser() {
    cout << "=====ДОБАВЛЕНИЕ ПОЛЬЗОВАТЕЛЯ=====" << endl;
    string fio, birthday, tel, adress;
    cout << "Введите ФИО:";
    getline(cin, fio);
    cout << "Введите дату рождения:";
    getline(cin, birthday);
    cout << "Введите телефон:";
    getline(cin, tel);
    cout << "Введите адрес:";
    getline(cin, adress);

    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << fio << endl;
        file << birthday << endl;
        file << tel << endl;
        file << adress << endl;
        file << "-------------" << endl;
        file.close();
        cout << "Новый пользователь " << fio << " добавлен." << endl;
    }
    else {
        cout << "Произошла ошибка при регистрации пользователя.";
        return;
    }
}

void Librarian::delUser() {
    cout << "=====УДАЛЕНИЕ ПОЛЬЗОВАТЕЛЯ=====" << endl;
    string FIO_del;
    cout << "Введите ФИО пользователя, которого хотите удалить: ";
    getline(cin, FIO_del);

    ifstream file("users.txt");
    if (!file) {
        cout << "Ошибка открытия файла." << endl;
        return;
    }

    ofstream temp("temp.txt");
    string line;
    bool found = false;
    int skip = 0;

    while (getline(file, line)) {
        if (skip > 0) {
            skip--;
            continue;
        }

        if (line == FIO_del) {
            found = true;
            skip = 4;
            continue;
        }

        temp << line << endl;
    }

    file.close();
    temp.close();

    if (found) {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        cout << "Пользователь удален. " << endl;
    }
    else {
        remove("temp.txt");
        cout << "Не найден!" << endl;
    }
}

void Librarian::addBook() {
    cout << "=====ДОБАВЛЕНИЕ КНИГИ=====" << endl;
    string author, title, edition, annatation, year;
    cout << "Введите название книги:";
    getline(cin, title);
    cout << "Введите ФИО автора: ";
    getline(cin, author);
    cout << "Введите год издания: ";
    getline(cin, year);
    cout << "Введит название издания: ";
    getline(cin, edition);
    cout << "Введите анотацию к книге: ";
    getline(cin, annatation);

    ofstream file("books.txt", ios::app);
    if (file.is_open()) {
        file << title << endl;
        file << author << endl;
        file << year << endl;
        file << edition << endl;
        file << annatation << endl;
        file << "---------------------" << endl;
        file.close();
        cout << "Книга " << title << " добавлена в библиотеку." << endl;
    }
}

void Librarian::delBook() {
    cout << "=====УДАЛЕНИЕ КНИГИ=====" << endl;
    string del_title;
    cout << "Введите название книги, которую хотите удалить: ";
    getline(cin, del_title);
    ifstream file("books.txt");
    if (!file) {
        cout << "Ошибка записи книги в файл.";
        return;
    }
    ofstream temp("temp.txt");
    string line;
    bool found = false;
    int skip = 0;

    while (getline(file, line)) {
        if (skip > 0) {
            skip--;
            continue;
        }
        if (line == del_title) {
            found = true;
            skip = 5;
            continue;
        }
        temp << line << endl;
    }
    file.close();
    temp.close();
    if (found) {
        remove("books.txt");
        rename("temp.txt", "books.txt");
        cout << "Книга " << del_title << " удалена." << endl;
    }
    else {
        remove("temp.txt");
        cout << "Книга " << del_title << " не найдена." << endl;
    }
}

void Librarian::giveBook() {
    cout << "=====ВЫДАЧА КНИГИ=====" << endl;
    string user_FIO, book_title;
    cout << "Введите ФИО: ";
    getline(cin, user_FIO);
    cout << "Введите название книги: ";
    getline(cin, book_title);

    ifstream file("books.txt");
    if (!file) {
        cout << "Ошибка записи книги в файл.";
        return;
    }
    ofstream temp("temp.txt");
    string line;
    bool found = false;
    int skip = 0;

    while (getline(file, line)) {
        if (skip > 0) {
            skip--;
            continue;
        }
        if (line == book_title) {
            found = true;
            skip = 5;
            continue;
        }
        temp << line << endl;
    }
    file.close();
    temp.close();
    if (found) {
        remove("books.txt");
        rename("temp.txt", "books.txt");
        cout << "Книга " << book_title << " удалена." << endl;
    }
    else {
        remove("temp.txt");
        cout << "Книга " << book_title << " не найдена." << endl;
    }
}
