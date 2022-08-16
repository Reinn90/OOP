#include<iostream>
#include<string>

using namespace std;

#include "date3.h"

int main() {
	Date d;
   
	//d.day = 10;
    //d.month = "Aug";
	//d.year = 2019;
   
	d.setDay(10);
	d.setMonth("Aug");
	d.setYear(2019);

	//cout << d.day << "  " << d.month << "   " << d.year << endl;

	d.display();
	return 0;
}
