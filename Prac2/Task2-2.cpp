#include <iostream>
#include <cmath>
using namespace std;

void testOverloading(int numerator, int denominator)
{
    int fraction = numerator / denominator;
    cout << "Fraction1 = " << fraction << endl;
}
void testOverloading(double numerator, double denominator)
{
    double fraction = numerator / denominator;
    cout << "Fraction2 = " << fraction << endl;
}

void testOverloading(int numerator, double denominator)
{
    double fraction = numerator / denominator;
    cout << "Fraction3 = " << fraction << endl;
}

int main() {

    // function one - two integers
    testOverloading(3,7);

    // function two - two doubles
    testOverloading(3.0, 7.0);

    // function three - one integer, one double
    testOverloading(3, 7.0);

    return 0;
}