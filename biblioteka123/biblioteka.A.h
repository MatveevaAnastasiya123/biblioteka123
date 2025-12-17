#pragma once
#include <iostream>


class Magazine : public Literature {
public:
    string issue;
    string month;
    string description;

    void showAvailable();
}