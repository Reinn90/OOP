#include<iostream>
#include<string>

using namespace std;

int main() {

	int *ptr1;
	int value = 100;
	ptr1 = &value; //legal
	cout << *ptr1 << endl;

//	value = 200;
//	cout << *ptr1 << endl;

//	    double *ptr2;
//		ptr2 = &value; //illegal

//	string *ptr3;
//	string mystring("hello");
//	ptr3 = &mystring;
//	cout << *ptr3 << endl;
//
//
//	ptr1 = 0x7ffee93b3154; //illegal
	cout << *ptr1 << endl;

}
