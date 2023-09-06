#include<iostream>

using namespace std;

#include "date6.h"

int main() {
	Date d;
	
	d.showdate("Initial date is ");

	d.setDate(6,8,2019);
   
	d.showdate("Today is ");
    
	return 0;
}
