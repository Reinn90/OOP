#include <iostream>
class B {
public:B();
  B(int nn);
  void f();
protected:
  void g();
private:
  int n;
};

class D : public B {
public:
  D(int nn, float dd);
protected:
  void h();
private:
  void k();
  double d;
};


int main() {

  D obj(1,1.2);

  obj.f();

  obj.k();


  return 0;
}