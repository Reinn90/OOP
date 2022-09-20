/*
 * Accessability3.cpp
 *
 *  Created on: 6 Sep. 2020
 *      Author: dongmo
 */

#include<iostream>

using namespace std;

class B {
private:
	int x;
protected:
	int y;
public:
	int z;
	B() {
		x = 10;
		y = 20;
		z = 30;
	}
	int getX() {
		return x;
	}
};

class D: public B {
protected:
	int r;
public:
	D() {
		r = 40;
	}
	int dSum() {
		return getX() + y + z;
	}
};

class E: public D {
public:
	int eSum() {
		return dSum() + r;
	}
};

int main() {
	E e;
	cout << e.eSum() << endl;
	return 0;
}

