#include<iostream>
#include <string>

class Date {
private:
	int day;
	int month;
	int year;
	string mapping(int);
public:
	void setDate(int, int, int);
	void display();
	void showdate();
};

void Date::setDate(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}
void Date::display() {
	cout << "The date is ";
    cout << day << " ";
	cout << mapping(month);
	cout << " " << year << endl;
}

void Date::showdate() {
  cout << "The date is ";
  cout << setfill('0') 
	      << setw(2) << day << '/'
	      << setw(2) << month << '/'
	      << setw(2) << year % 100
	      << endl;
}

string Date::mapping(int month) {
	string map[12] ={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	return map[month-1];
}
