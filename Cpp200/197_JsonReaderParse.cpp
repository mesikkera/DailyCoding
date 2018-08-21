#include <fstream>
#include <iostream>
#include "json/json.h"

using namespace std;
using namespace Json;

int main()
{
    ifstream json_dir("json_exam.json");
    Reader reader;
    Value value;

    bool is_parse = reader.parse(json_dir, value);

    if (is_parse == true)
    {
        cout << "Job1 : " << value["Job1"] << endl;
        cout << "SubItem Sub1 : " << value["SubItems"]["Sub1"] << endl;
    }
    else
    {
        cout << "Json 파일을 읽을 수 없습니다.";
    }

    return 0;
}