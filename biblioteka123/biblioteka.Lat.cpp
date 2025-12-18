#include "biblioteka.B.h"
#include "biblioteka.Lat.h"

void ELiter::showAvailable() {
    ifstream file("eliter.txt");
    string line;
    int count = 0;
    
    if (!file.is_open()) {
        cout << "Ôàéë eliter.txt íå íàéäåí!" << endl;
        return;
    }
    
    cout << "=====ÊÀÒÀËÎÃ ÝËÅÊÒÐÎÍÍÎÉ ËÈÒÅÐÀÒÓÐÛ====="<<endl;
    
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
        string format = line;
        getline(file, line);
        string size = line;
        getline(file, line);
        string description = line;
        
        cout << "ÝËÅÊÒÐÎÍÍÀß ÊÍÈÃÀ #" << count + 1 << endl;
        cout << "Íàçâàíèå:  " << title <<endl;
        cout << "Àâòîð:     " << author <<endl;
        cout << "Ãîä:       " << year <<endl;
        cout << "Ôîðìàò:    " << format <<endl;
        cout << "Ðàçìåð:    " << size <<endl;
        cout << "Îïèñàíèå:  " << description <<endl;
        cout << endl;
    }
    
    if (count == 0) {
        cout << "Â êàòàëîãå ïîêà íåò ýëåêòðîííîé ëèòåðàòóðû."<<endl;
    }
    
    file.close();
}
