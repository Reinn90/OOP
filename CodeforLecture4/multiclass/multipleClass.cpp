#include<iostream>
#include "try.h"

using namespace std;


class B {
  int a, b;
public:
  void init();
  int f();
};

void B::init() { 
  a = 10;
  b = 20;
  return;
}

int B::f() { 
  return a*b; 
} 

int main() {
  A a;
  B b;
  a.init();
  cout << a.f() << endl;
  b.init();
  cout << b.f() << endl;
  return 0;
}
