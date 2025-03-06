/*
 * Accessability3.cpp
 *
 *      Author: dongmo
 */

#include<iostream>

using namespace std;

class B {
private:
	int x;
protected:
	int y;
	int getX() {
		return x;
	}
public:
	int z;
	B() {
		x = 10;
		y = 20;
		z = 30;
	}
};

class D: private B {
protected:
	int r;
public:
	void sum() {
		//r=x+y+z;
		r = getX() + y + z;
	}
	int getR() {
		return r;
	}
};

class E: protected D {
public:
	void print() {
//        cout<<getX()+y+z+r;
//        cout<<z+r;
//		sum();
		cout << r;
	}
};

int main() {
	E e;
//	cout << e.z << endl;
//	e.sum();
//	cout << e.getR() << endl;
	e.print();
	return 0;
}
