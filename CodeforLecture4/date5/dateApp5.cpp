#include<iostream>

using namespace std;

#include "date5.h"

int main() {
	Date d1,d2,d3;
   
	d1.setDate(6,8,2019);
	d2.setDate(6,9,2019);
	d3.setDate(11,10,2019);
   
	d1.showdate("Today is ");
    d2.showdate("The due date for assignment 1 is ");
    d3.showdate("The due date for assignment 2 is ");

	return 0;
}
