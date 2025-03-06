#include<iostream>

using namespace std;

int main() {
	int v1 = 8;
	int v2 = 9;
	int *p1, *p2;
	p1 = &v1;
	p2 = &v2;

	cout << *p1 << "   " << *p2 << endl;

//	p2 = p1;
//	cout << *p1 << "   " << *p2 << endl;

	return 0;
}

