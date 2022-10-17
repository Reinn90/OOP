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

	void display();

	bool operator<(Date);

	bool operator==(Date);

};

void Date::display() {
    cout << day << "  " << month << "   " << year << endl;
}

// comparing the intical constructor values to new 'd.date' type
bool Date::operator<(Date d) {
	if(year < d.year )
		return true;

	if(year == d.year && month < d.month)
		return true;

	if(year == d.year && month == d.month && day < d.day)
		return true;

	return false;
}

bool Date::operator==(Date d) {
	if(year == d.year && month == d.month && day == d.day)
		return true;

	return false;
}
