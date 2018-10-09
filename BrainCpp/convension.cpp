int main()
{
    float i = 100.12345;
    double j = 200.12345;

    // 산술 연산으로 인해 자동으로 형변환되는 경우를 방지하기 위해 명시적으로 자료형을 강제하는 경우
    float count = static_cast<float>(j/i);

    double d = 1212;
    void* p = &d;

    // void형 포인터 변수 p에 대해 컴파일러가 자료형을 모르기 때문에
    // static_cast를 이용해 명시적으로 형(double형)을 변환
    double* dp = static_cast<double*>(p);

    const char *cp;
    // char *q = static_cast<char*>(cp);
    // const_cast<string>(cp);
}