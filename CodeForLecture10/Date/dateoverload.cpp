#include<iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "date.h"

int main() {
	Date d(29,9,2021);

	cout << "Date 1: " << d << endl; // check << overloading

	cout << "Date 2: " << ++d << endl; // prefix increment
    cout << "Date 3: " << d++ << endl; // postfix increment

    cout << "Date 3: " << d << endl; // postfix increment

    d.helpIncrement();
	cout << "Date 4: " << d << endl;


	d.setDate(28,9,1962);

	d++; // increment one day
    cout << "Date 5: " << d << endl;

    d += 40; // accumulation
    cout << "Date 6: " << d << endl;

	d += 4000; // accumulation
    cout << "Date 7: " << d << endl;

    return 0;

}
