#include "HTMLWriter.h"

int main()
{
    HTMLWriter hw;
    hw.SetFileName("test.html");
    hw.SetContent("Auto Generated HTML Document");
    hw.SetFont("D2Coding", 20, "Red");
    hw.Write();

    return 0;
}