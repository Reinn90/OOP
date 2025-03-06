#include<iostream>

using namespace std;

class A {

	private: int num ;

	public:
		int getNumber() { return num ; }

		A(int i=0) { num=i; cout << i << " ctor" << endl;}

		~A() { cout << num << " dtor" << endl; }
};

int main() {
	A x(1) ;
	{
		{
			A y(2);
		}
		A z(3);
	}
	return 0;
}



