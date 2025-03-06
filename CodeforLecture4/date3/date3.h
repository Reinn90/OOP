#include <iostream>
#include <string>

class Date
{
private:
	int day;
	string month;
	int year;

public:
	void setDay(int d)
	{
		day = d;
	}

	void setMonth(string m)
	{
		month = m;
	}

	void setYear(int y)
	{
		year = y;
	}
	
	void display()
	{
		cout << day << "  " << month << "   " << year << endl;
	}
};
