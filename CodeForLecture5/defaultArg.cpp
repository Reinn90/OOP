#include<iostream>
using namespace std;

class Time
{
private:
	int hrs;
	int mins;
	int secs;
public:
	Time(int=0, int=0, int=0);
	void display() {cout << hrs << ":" << mins << ":" << secs << endl;}
};

Time::Time(int h, int m, int s) {
	hrs = h;
	mins = m;
	secs = s;
}

int main()
{
	Time t;
	Time t1(1);
	Time t2(2,20);
	Time t3(3,30,30);

	t.display();
	t1.display();
	t2.display();
	t3.display();
	return 0;
}
