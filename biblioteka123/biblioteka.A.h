#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>

class Magazine : public Literature {
public:
    string issue;
    string month;
    string description;

    void showAvailable();
}
