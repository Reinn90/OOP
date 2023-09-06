#include<iostream>
#include<string>

using namespace std;

#include "date1.h"

int main() {
	Date d;
   
	d.day = 10;
    d.month = "Aug";
	d.year = 2019;

	d.display();
	
	return 0;
}
