#include<iostream>
using namespace std;

int f(int& x, int& y) {
	x = 1; 
	y = 2;
	return 0; // since x and y are passed by ref,
	// function returns zero but x and y will get the values 1 and 2
}

int main() {

	// int a = 5;
	// int& b = a; // b = 5

	// // b = 10;
	// a = 20; // this also changes b as b is by reference
	// cout << "a=" << a << "  b=" << b << endl;

	int a, b;
   f(a,b);
	cout << "a=" << a << "  b=" << b << endl; // a = 1, b = 2

	int c=5, d;
   d = f(c,d); // return 0 will be stored in d and c= 1
	cout << "c=" << c << "  d=" << d << endl;


	f(5,d); // not allowed as cannot pass ACTUAL value, have to be a variable name ie. int z = 5, then pass z

	return 0;
}
