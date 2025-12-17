#include "biblioteka.B.h"
#include "biblioteka.Lat.h"

void ELiter::showAvailable() {
    ifstream file("eliter.txt");
    string line;
    int count = 0;
    
    if (!file.is_open()) {
        cout << "Файл eliter.txt не найден!" << endl;
        return;
    }
    
    cout << "=====КАТАЛОГ ЭЛЕКТРОННОЙ ЛИТЕРАТУРЫ====="<<endl;
    
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
        
        cout << "ЭЛЕКТРОННАЯ КНИГА #" << count + 1 << endl;
        cout << "Название:  " << title <<endl;
        cout << "Автор:     " << author <<endl;
        cout << "Год:       " << year <<endl;
        cout << "Формат:    " << format <<endl;
        cout << "Размер:    " << size <<endl;
        cout << "Описание:  " << description <<endl;
        cout << endl;
    }
    
    if (count == 0) {
        cout << "В каталоге пока нет электронной литературы."<<endl;
    }
    
    file.close();
}
    
    file.close();
}
