#include<iostream>
#include <string>

class Date {
protected:
	int day;
	int month;
	int year;
public:
	Date(int, int, int);
	void display();
};

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}
void Date::display() {
	cout << "The date is: ";
    cout << day << ", ";
	cout << month << ", ";
	cout << " " << year << endl;
}
