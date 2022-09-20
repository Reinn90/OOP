/*
 * Accessibility2.cpp
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

class D: public B {
private:
	int r;
public:
	void sum() {
		//r=x+y+z;
		r= getX()+y+z;
	}
	int getR() {return r;}
};

int main() {
	D d;
//	cout << d.x << endl;
//	cout << d.y << endl;
	cout << d.z << endl;
	d.sum();
	cout << d.getR() << endl;
	return 0;
}

