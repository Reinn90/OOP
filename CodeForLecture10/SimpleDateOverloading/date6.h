class Date {
private:
	int day;
	int month;
	int year;
public:
	Date(int d=0, int m=0, int y=0) {
		day = d;
		month = m;
		year = y;
	}

	Date operator++() {
		day++;
		return *this;
	}

	Date operator++(int t) {
		Date temp = *this;
		day++;
		return temp;
	}

	void display();
};


void Date::display() {
    cout << day << "/" << month << "/" << year << endl;
}


