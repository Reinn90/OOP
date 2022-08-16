#include<iostream>
#include<iomanip>
using namespace std;

#include "date2.h"

int main() {
	class Date d;
   
	d.setDate(3, 8, 2022);
   
	d.display();
	d.showdate();
	
	return 0;
}
