#pragma once
#include <iostream>
#include <windows.h>
#include <string>


class Magazine : public Literature {
public:
    string issue;
    string month;
    string description;

    void showAvailable();
}
