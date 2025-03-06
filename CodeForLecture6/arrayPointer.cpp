#include<iostream>

using namespace std;

int main() {

	 int a[] = { 1, 2, 3, 4, 5 };
	 cout << a << "   "  << &a[0] << endl;

	 cout << *a << endl;
	 cout << *(a+1) << endl;

	 cout << endl;

	 for(int i=0;i<5;i++) {
		 cout << *(a+i) << " ";
	 }

	return 0;
}
