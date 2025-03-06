#include <iostream>
using namespace std;

int func()
{
     static int i = 0; // remembers what the last state of the variable
     // int i = 0; always reverts back to 0
     i++;
     return i;
}

int main()
{
     cout << func() << endl;
     cout << func() << endl;
     cout << func() << endl;
     return 0;
}