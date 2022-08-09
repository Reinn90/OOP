#include <iostream>
#include <cstdlib>

using namespace std;

int main( )
{
    srand(time(0));

    cout <<"The value of constant RAND_MAX: "<< endl;
    cout << RAND_MAX << endl;

    cout <<"Generate a random number between 0-RAND_MAX: "<< endl;
    cout << rand() << endl;

    cout <<"Generate a random number between 0-9, inclusive: "<< endl;
    cout << rand()%10 << endl;

    cout <<"Generate a random number between 1-100, inclusive: "<< endl;
    cout << rand()%100 + 1 << endl;

    cout <<"Generate a random number between 0.0 - 1.0: "<< endl;

    cout << (double) (RAND_MAX-rand())/ (double) RAND_MAX << endl;

     return 0;
}




