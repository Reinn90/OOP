#include <iostream>

using namespace std;

const int SIZE = 10;

class ooArray {
public:
	void fillArray(int a[], int size){
		for (int i = 0; i < size; i++)
			a[i] = rand() % 100;
	}

	void printArray(int a[], int size){
		for (int i = 0; i < size; i++)
			cout << a[i] << " ";
	}
};

int main() {
	int arr[SIZE];
	srand(time(0));

	ooArray oo;

	cout << "Generate " << SIZE << " random integers (0-100) ... " << endl;
	oo.fillArray(arr, SIZE);

	char c;
	cin >> c;

	cout << "Here are the integers: ";
	oo.printArray(arr, SIZE);

	return 0;
}
