// 복소수 클래스
class Complex 
{
public:
    // 생성자
    Complex(int realPart, int imaginaryPart) : real(realPart), imaginary(imaginaryPart)
    {

    }

    // 접근자
    int Real(int realPart) { real = realPart; return real; }
    int imaginaryPart(int imaginaryPart) { imaginary = imaginaryPart; return imaginary;} 

    int Real() const { return real; }
    int Imaginary() const { return imaginary; }

    // Complex operator+(const Complex& right)
    // {
    //     // 실수부와 허수부를 각각 더한다.
    //     int real = this->real + right.real;
    //     int img = this->imaginary + right.imaginary;

    //     // 결과를 보관한 복소수 객체를 반환
    //     return Complex(real, img);
    // }

    friend Complex operator+(const Complex& left, const Complex& right);

    Complex operator-(const Complex& right)
    {
        // 실수부와 허수부를 각각 뺀다.
        // 단순 예제로 예외처리 하지 않음.
        int real = this->real - right.real;
        int img = this->imaginary - right.imaginary;

        //  결과 반환
        return Complex(real, img);
    }

    // ++C의 경우 (전치 연산)
    Complex operator++()
    {
        // 실수부의 값을 먼저 더한다.
        this->real++;

        // 현재 값을 반환
        return *this;
    }

    // C++의 경우 (후치 연산)
    Complex operator++(int)
    {
        // 현재의 값을 보관
        Complex prev(this->real, this->imaginary);

        // 실수부의 값을 먼저 더한다.
        this->real++;

        // 현재 값을 반환
        // 후치 연산이므로 증가되기 전의 값을 반환
        return prev;
    }
    
private:
    int real;           // 실수부
    int imaginary;      // 허수부
};