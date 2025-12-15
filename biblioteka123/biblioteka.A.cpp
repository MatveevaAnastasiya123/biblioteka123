#include <iostream>
"biblioteka.A.h"
using namespace std;


Literature::Literature() {
	title = "Без названия";
	author = "Неизвестен";
	year = 2000;
}

Literature::Literature(string t, string a, int y) {
	title = t;
	author = a;
	year = y;
}

void Literature::display() {
	cout << "Название: " << title << endl;
	cout << "Автор: " << author << endl;
	cout << "Год: " << year << endl;
}

void Literature::setInfo(string t, string a, int y) {
	title = t;
	author = a;
	year = y;
}
string Literature::getTitle() {
	return title;
}
string Literature::getAuthor() {
	return author;
}
int Literature::getYear() {
	return year;
}


Magazine::Magazine() : Literature() {
	issue = 1;
	category = "Общий";
}

Magazine::Magazine(string t, string a, int y, int i, string c) : Literature(t, a, y) {
	issue = i;
	category = c;
}

void Magazine::displayMagazine() {
	cout << "\n===Журнал===" << endl;
	display();
	cout << "Номер выпуска: " << issue << endl;
	cout << "Категория: " << category << endl;
	cout << "=======================" << endl;
}

void Magazine::nextIssue() {
	issue++;
	year++;
	cout << "Выпущен следующий номер: " << issue << " (" << year << " год)" << endl;
}

int Magazine::getIssue() {
	return issue;
}

string Magazine::getCategory() {
	return category;
}

void Magazine::setIssue(int i) {
	issue = i;
}

void Magazine::setCategory(string c) {
	category = c;
}