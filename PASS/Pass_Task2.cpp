#include <iostream>

using namespace std;

#include "Pass_Task2.h"

int main(){

    // select class
    division d;

    //take in user input
    cout << "Enter a numerator and a denominator: " << endl;
    int num; int den;
    cin >> num >> den; cout << endl;

    d.set(num,den); //pass to object
    d.calculateQuotientRemainder(); //calculate quotient and remainder 
    d.print(); //  and print result

    return 0;
}