#include <iostream>
using namespace std;

struct FuncObject {
public:
    void operator()(int arg) const {
        cout << "Integer: " << arg << endl;
    }
};

void Print1(int arg) {
    cout << "Integer: " << arg << endl;
}

int main() {
    void (*Print2)(int) = Print1;
    FuncObject Print3;

    Print1(10);     // Function
    Print2(10);     // Function Pointer
    Print3(10);     // Function Object

    return 0;
}