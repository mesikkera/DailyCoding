#include <list>
#include <iostream>

int main()
{
    // int 타입을 담을 링크드 리스트 생성
    std::list<int> intList;

    // 0 ~ 9까지 링크드 리스트에 넣는다.
    for (int i = 0; i < 10; ++i)
        intList.push_back(i);

    // 5를 찾아서 제거한다.
    intList.remove(5);

    // 링크드 리스트의 내용을 출력
    std::list<int>::iterator it;
    for (it = intList.begin(); it != intList.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}