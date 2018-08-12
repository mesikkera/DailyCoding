#ifndef HTMLWRITER_H
#define HTMLWRITER_H 

// DocWriter 클래스 상속을 위해 DocWriter 클래스의 
// 정의가 들어있는 헤더 파일을 포함시킬 필요가 있다.
#include "DocWriter.h"

// DocWriter 클래스 상속
class HTMLWriter : public DocWriter
{
public:
    HTMLWriter();
    HTMLWriter(const string& fileName, const string& content);
    ~HTMLWriter();

    // 텍스트를 파일로 저장
    // 이미 DocWriter 클래스에서 가상 함수를 만들었기 때문에
    // 여기서는 virtual를 써주지 않아도 자동적으로 가상함수가 된다.
    // 그러나 이렇게 자식 클래스에서도 virtual 키워드를 붙여주는 것이 일반적이다.
    virtual void Write();

    // 폰트 지정
    void SetFont(const string& fontName, int fontSize, const string& fontColor);

protected:
    string _fontName;
    int _fontSize;
    string _fontColor;
};

#endif 