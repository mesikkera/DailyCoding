#include <iostream>
using namespace std;

class Car 
{
private:
    int num;
    double gas;
public:
    Car();
    Car(int n, double g);
    void show();
};

Car::Car()
{
    num = 0;
    gas = 0;
    cout << "Create a car." << endl;
}

Car::Car(int n, double g)
{
    num = n;
    gas = g;
    cout << "Create a car." << endl;
    cout << "Car Number is : " << num << endl;
    cout << "Car Gas is : " << gas << endl;
}

void Car::show()
{
    cout << "Car Number is " << num << " and Car Gas is " << endl; 
}

int main()
{
    Car Car1;
    Car car2(1234, 20.5);

    return 0;
}