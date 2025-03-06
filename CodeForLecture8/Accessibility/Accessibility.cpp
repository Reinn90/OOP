/*
 * Accessibility.cpp
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
protected:
	int r;
public:
	void sum() {
		//r=x+y+z;
		r= getX()+y+z;
	}
	int getR() {return r;}
};

class E:public D {
public:
    void print() {
        cout<<getX()+y+z+r;
    }
};

int main() {
	E e;
	cout << e.z << endl;
	e.sum();
	cout << e.getR() << endl;
	e.print();
	return 0;
}

