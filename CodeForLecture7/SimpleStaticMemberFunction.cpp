#include<iostream>
using namespace std;

class X {
private:
	static int i;
public:
	static int f(){ i++; return i;};
};

int X::i = 10;

int main() {
//   X x1,x2;
   cout << X::f() << "   "  << X::f() << "   " << X::f() << "   " << endl;
   
   return 0;
} ///:~
