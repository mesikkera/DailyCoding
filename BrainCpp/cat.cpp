#include "cat.h"

namespace cat 
{
    Info cats[20];
    int count;

    void Info::Meow()
    {
        // do nothing.
    }

    void CreateAll()
    {
        std::cout << "CreateAll()" << std::endl;
    }

}