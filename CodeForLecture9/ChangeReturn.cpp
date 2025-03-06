#include <iostream>
#include <string>
using namespace std;

class Base {
public:
//   int f() const {
//     cout << "Base::f()\n";
//     return 1;
//   }

	virtual int f() const {
 		cout << "Base::f()\n";
 		return 1;
 	}
};

//  Cannot change return type
class Derived: public Base {
public:
	// void f() const {
	// 	cout << "Derived::f()\n";
	// 	return ;
	// }

	int f() const {
		cout << "Derived1::f()\n";
		return 0;
	}
};

int main() {
	Derived d;
	d.f();

	return 0;
}
