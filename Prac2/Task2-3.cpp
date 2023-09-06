#include <iostream>
#include <cmath>

using namespace std;

void testDefaultArg(int day = 1, string month = "Jan", int year = 2020)
{
    cout << "Today is " << day << " " << month << " " << year << endl;
}

int main()
{

    testDefaultArg();                   // "Today is 1 Jan 2020"
    testDefaultArg(10);                 // "Today is 10 Jan 2020"
    testDefaultArg(10, "Jul");          // "Today is 10 Jul 2020"
    testDefaultArg(10, "Jul", 2021);    // "Today is 10 Jul 2021"

    return 0;
}