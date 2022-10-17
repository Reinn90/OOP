#include <iostream>
using namespace std;

int main()
{

    int a = 10;
    int *pa;
    pa = &a;

    cout << "Value of a: " << a << endl;
    cout << "Memory address of pa: " << pa << endl; // memory address, CAN ALSO USE &pa
    cout << "Value of pa: " << *pa << endl; // value of 10, USING * TO DEREFERENCE 


    return 0;
}