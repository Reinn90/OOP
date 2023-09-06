/*
 * Accessibility.cpp
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
	B() {x=10;y=20;z=30;}
};


class D :public B {
private:
	int r;
public:
	int sum() {
//		r= x+y+z;
		r= y+z;
		return r;
	}
};

int main() {
	D d;
//	cout << d.x << endl;
//	cout << d.y << endl;
	cout << d.z << endl;
	cout << d.sum() << endl;
	return 0;
}




