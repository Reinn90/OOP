#include<iostream>

using namespace std;

int* f(int size) {
//	int a[size];// legal but does not make sense
//	static int a[size]; //illegal
	int* a= new int[size];
	for (int i = 1; i <= 5; i++)
		a[i] = i * 10;

	return a;
}

int main() {
	int *ptr, size = 3;

	ptr = f(size);

for(int i=0;i<5;i++)
	cout << ptr[i] << " ";

	delete ptr;
	
	return 0;
	
}
