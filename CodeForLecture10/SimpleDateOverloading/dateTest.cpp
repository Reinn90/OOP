#include<iostream>
#include<iomanip>

using namespace std;

#include "date6.h"

int main() {

//Test 1
// 	cout << "Test 1:  " << endl;

// 	Date d1(21, 9, 2020), d2;
// 	d1.display(); // display 21/09/2020
// 	d2 = ++d1; // increase d1 by 1 day(ie, 22/09/2020 and store in d2)
// 	d2.display(); // display 22/09/2020
//    ++d1; // d1 = 23/09/2020
// 	d1++; // d1 = 24/09/2020
//    d1.display();

////Test 2
	// cout << "\nTest 2:  " << endl;

	// Date d3(21, 9, 2020), d4;
	// d3.display(); // display 21/09/2020
	// d4 = d3++; // d4 = 21/09/2020 THEN increment d3++
	// d4.display(); // display 21/09/2020
	// d3.display(); // 22/09/2020


	Date d(21,9,2021);
//Test 3
	// cout << "\nTest 3:  " << endl;
	// (d++).display(); // .display gets called first, then the increment ie 21/09/2020
	// d.display(); // 22/09/2020

//Test 4
	cout << "\nTest 4:  " << endl;
	(++d).display(); // increment first, then call function ie. 22/09/2020
	d.display(); // 22/09/2020
	return 0;
}
