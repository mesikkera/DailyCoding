#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;              // stack 컨테이너 생성

    st.push(10);                // 데이터 추가(입력)
    st.push(20);    
    st.push(30);
    
    cout << st.top() << endl;   // top 데이터 출력
    st.pop();                   // top 데이터 삭제

    cout << st.top() << endl;   
    st.pop();

    cout << st.top() << endl;
    st.pop();

    if(st.empty())              // 스택이 비었는지 확인
        cout << "There is no data in stack." << endl;

// Stack Container
    stack<int> st1;

    // push()로 원소를 추가하고,
    // top()으로 가장 늦게 저장된 원소를 참조하고,
    // pop()으로 원소를 제거한다.
    st1.push(10);
    st1.push(20);
    st1.push(30);

    while(!st1.empty())
    {
        cout << st1.top() << endl;
        st1.pop();
    }
    return 0;
}