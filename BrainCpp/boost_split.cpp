#include <string>
#include <set>
#include <vector>
#include <iterator>
#include <iostream>
#include <boost/algorithm/string.hpp>

int main()
{
    std::string version1 = "1.0.13";
    std::string version2 = "1.0.112";

    std::vector<std::string> ver1;
    boost::split(ver1, version1, boost::is_any_of("."));
    for(int i=0; i < ver1.size(); ++i)
        std::cout << ver1[i];
    std::cout << '\n';

    std::vector<std::string> ver2;
    boost::split(ver2, version2, boost::is_any_of("."));
    for(int i=0; i < ver2.size(); ++i)
        std::cout << ver2[i];
    std::cout << '\n';

    std::cout << "ver1.size() : " << ver1.size() << "\n";
    std::cout << "ver2.size() : " << ver2.size() << "\n";

    for(unsigned i = 0; i < ver1.size(); ++i) {    
        std::cout << "i: " << i << "\n";
        if(ver2.size() <= i) {
            std::cout << "ver1 is bigger" << "\n";
            return 0;
        } 
        int num1 = atoi(ver1[i].c_str());
        std::cout << "num1 : " << num1 << "\n";
        int num2 = atoi(ver2[i].c_str());
        std::cout << "num2 : " << num2 << "\n";
        if(num1 > num2) { 
            std::cout << "Ver1 is bigger" << "\n";
            return 0;
        } else if (num1 < num2) {
            std::cout << "Ver2 is bigger" << "\n";
            return 0;
        }
    }

    // if (ver2.size() > i) {
    //     std::cout << "Ver2 is Latest!" << "\n";
    // }


    std::cout << "Same Version!" << "\n";
}
