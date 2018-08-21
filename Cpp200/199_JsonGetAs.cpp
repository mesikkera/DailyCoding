#include <fstream>
#include <iostream>
#include "json/json.h"

using namespace std;
using namespace Json;

int main()
{
    ofstream json_write;
    json_write.open("json_exam3.json");

    Value root;
    root["Title"] = "Convert Exam";
    root["IsJson"] = true;

    Value numbers;
    numbers["No1"] = 12;
    numbers["No2"] = 20.3;

    root["Array"]["Number"] = numbers;

    json_write << root;
    json_write.close();

    ifstream json_open("json_exam3.json");
    Reader reader;
    Value value;
    reader.parse(json_open, value);

    cout << value["Array"]["Number"].get("No1", -1).asInt() << endl;
    cout << value["Array"]["Number"].get("No2", -1).asDouble() << endl;
    cout << value["Array"]["Number"].get("No1", "Empty").asString() << endl;
    cout << value.get("IsJson", false).asBool() << endl;

    return 0;
}