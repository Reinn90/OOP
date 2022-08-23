#include<iostream>
#include<iomanip>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date () {day  = 0; month = 0; year = 0;}
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
	cout << setfill('0') << setw(2) << day << '/' << setw(2) << month << '/'
			<< setw(2) << year % 100 << endl;
}

