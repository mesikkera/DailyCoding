#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    // vector 컨테이너를 이용한 stack 컨테이너 생성
    stack<int, vector<int>> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;       // top 데이터 출력
    st.pop();                       // top 데이터 삭제
    cout << st.top() << endl;
    st.pop();  
    cout << st.top() << endl;
    st.pop();

    // 스택이 비었는지 확인
    if(st.empty())
        cout << "There is no data in stack." << endl;
}