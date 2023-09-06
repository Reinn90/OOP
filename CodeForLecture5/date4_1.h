#ifndef DATE4_1_H_
#define DATE4_1_H_
#include<iostream>
#include<iomanip>
using namespace std;



class Date {
private:
	// doesn't print out, as it is replaced by the constructor
	int day = 20;
	int month = 8;
	int year = 2018;

public:
	Date() //Constructor
	{
	day = 19;
	month = 8;
	year = 2018;
	}

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


#endif /* DATE4_1_H_ */

