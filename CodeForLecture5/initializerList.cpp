// This example illustrates explicit initialization
// by constructor.

#include <iostream>
#include<iomanip>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date(): day(27), month(8), year(2018){}
	Date(int d, int m, int y): day(d), month(m), year(y){}
	void setDate(int, int, int);
	void showdate();

};

void Date::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

void Date::showdate() {
  cout << "The date is ";
  cout << setfill('0')
	      << setw(2) << day << '/'
	      << setw(2) << month << '/'
	      << setw(2) << year % 100
	      << endl;
}

int main() {
//	Date a;
	Date a(27, 8,2018);

	a.showdate();

	return 0;
}

