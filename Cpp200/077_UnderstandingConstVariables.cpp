#include <iostream>
#include <string>

using namespace std;

int main()
{
    // const: »ó¼ö.
    const string kMyJob = "developer";

    string question = "who are you : ";
    string answer = "my job is : " ;

    cout << question << kMyJob << endl;
    cout << answer << kMyJob << endl;
    return 0;
}