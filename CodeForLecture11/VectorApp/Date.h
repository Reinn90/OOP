/*
 * Date.h
 *
 *      Author: dongmo
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <iomanip>

using namespace std;

class Date {
	friend ostream &operator<<(ostream &, const Date &);
private:
	int day;
	int month;
	int year;
	static const int days[]; // array of days per month
	void helpIncrement(); // utility function for incrementing date

public:
	Date(int = 1, int = 1, int = 0);
	void setDate(int, int, int);

	int getMonth() {
		return month;
	}

	//New added
	Date dayAfter() {
		Date tempDate = *this;
		tempDate += 2;
		return tempDate;
	}

	bool leapYear(int) const; // is date in a leap year?
	bool endOfMonth(int) const; // is date at the end of month?
	Date &operator++(); // prefix increment operator
	Date operator++(int); // postfix increment operator
	const Date &operator+=(int); // add days, modify object
	Date operator+(int offset);
	bool operator<(const Date& d) const;

	void showdate();
};

const int Date::days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
	// initialize static member at file scope; one classwide copy
}

// set month, day and year
void Date::setDate(int dd, int mm, int yy) {
	year = yy;
	month = (mm >= 1 && mm <= 12) ? mm : 1;

	// test for a leap year
	if (month == 2 && leapYear(year))
		day = (dd >= 1 && dd <= 29) ? dd : 1;
	else
		day = (dd >= 1 && dd <= days[month]) ? dd : 1;
} // end function setDate

// if the year is a leap year, return true; otherwise, return false
bool Date::leapYear(int testYear) const {
	if (testYear % 400 == 0 || (testYear % 100 != 0 && testYear % 4 == 0))
		return true; // a leap year
	else
		return false; // not a leap year
} // end function leapYear

// determine whether the day is the last day of the month
bool Date::endOfMonth(int testDay) const {
	if (month == 2 && leapYear(year))
		return testDay == 29; // last day of Feb. in leap year
	else
		return testDay == days[month];
} // end function endOfMonth

// function to help increment the date
void Date::helpIncrement() {
	// day is not end of month
	if (!endOfMonth(day))
		day++; // increment day
	else if (month < 12) // day is end of month and month < 12
			{
		month++; // increment month
		day = 1; // first day of new month
	} // end if
	else // last day of year
	{
		year++; // increment year
		month = 1; // first month of new year
		day = 1; // first day of new month
	} // end else
} // end function helpIncrement

// overloaded prefix increment operator
Date &Date::operator++() {
	helpIncrement(); // increment date
	return *this; // reference return to create an lvalue
} // end function operator++

// overloaded postfix increment operator; note that the
// dummy integer parameter does not have a parameter name
Date Date::operator++(int) {
	Date temp = *this; // hold current state of object
	helpIncrement();

	// return unincremented, saved, temporary object
	return temp; // value return; not a reference return
} // end function operator++

// add specified number of days to date
const Date &Date::operator+=(int additionalDays) {
	for (int i = 0; i < additionalDays; i++)
		helpIncrement();

	return *this; // enables cascading
} // end function operator+=

// overloaded output operator
ostream &operator<<(ostream &output, const Date &d) {
	output << setfill('0') << setw(2) << d.day << '/' << setw(2) << d.month
			<< '/' << setw(4) << d.year;

	return output; // enables cascading
} // end function operator<<

Date Date::operator+(int offset) {
	Date temp = *this;
    for(int i=0;i<offset;i++)
    	temp.helpIncrement();
    return temp;
}

bool Date::operator<(const Date& d) const {
	if(year < d.year )
		return true;

	if(year == d.year && month < d.month)
		return true;

	if(year == d.year && month == d.month && day < d.day)
		return true;

	return false;
}


void Date::showdate() {
	cout << "The date is ";
	cout << setfill('0') << setw(2) << day << '/' << setw(2) << month << '/'
			<< setw(2) << year % 100 << endl;
	return;
}

#endif /* DATE_H_ */
