/* 단어의 개수
문제
영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다. 이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오.

입력
첫 줄에 영어 대소문자와 띄어쓰기로 이루어진 문자열이 주어진다. 이 문자열의 길이는 1,000,000을 넘지 않는다. 단어는 띄어쓰기 한 개로 구분되며, 공백이 연속해서 나오는 경우는 없다. 또한 문자열의 앞과 뒤에는 공백이 있을 수도 있다.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int space_count = 0;
    
    getline(cin, input);

    for(int i = 0; i < input.size(); i++) {
        if(input[i] == ' ')
            space_count++;
    }

    // 문자열 첫번째가 공백인 경우
    if (input.at(0) == ' ')
        space_count -= 1;
        
    // 문자열 마지막이 공백인 경우
    if (input.at(input.size() -1) == ' ')
        space_count -= 1;

    // 단어의 개수는 공백의 수 보다 1이 많다.   
    cout << space_count + 1 << "\n";
    return 0;
}
