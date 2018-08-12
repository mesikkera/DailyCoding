#ifndef DOCWRITER_H
#define DOCWRITER_H

#include <string>
using namespace std;

class DocWriter 
{
public:
    DocWriter();
    DocWriter(const string& fileName, const string& content);
    ~DocWriter();

    // 파일 이름 지정
    void SetFileName(const string& fileName);

    // 저장할 텍스트 지정
    void SetContent(const string& content);

    // 파일에 텍스트 저장
    // virtual 키워드를 사용해서 가상함수도 만들었다.
    virtual void Write();

protected:
    string _fileName;
    string _content;
};

#endif