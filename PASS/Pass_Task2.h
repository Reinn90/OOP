#include <iostream>
#include <cmath>
using namespace std;

class division
{
private:
    int numerator;
    int denominator;
    int quotient;
    int remainder;
    void calculateQuotientRemainder();

public:
    void set(int, int);
    
    void print();
};

void division::set(int n, int d){
    numerator = n;
    denominator = d;
}


void division::calculateQuotientRemainder()
{
    quotient = numerator / denominator;
    remainder = numerator % denominator;
}

void division::print()
{
    calculateQuotientRemainder();
    cout << "The quotient of " << numerator << "/" << denominator << " is: " << quotient << endl;
    cout << "The remainder of " << numerator << "/" << denominator << " is: " << remainder << endl;
}
