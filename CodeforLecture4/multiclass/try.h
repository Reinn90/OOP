/*
 * try.cpp
 *
 *  Created on: 19/08/2014
 *      Author: dongmo
 */

class A {
private:
  int a, b;
public:
  void init();
  int f();
};

void A::init() {
  a = 1;
  b = 2;
  return;
}

int A::f() {
  return a+b;
}

