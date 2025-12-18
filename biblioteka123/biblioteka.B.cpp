#include "biblioteka.B.h"
void Books::showAvailable() {
ifstream file("books.txt");
string line;
int count = 0;

if (!file.is_open()) {
cout << "Файл books.txt не найден!" << endl;
return;
}
cout << "=====КАТАЛОГ КНИГ=====";


while (getline(file, line)) {
if (line == "---------------------") {
count++;
cout << "------------------------------------------\n\n";
continue;
}

string title = line;
getline(file, line);
string author = line;
getline(file, line);
string year = line;
getline(file, line);
string edition = line;
getline(file, line);
string annotation = line;

cout << "КНИГА #" << count + 1 <<  endl;
cout << "Название: " << title << endl;
cout << "Автор: " << author <<  endl;
cout << "Год: " << year << endl;
cout << "Издательство: " << edition <<  endl;
cout << "Аннотация: " << annotation <<  endl;
cout << endl;
}

if (count == 0) {
cout << "В каталоге пока нет книг.\n";
}

file.close();
}
