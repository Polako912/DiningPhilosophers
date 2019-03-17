#pragma once
#include <iostream>

class Fork
{

    enum Status
    {
    Taken = 0,
    Free = 1
    };

    public:
    Fork();
    ~Fork();
    
};