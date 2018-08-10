#include "DocWriter.h"
#include <fstream>              // 파일 입출력
using namespace std;

DocWriter::DocWriter()
{
    // 파일 이름과 텍스트를 디폴트로 지정
    _fileName = "NoName.txt";
    _content = "There is no content";
}

DocWriter::DocWriter(const string& fileName, const string& content)
{
    _fileName = fileName;
    _content = content;
}

// 소멸자
DocWriter::~DocWriter()
{

}

// 파일 이름을 지정
void DocWriter::SetFileName(const string& fileName)
{
    _fileName = fileName;
}

// 저장할 텍스트를 지정
void DocWriter::SetContent(const string& content)
{
    _content = content;
}

// 파일에 텍스트 저장
void DocWriter::Write()
{
    // 파일 오픈
    ofstream of(_fileName.c_str());

    // 헤더 출력
    of << "# Content\n\n";

    // 텍스트 저장
    of << _content;
}
