//The code is a simplified version of the example code for Practical 7.1
#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <iomanip>

using namespace std;

class Date {
	friend ostream& operator<<(ostream&, const Date&);
private:
	int day;
	int month;
	int year;
	static const int days[]; // array of days per month
	void helpIncrement(); // utility function for incrementing date

public:
	Date(int = 1, int = 1, int = 0);
	void setDate(int, int, int);
	bool leapYear(int) const; // is date in a leap year?
	bool endOfMonth(int) const; // is date at the end of month?
	Date& operator++(); // prefix increment operator
	Date operator++(int); // postfix increment operator
	const Date& operator+=(int); // add days, modify object
	bool operator<(const Date&) const;

	void showdate();
};

const int Date::days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

void Date::setDate(int dd, int mm, int yy) {
	year = yy;
	month = (mm >= 1 && mm <= 12) ? mm : 1;

	if (month == 2 && leapYear(year))
		day = (dd >= 1 && dd <= 29) ? dd : 1;
	else
		day = (dd >= 1 && dd <= days[month]) ? dd : 1;
}

// if the year is a leap year, return true; otherwise, return false
bool Date::leapYear(int testYear) const {
	if (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0))
		return true;
	else
		return false;
}

// determine whether the day is the last day of the month
bool Date::endOfMonth(int testDay) const {
	if (month == 2 && leapYear(year))
		return testDay == 29;
	else
		return testDay == days[month];
}

// function to help increment the date
void Date::helpIncrement() {
	if (!endOfMonth(day))
		day++;
	else if (month < 12) {
		month++;
		day = 1;
	} else {
		year++;
		month = 1;
		day = 1;
	}
}

// overloaded prefix increment operator
Date& Date::operator++() {
	helpIncrement();
	return *this;
}

// overloaded postfix increment operator; note that the
// dummy integer parameter does not have a parameter name
Date Date::operator++(int) {
	Date temp = *this;
	helpIncrement();

	return temp;
}

// add specified number of days to date
const Date& Date::operator+=(int additionalDays) {
	for (int i = 0; i < additionalDays; i++)
		helpIncrement();

	return *this;
}

// overloaded output operator
ostream& operator<<(ostream &output, const Date &d) {
	output << setfill('0') << setw(2) << d.day << '/' << setw(2) << d.month
			<< '/' << setw(4) << d.year;

	return output;
}

bool Date::operator<(const Date &right) const {
	return (year < right.year || (year == right.year && month < right.month)
			|| (year == right.year && month == right.month && day < right.day));
}

void Date::showdate() {
	cout << "The date is ";
	cout << setfill('0') << setw(2) << day << '/' << setw(2) << month << '/'
			<< setw(2) << year % 100 << endl;
	return;
}

#endif /* DATE_H_ */
