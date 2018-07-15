#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    time_t now = time(NULL);
    tm* ptm = localtime(&now);

    char buffer[64];
    strftime(buffer, 64, "Year: %Y, Month: %m, Day: %d, %H:%M:%S (%p)\n", ptm);

    cout << buffer;

    return 0;
}