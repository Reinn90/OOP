#include<iostream>
#include<iomanip>
using namespace std;

class Date {
	friend void display(Date);
private:
	int day;
	int month;
	int year;
public:
	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
//	void display();
};

void display(Date d) { //non-member function of class Date
    cout << d.day << "  " << d.month << "   " << d.year << endl;
}

int main() {
	Date today(21,9,2020);
	display(today); // not an object of class Date but still able to access all Date class member functions
	return 0;
}
