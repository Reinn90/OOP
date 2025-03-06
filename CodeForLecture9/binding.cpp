#include <iostream>

using namespace std;

class Binding
{
public:
  void print(int value) {
	  cout << "Here is the value from the class: " << value << endl;
  }
};

void print(int value) {
	 cout << "Here is the value from outside: " << value << endl;
}

int main()
{
    Binding b;
    b.print(10);

    print(12);
    return 0;
}
