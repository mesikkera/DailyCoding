int main()
{
    const int size = 100;

    const int &size2 = size;

    // 한정자를 초깃값으로 참조자를 선언할 때는 반드시 해당 참조자 역시
    // const 키워드를 붙여서 한정자로 선언한다.
    // int &size3 = size;
     const int &size3 = size;

    return 0;
}