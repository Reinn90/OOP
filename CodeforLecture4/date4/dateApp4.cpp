#include<iostream>
#include<iomanip>
using namespace std;

#include "date4.h"

int main() {
	Date d;
   
	d.setDate(10,"Aug",2019);
   
	d.display();

	return 0;
}
