#include<iostream>
using namespace std;

class A {
	private: int val ;
	public:
		A() { val=0; } // constructor
		int value() {return val;}
};


class B {
	private: int val ;
	public:
		//B(){val=0;}
		B(int i) { val=i; }
		int value() {return val;}
};


class C {
	private: int val ;
	public:
		int value() {return val;}
}; // default constructor


int main() {

	A a;
	cout << a.value() << endl;

	//B b; //if you have a constructor, there is no default constructor.

	//cout << b.value() << endl;

	C c;
	cout << c.value() << endl;
	return 0;
}

