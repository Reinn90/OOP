#include<iostream>
#include<string>

class Date {
private:
	int day;
	string month;
	int year;
public:
	void setDate(int, string, int);
	void display();
};

void Date::setDate(int d, string m, int y) {
    day = d;
    month = m;
    year = y;
}

void Date::display() {
    cout << day << "  " << month << "   " << year << endl;
}
