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

    ifstream idFile("last_id.txt");
    int lastID = 1;
    if (idFile) {
        idFile >> lastID;
        idFile.close();
    }

     int newID = lastID;

    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << "ID: " << newID << endl;
        file << fio << endl;
        file << birthday << endl;
        file << tel << endl;
        file << adress << endl;
        file << "-------------" << endl;
        file.close();
        ofstream idOut("last_id.txt");
        idOut << (lastID + 1);
        idOut.close();
        cout << "Новый пользователь " << fio << " добавлен." << endl;
    }
    else {
        cout << "Ошибка записи пользователя в файл.";
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
        cout << "Ошибка открытия файла с пользователями." << endl;
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

        if (line.find("ID: ") == 0) {
            string fio_line;
            if (getline(file, fio_line)) {
                if (fio_line == FIO_del) {
                    found = true;
                    skip = 4; 
                    continue;
                } else {
                    temp << line << endl;
                    temp << fio_line << endl;
                     for (int i = 0; i < 3; i++) {
                        getline(file, line);
                        temp << line << endl;
                    }
                    getline(file, line);
                    temp << line << endl;
                }
            }
        } 
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
        cout << "Пользователь не найден." << endl;
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
    cout << "Введите название издания: ";
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
        cout << "Ошибка открытия файла с книгами.";
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
        cout << "Книга " << del_title << " не удалена." << endl;
    }
}

void Librarian::giveBook() {
    cout << "=====ВЫДАЧА КНИГИ=====" << endl;
    string user_FIO, book_title, date;
    cout << "Введите ФИО: ";
    getline(cin, user_FIO);
    cout << "Введите название книги: ";
    getline(cin, book_title);
    cout << "Введите дату выдачи: ";
    getline(cin, date);

    ifstream file("books.txt");
    if (!file) {
        cout << "Ошибка открытия файла.";
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
        cout << "Книга " << book_title << " выдана." << endl;

         int userID;
        cout << "Введите ID пользователя: ";
        cin >> userID;
        cin.ignore();
        
        ofstream book_file("books_to_users.txt", ios::app);
        book_file << "ID: " << userID << endl;                   
        book_file << "Выдана(кому): " << user_FIO << endl;
        book_file << "Книга: " << book_title << endl;
        book_file << "Дата выдачи: " << date << endl;
        book_file << "--------------------------" << endl;
        book_file.close();
        cout << "Запись добавлена в архив.";
    }
    else {
        remove("temp.txt");
        cout << "Книга " << book_title << " не выдана." << endl;
    }
}
void Librarian::takeBook() {
    cout << "=====ВОЗВРАЩЕНИЕ КНИГИ=====" << endl;
    string author, title, edition, annatation, year;
    cout << "Введите название книги:";
    getline(cin, title);
    cout << "Введите автора книги: ";
    getline(cin, author);
    cout << "Введите год издания: ";
    getline(cin, year);
    cout << "Ввелите название издания: ";
    getline(cin, edition);
    cout << "Введите анотацию к книге: ";
    getline(cin, annatation);

    int userID;
    cout << "Введите ID пользователя: ";
    cin >> userID;
    cin.ignore();

    ifstream file("books_to_users.txt");
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
        if (line == "ID: " + to_string(userID)) {
            string fio_line;
            if (getline(file, fio_line)) {
                string book_line;
                if (getline(file, book_line)) {
                    if (book_line == "Книга: " + title) {
                        found = true;
                        skip = 2;
                        continue;
                    } else {
                        temp << line << endl;
                        temp << fio_line << endl;
                        temp << book_line << endl;
                    }
                }
            }
        } else {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    if (found) {
        remove("books_to_users.txt");
        rename("temp.txt", "books_to_users.txt");
        cout << "Запись о выдаче книги удалена из архива." << endl;

        ofstream books_file("books.txt", ios::app);
        if (books_file.is_open()) {
            books_file << title << endl;
            books_file << author << endl;
            books_file << year << endl;
            books_file << edition << endl;
            books_file << annatation << endl;
            books_file << "---------------------" << endl;
            books_file.close();
            cout << "Книга '" << title << "' возвращена в библиотеку." << endl;
        }
        else {
            cout << "Ошибка при записи в файл." << endl;
        }
    }
    else {
        remove("temp.txt");
        cout << "Книга " << title << " не найдена у пользователя " << userID << endl;
    }
}
