#include "biblioteka.M.h"

void Librarian::addUser() {
    cout << "=====ÄÎÁÀÂËÅÍÈÅ ÏÎËÜÇÎÂÀÒÅËß=====" << endl;
    string fio, birthday, tel, adress;
    cout << "Ââåäèòå ÔÈÎ:";
    getline(cin, fio);
    cout << "Ââåäèòå äàòó ðîæäåíèÿ:";
    getline(cin, birthday);
    cout << "Ââåäèòå òåëåôîí:";
    getline(cin, tel);
    cout << "Ââåäèòå àäðåñ:";
    getline(cin, adress);

    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << fio << endl;
        file << birthday << endl;
        file << tel << endl;
        file << adress << endl;
        file << "-------------" << endl;
        file.close();
        cout << "Íîâûé ïîëüçîâàòåëü " << fio << " äîáàâëåí." << endl;
    }
    else {
        cout << "Ïðîèçîøëà îøèáêà ïðè ðåãèñòðàöèè ïîëüçîâàòåëÿ.";
        return;
    }
}

void Librarian::delUser() {
    cout << "=====ÓÄÀËÅÍÈÅ ÏÎËÜÇÎÂÀÒÅËß=====" << endl;
    string FIO_del;
    cout << "Ââåäèòå ÔÈÎ ïîëüçîâàòåëÿ, êîòîðîãî õîòèòå óäàëèòü: ";
    getline(cin, FIO_del);

    ifstream file("users.txt");
    if (!file) {
        cout << "Îøèáêà îòêðûòèÿ ôàéëà." << endl;
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
        cout << "Ïîëüçîâàòåëü óäàëåí. " << endl;
    }
    else {
        remove("temp.txt");
        cout << "Íå íàéäåí!" << endl;
    }
}

void Librarian::addBook() {
    cout << "=====ÄÎÁÀÂËÅÍÈÅ ÊÍÈÃÈ=====" << endl;
    string author, title, edition, annatation, year;
    cout << "Ââåäèòå íàçâàíèå êíèãè:";
    getline(cin, title);
    cout << "Ââåäèòå ÔÈÎ àâòîðà: ";
    getline(cin, author);
    cout << "Ââåäèòå ãîä èçäàíèÿ: ";
    getline(cin, year);
    cout << "Ââåäèò íàçâàíèå èçäàíèÿ: ";
    getline(cin, edition);
    cout << "Ââåäèòå àíîòàöèþ ê êíèãå: ";
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
        cout << "Êíèãà " << title << " äîáàâëåíà â áèáëèîòåêó." << endl;
    }
}

void Librarian::delBook() {
    cout << "=====ÓÄÀËÅÍÈÅ ÊÍÈÃÈ=====" << endl;
    string del_title;
    cout << "Ââåäèòå íàçâàíèå êíèãè, êîòîðóþ õîòèòå óäàëèòü: ";
    getline(cin, del_title);
    ifstream file("books.txt");
    if (!file) {
        cout << "Îøèáêà çàïèñè êíèãè â ôàéë.";
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
        cout << "Êíèãà " << del_title << " óäàëåíà." << endl;
    }
    else {
        remove("temp.txt");
        cout << "Êíèãà " << del_title << " íå íàéäåíà." << endl;
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
        ofstream book_file("books_to_users.txt", ios::app);
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
void Librarian::take_book() {
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

    string user_FIO;
    cout << "Введите ФИО пользователя, который возвращает книгу: ";
    getline(cin, user_FIO);

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
        if (line == "Выдана(кому): "+user_FIO) {
            string next_line;
            if (getline(file, next_line)) {
                if (next_line == "Книга: "+title) {
                    found = true;
                    skip = 2; 
                    continue;
                }
                else {//записываем все обратно
                    temp << line << endl;
                    temp << next_line << endl;
                }
            }
        }
        else {
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
        cout << "Книга " << title << " не найдена у пользователя " << user_FIO << endl;
    }
}
