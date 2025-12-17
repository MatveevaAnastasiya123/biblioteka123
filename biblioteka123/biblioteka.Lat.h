#pragma once
#include "biblioteka.B.h"
class ELiter : public Literature {
public:
    string format;
    string size;
    string description;
    
    void showAvailable();
};
