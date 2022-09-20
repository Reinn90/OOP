#include <iostream>
using namespace std;

class ExampleStatic {
  static int x;
public:
  void next() {x++;}
  
  void print() const {
    cout << "x = " << x << endl;
  }
  
};

int ExampleStatic::x = 10;

int main() {
  ExampleStatic ws;
  ws.next();
  ws.print();
  ws.next();
  ws.print();
  return 0;
} 
