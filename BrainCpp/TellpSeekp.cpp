#include <fstream>
using namespace std;

int main()
{
    ofstream ofs;

    // file.txt 파일을 연다.(없으면 생성)
    ofs.open("file.txt");

    // "This is an apple" 문자열을 파일에 쓴다.
    ofs.write("This is an apple", 16);

    // tellp() 멤버 함수를 이용해 파일의 현재 위치를 얻는다.
    // 현재 위치는 This is an apple 의 맨 끝일 것이다.
    long  pos = ofs.tellp();

    // 현재 위치에서 7만큼 위치를 뒤로 이동시킨다.
    // 현재 위치를 앞뒤로 조정하는 것을 오프셋(offset)을 조정한다고 한다.
    // 오프셋을 -7로 조정한 위치는 문자 'n'이다.
    ofs.seekp(pos-7);

    // 조정한 위치부터 문자열 "sam"을 쓴다.
    ofs.write(" sam", 4);

    // 파일을 닫는다.
    ofs.close();

    return 0;
}