#ifndef DATE2_4_H_
#define DATE2_4_H_
#include<iostream>
#include<iomanip>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date(int d=27, int m=8, int y=2018){
	this->day = d;
	this->month = m;
	this->year = y;
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



#endif /* DATE2_4_H_ */
