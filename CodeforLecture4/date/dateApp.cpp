#include<iostream>
#include<string>

using namespace std;

#include "date.h"

int main() {
	Date d;
   
	d.day = 10;
    d.month = "August";
	d.year = 2019;
   
	cout << d.day << "  " << d.month << "   " << d.year << endl;

	return 0;
}
