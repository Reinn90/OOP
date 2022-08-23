#ifndef DATE4_2_H_
#define DATE4_2_H_
#include<string>
#include<iomanip>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int);
	Date(int,int);
	Date(int,int,int);
	void setDate(int, int, int);
	void showdate(string);
};

Date::Date(){
	day = 0;
	month = 0;
	year = 0;
	cout <<" This is a constructor without any arguments" << endl;
}


Date::Date(int d){
	day = d;
	month = 0;
	year = 0;
	cout <<" This is a constructor with one argument." << endl;
}


Date::Date(int d, int m){
	day = d;
	month = m;
	year = 0;
}


Date::Date(int d, int m, int y){
	day = d;
	month = m;
	year = y;
	cout <<" This is a constructor with three arguments." << endl;

}


void Date::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

void Date::showdate(string s) {
  cout << s;
  cout << setfill('0')
	      << setw(2) << day << '/'
	      << setw(2) << month << '/'
	      << setw(2) << year % 100
	      << endl;
}



#endif /* DATE4_2_H_ */

