#include<iostream>
#include<iomanip>
using namespace std;

class Date {
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

	void setDay(int d) {day = d;}

	void setMonth(int m) {month = m;}

	void setYear(int y) {year = y;}

	int getDay() {return day;}

	int getMonth() {return month;}

	int getyear() {return year;}

	void display();

//	bool operator<(Date);
};

void Date::display() {
    cout << day << "  " << month << "   " << year << endl;
}

//bool Date::operator<(Date d) {
//	if(year < d.year )
//		return true;
//
//	if(year == d.year && month < d.month)
//		return true;
//
//	if(year == d.year && month == d.month && day < d.day)
//		return true;
//
//	return false;
//}
