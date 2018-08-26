#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
    // 동적 배열을 생성해서 임의의 영문자 출력
    std::vector<char> vec;
    vec.push_back('e');
    vec.push_back('b');
    vec.push_back('a');
    vec.push_back('d');
    vec.push_back('c');

    // sort() 함수를 사용해서 정렬
    std::sort(vec.begin(), vec.end());

    // 정렬 후 상태 출력
    std::cout << "vector 정렬 후\n";
    std::vector<char>::iterator it;
    for(it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it;

    // 일반 배열 정렬
    char arr[5] = {'d', 'c', 'a', 'e', 'b'};

    // sort() 함수를 사용해서 정렬
    std::sort(arr, arr+5);

    // 정렬 후 상태 출력
    std::cout << "\n\n배열 정렬 후\n";
    for (char* p = arr; p != arr + 5; ++p)
        std::cout << *p;

    std::cout << std::endl;

    return 0;
}   