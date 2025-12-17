#include "biblioteka.A.h"

void Magazine::showAvailable() {
	ifstream file("magazines.txt");
	string line;
	int count = 0;

	if (!file.is_open()) {
		cout << "Файл magazines.txt не найден!" << endl;
		return;
	}
	cout << "=====КАТАЛОГ ЖУРНАЛОВ====="<<endl;

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
		string issue = line;
		getline(file, line);
		string month = line;
		getline(file, line);
		string description = line;

		cout << "ЖУРНАЛ #" << count + 1 << "\n";
cout << "Название: " << title << "\n";
cout << "Авторы: " << author << "\n";
cout << "Год: " << year << "\n";
cout << "Номер: " << issue << "\n";
cout << "Месяц: " << month << "\n";
cout << "Описание: " << description << "\n";
cout << endl;
	}

	if (count == 0) {
		cout << "В каталоге пока нет журналов.\n";
	}

	file.close();
}
