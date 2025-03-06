#include<iostream>
#include<cmath>

using namespace std;

class One {
protected:
	double a;
public:
	One(double val = 1.0): a(val){}
	virtual ~One() {}

	virtual double f1(double); // dynamic binding
	double f2(double);
};

double One::f1(double num) {
	return num + 1;
}

double One::f2(double num) {
	return f1(num) * f1(num);
}

class Two: public One {
public:
	double f1(double);
};

double Two::f1(double num) {
	return (num + 2);
}

int main() {
	One object1;
	Two object2;

	cout << "the computed value using the base class object is "
			<< object1.f2(3) << endl;

	// now that f1 is virtual, polymorphism
	// allows for the most recent implementation of f1 in Class TWO
	// to be used. ie. number get's 2 added, then squared
	cout << "the computed value using the derived class object is "
			<< object2.f2(3) << endl;

	return 0;
}
