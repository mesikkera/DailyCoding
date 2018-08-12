#include <iostream>
using namespace std;

// 일반적인 '도형'을 상징하는 클래스
class Shape 
{
public:
    void Move(double x, double y);
    // virtual void Draw() const;          // 함수의 원형 앞에 virtual 키워드를 붙이면 가상함수가 된다.
    virtual void Draw() const = 0;         // 함수 선언 = 0 --> 순수 가상 함수

    Shape();
    Shape(double x, double y);

protected:
    double _x, _y;
};

Shape::Shape()
{
    _x = _y = 0.0;
}

Shape::Shape(double x, double y)
{
    _x = x;
    _y = y;
}

void Shape::Move(double x, double y)
{
    _x = x;
    _y = y;
}

// Draw()를 순수 가상 함수로 선언했으므로 
// Shape::Draw() 함수의 정의를 제거할 수 있다.
// void Shape::Draw() const 
// {
//     cout << "[Shape] Position = ( " << _x << ", " << _y << ")\n";
// }

// 사각형을 상징하는 클래스
class Rectangle : public Shape 
{
public:
    void Draw() const;
    void Resize(double width, double height);

    Rectangle();
    Rectangle(double x, double y, double width, double height);

protected:
    double _width;
    double _height;
};

Rectangle::Rectangle()
{
    _width = _height = 100.0f;
}

Rectangle::Rectangle(double x, double y, double width, double height) : Shape(x, y)
{
    Resize(width, height);
}

void Rectangle::Draw() const 
{
    cout << "[Rectangle] Position = ( " << _x << ", " << _y << "), Size = ( " << _width << ", " << _height << ")\n";
}

void Rectangle::Resize(double width, double height)
{
    _width = width;
    _height = height;
}

// 원을 상징하는 클래스
class Circle : public Shape 
{
public:
    void Draw() const;
    void SetRadius(double radius);

    Circle();
    Circle(double x, double y, double radius);

protected:
    double _radius;
};

Circle::Circle()
{
    _radius = 100.0f;
}

Circle::Circle(double x, double y, double radius) : Shape(x, y)
{
    SetRadius(radius);
}

void Circle::Draw() const 
{
    cout << "[Circle] Position = ( " << _x << " , " << _y << " ), Radius = " << _radius << endl;
}

void Circle::SetRadius(double radius)
{
    _radius = radius;
}

int main()
{
    // 도형 객체 생성 및 그리기
    // Shape s(100, 100);

    // 하나 이상의 순수 가상 함수를 가진 클래스: 추상 클래스
    // 추상클래스의 객체를 만드는 것은 불가능.
    
    // Shape s;
    // s.Move(100, 100);
    // s.Draw();

    // 사각형 객체 생성 및 그리기
    // Rectangle r(200, 100, 50, 50)
    Rectangle r;
    r.Move(200, 200);
    r.Resize(50, 50);
    r.Draw();

    // 원 객체 생성 및 그리기
    // Circle c(300, 100, 30);
    Circle c;
    c.Move(300, 100);
    c.SetRadius(30);
    c.Draw();

    // 도형들을 담을 배열 준비
    Shape* shapes[5] = {NULL};

    // 각 타입의 객체를 생성 후 배열 보관
    shapes[0] = new Circle(100, 100, 50);
    shapes[1] = new Rectangle(300, 300, 100, 100);
    shapes[2] = new Rectangle(200, 100, 50, 150);
    shapes[3] = new Circle(100, 300, 150);
    shapes[4] = new Rectangle(200, 200, 200, 200);

    // 배열의 모든 객체 그리기
    cout << endl;
    for (int i = 0; i < 5; ++i)
        shapes[i] -> Draw();

    // 배열에 보관된 모든 객체 소멸
    for (int i = 0; i < 5; ++i)
    {
        delete shapes[i];
        shapes[i] = NULL;
    }

    return 0;
}

