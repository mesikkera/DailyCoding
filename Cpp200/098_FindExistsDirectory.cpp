#include <iostream>
#include <experimental/filesystem>

using namespace std;
namespace fs = experimental::filesystem;

int main()
{
    if (fs::exists("test") == true)
        cout << "Directory Exists!" << endl;
    else
        cout << "Directory not Exists!" << endl;

    return 0;
}


