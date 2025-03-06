#include <iostream>
#include <string>
using namespace std;

class Base {
public:
  // void f() const {
  //   cout << "Base::f()\n";
  // }

  // void f(string) const {
	//   cout << "Base::f(string)\n"<< endl;
  // }

virtual void f() const {
    cout << "Base::f()\n";
  }

virtual  void f(string) const {
	  cout << "Base::f(string)\n"<< endl;
  }

 virtual ~Base(){}
};

//Overriding an overloaded function
class Derived1 : public Base {
public:
  void f() const {
    cout << "Derived1::f()\n";
  }

 void f(string s) const {
   cout << "Derived2::f(string)\n";
   return;
 }
};

int main() {
string s = "hello";

//Test 1
  Derived1 d1;
  d1.f();

//Test 2
  Derived1 d2;
  d2.f(s);

  return 0;
}
