#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    // initialise variables
    int product;

    //nested for loop to go numbers through 1-10
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            // print the products of both numbers
            cout << i*j << " ";
        }

        cout << endl;
    }

    return 0;
}