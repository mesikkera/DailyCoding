#include <iostream>     // std::cout 
#include <typeinfo>     // std::bac_cast 

class Base { virtual void member() {} };
class Derived : Base {};

int main()
{
    try
    {
        Base b;
        Derived& rd = dynamic_cast<Derived&>(b);
    }
    catch(std::bad_cast& bc)
    {
        std::cerr << "bad_case caught: " << bc.what() << std::endl;
    }
    return 0;
    

}