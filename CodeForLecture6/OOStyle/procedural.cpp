#include <iostream>

using namespace std;

const int SIZE = 10;

void fillArray(int a[], int size) {
	for (int i = 0; i < size; i++)
		a[i] = rand() % 100;
}

void printArray(int a[], int size) {
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
}

int main() {
	int arr[SIZE];
	srand(time(0));

	cout << "Generate " << SIZE << " random integers (0-100) ... " << endl;
	fillArray(arr, SIZE);

	char c;
	cin >> c;

	cout << "Here are the integers: ";
	printArray(arr, SIZE);

	return 0;
}
