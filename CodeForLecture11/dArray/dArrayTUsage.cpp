// dArrayTUsage.cpp 
// Trying the dArray Class
#include <iostream> 
using namespace std;

#include"dArrayT.h"

int main() { 
	dArrayT<int> a1(10);
	
	a1.insert(0, 10); 
	a1.insert(1, 20); 
	a1.insert(2, 30);

	int i;
	for(i=0;i<a1.length();i++) {
       cout << a1[i] << "  ";
	}
     
	cout << endl;

	//numb = array.operator[1];

    a1[1] = 40;

	for(i=0;i<a1.length();i++) {
       cout << a1[i] << "  ";
	}
    cout << endl;

	a1.remove(1);

	for(i=0;i<a1.length();i++) {
       cout << a1[i] << "  ";
	}
    cout << endl;

	dArrayT<char> a2(10);

	a2.insert(0, 'H');
	a2.insert(1, 'e');
	a2.insert(2, 'l');
	a2.insert(3, 'l');
	a2.insert(4, 'o');

	for(i=0;i<a2.length();i++) {
       cout << a2[i] <<" ";
	}
    cout << endl;

	return 0;
}
