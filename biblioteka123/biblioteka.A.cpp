#include "biblioteka.A.h"

void Magazine::showAvailable() {
	ifstream file("magazines.txt");
	string line;
	int count = 0;

	if (!file.is_open()) {
		cout << "Ôàéë magazines.txt íå íàéäåí!" << endl;
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

		cout << "ÆÓÐÍÀË #" << count + 1 << endl;
		cout << "Íàçâàíèå: " << title <<endl;
		cout << "Àâòîðû: " << author <<endl;
		cout << "Ãîä: " << year << endl;
		cout << "Íîìåð: " << issue << endl;
		cout << "Ìåñÿö: " << month << endl;
		cout << "Îïèñàíèå: " << description <<endl";
		cout << endl;
	}

	if (count == 0) {
		cout << "Â êàòàëîãå ïîêà íåò æóðíàëîâ.\n";
	}

	file.close();
}
