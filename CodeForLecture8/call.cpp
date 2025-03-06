#include <iostream>
using namespace std;

class A
{
public:
	A() { cout << "ctor:A()" << endl; }
	~A() { cout << "dtor:~A()" << endl; }
};

class B : public A
{
public:
	B() { cout << "ctor:B()" << endl; }
	~B() { cout << "dtor:~B()" << endl; }
};

class C : public B
{
public:
 	 C() { cout << "ctor:C()" << endl; }
	~C() { cout << "dtor:~C()" << endl; }
};

int main()
{
	C c;
	return 0;
}
