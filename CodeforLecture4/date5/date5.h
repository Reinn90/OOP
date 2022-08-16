#include<string>
#include<iomanip>

using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	void setDate(int, int, int);
	void showdate(string);

};

void Date::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

void Date::showdate(string s) {
  cout << s	 << endl;
  cout << setfill('0')
	      << setw(2) << day << '/'
	      << setw(2) << month << '/'
	      << setw(2) << year % 100;

 cout << endl;
}

