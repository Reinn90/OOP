#include<iostream>

using namespace std;

struct Date {
private:
  string mapping(int); 

public:
	int day;
	string month;
	int year;

	void display();
};

void Date::display() {
    cout << day << "  " << month << "   " << year << endl;
}

