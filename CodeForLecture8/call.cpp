#include<iostream>
using namespace std;

class A {
public: 
	A() { cout << "ctor:A()" << endl ; }
	~A() { cout << "dtor:~A()" << endl ; }
};

class B : public A {
public: 
	B() { cout << "ctor:B()" << endl ; }
	~B() { cout << "dtor:~B()" << endl ; }
};

int main() {
	B b ;
	return 0;
}

