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

    Complex operator+(const Complex& right)
    {
        // 실수부와 허수부를 각각 더한다.
        int real = this->real + right.real;
        int img = this->imaginary + right.imaginary;

        // 결과를 보관한 복소수 객체를 반환
        return Complex(real, img);
    }
    
private:
    int real;           // 실수부
    int imaginary;      // 허수부
};