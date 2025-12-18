#include "biblioteka.A.h"

void Magazine::showAvailable() {
	ifstream file("magazines.txt");
	string line;
	int count = 0;

	if (!file.is_open()) {
		cout << "Ôàéë magazines.txt íå íàéäåí!" << endl;
		return;
	}
	cout << "=====ÊÀÒÀËÎÃ ÆÓÐÍÀËÎÂ====="<<endl;

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

		cout << "ÆÓÐÍÀË #" << count + 1 << "\n";
cout << "Íàçâàíèå: " << title << "\n";
cout << "Àâòîðû: " << author << "\n";
cout << "Ãîä: " << year << "\n";
cout << "Íîìåð: " << issue << "\n";
cout << "Ìåñÿö: " << month << "\n";
cout << "Îïèñàíèå: " << description << "\n";
cout << endl;
	}

	if (count == 0) {
		cout << "Â êàòàëîãå ïîêà íåò æóðíàëîâ.\n";
	}

	file.close();
}
