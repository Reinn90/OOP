#include<iostream>
using namespace std;

int main()
{
    int count_1 = 0 ;
    int count_2 = 0 ;
    int n = 20 ;
    while (n>0)
    {
        --n ;
        cout << ++count_1 << endl ;
        cout << count_2++ << endl ;
        cout << endl ;
    }
    cout << "final value for count_1 = " << count_1 << endl ;
    cout << "final value for count_2 = " << count_2 << endl ;
    cout << endl ;
    return 0;
}