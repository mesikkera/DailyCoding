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
    ~HTMLWriter();

    // 텍스트를 파일로 저장
    void Write();

    // 폰트 지정
    void SetFont(const string& fontName, int fontSize, const string& fontColor);

protected:
    string _fontName;
    int _fontSize;
    string _fontColor;
};

#endif 