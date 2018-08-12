#include "DocWriter.h"

int main()
{
    DocWriter dw;
    dw.SetFileName( "test.txt" );
    dw.SetContent("You must be a good programmer~!!");
    dw.Write();

    return 0;
}