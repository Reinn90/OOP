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
	void setDate(int, int, int);
	void showdate(string);

};


Date::Date(){
	day = 0;
	month = 0;
	year = 0;
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

