#include "date4.h"

int main() {
//Test 1
	// Date d1(1, 1, 2020);
	// Date d2(21, 9, 2020);

	// d1.display();
	// d2.display();
	// cout << endl;

	// d1 = d2;

	// d1.display();
	// d2.display();
	// cout << endl;

	// d2.setDay(25);

	// d1.display();
	// d2.display();
	// cout << endl;

// Test 2
	// Date *d1 = new Date(1, 1, 2020);
	// Date *d2 = new Date(21, 9, 2020);

	// d1->display();
	// d2->display();
	// cout << endl;

	// delete d1;//memory is deleted but the pointer still exists

	// d1 = d2;

	// d1->display();
	// d2->display();
	// cout << endl;

	// d2->setDay(25);

	// d1->display(); // d1 pointer is also changed
	// d2->display();
	// cout << endl;

	// delete d2;

//Test 3
	Date d1(1, 1, 2020);
	Date &d2 = d1;

	d1.display();
	d2.display();
	cout << endl;

	d2.setDay(25);

	d1.display();
	d2.display();

	return 0;
}
