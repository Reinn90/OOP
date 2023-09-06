#include <iostream>
using namespace std;

class A
{
  int i;

public:
  A(int ii) : i(ii) { cout << "A's Constructor is called" << endl; }
  ~A() { cout << "A's Destructor is called" << endl; }
  void f() const { cout << "I am function f in Class A" << endl; }
};

class B
{
  int i;

public:
  B(int ii) : i(ii) { cout << "B's Constructor is called" << endl; }
  ~B() { cout << "B's Destructor is called" << endl; }
  void f() const {cout << "I am function f in Class B" << endl;}
};

class C : public A
{
  B b;

public:
  C(int ii) : A(ii), b(ii) { cout << "C's Constructor is called" << endl; }
  ~C() { cout << "C's Destructor is called" << endl; }
  void f() const
  {
    A::f();
    b.f();
    cout << "I am function f in Class C" << endl;
  }
};

int main()
{
  C c(45);
  c.f();
  return 0;
}