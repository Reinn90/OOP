#include <iostream>
#include <cmath>

using namespace std;

void quotientRemainder(int numerator, int denominator, int& quotient, int& remainder) {
   quotient = numerator / denominator;
   remainder = numerator % denominator;
}


int main()
{
    int numerator, denominator, quotient, remainder;

    numerator = 10;
    denominator = 3;
    quotient = 0;
    remainder = 0;

    quotientRemainder(numerator, denominator, quotient, remainder);

    cout << "The quotient of " << numerator << "/" << denominator << " is: " << quotient << endl;
    cout << "The remainder of " << numerator << "/" << denominator << " is: " << remainder << endl;
    


    return 0;
}