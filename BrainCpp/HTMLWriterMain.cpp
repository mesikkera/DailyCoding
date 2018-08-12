#include "HTMLWriter.h"

int main()
{
    // HTMLWriter hw;
    // hw.SetFileName("test.html");
    // hw.SetContent("Auto Generated HTML Document");
    // hw.SetFont("D2Coding", 20, "Red");
    // hw.Write();
    HTMLWriter hw("test.html", "Auto Generated HTML Document");

    // 부모 클래스의 포인터로 가리킨다.
    DocWriter* pdw = &hw;

    //hw.Write();
    //  포인터를 사용해서 저장함수 호출
    pdw->Write();
    
    return 0;
}