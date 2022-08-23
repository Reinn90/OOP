#include<iostream>

using namespace std;

#include "date4_2.h"

int main() {
	Date d;
	d.showdate("Initial date of d is ");

	Date d1(13);
	d1.showdate("Initial date of d1 is ");

	Date d2(13,8);
	d2.showdate("Initial date of d2 is ");

	Date d3(13,8,2019);
	d3.showdate("Initial date of d3 is ");


	return 0;
}
