#include<iostream>
//#include<cmath>

using namespace std;

class One {
protected:
	double a;
public:
	// Constructor
	// default val = 1.0, assign to a
	// a = 1.0
	One(double val = 1.0): a(val){}

	double f1(double);
	double f2(double);
};

// class function to add 1 to input
double One::f1(double num) {
	return (num + 1);
}

// function to square f1
double One::f2(double num) {
	// pass input to f1 - add 1 to number, THEN square it
	return f1(num) * f1(num);
}

// inherit from One
class Two: public One {
public:
	double f1(double);
};

// add 2 to number input
double Two::f1(double num) {
	return (num + 2);
}

int main() {
	One object1;
	Two object2;

	cout << "the computed value using the base class object is "
			<< object1.f2(3) << endl;

	// f2 functin will call f1 from Class ONE
	cout << "the computed value using the derived class object is "
			<< object2.f2(3) << endl;

	return 0;
}
