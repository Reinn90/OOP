#include "date5.h"

int main() {
	Date d1(20,9,2020), d2(18,9,2020);

	d1.display();
	d2.display();

	if( (d1 < d2) && !(d1 == d2))
    	cout << "d1 is earlier than d2!" << endl;
    else
    	cout << "d1 is not earlier than d2!" << endl;

	return 0;
}
