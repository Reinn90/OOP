#include <iostream>

using namespace std;

const int SIZE = 10;

class ooArray {
	int a[SIZE];
	int size;
public:
	ooArray(int s) {
		size = s;
	}
	void fillArray();
	void printArray();
};

void ooArray::fillArray() {
	for (int i = 0; i < size; i++)
		a[i] = rand() % 100;
}

void ooArray::printArray() {
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
}

int main() {
	srand(time(0));

	ooArray oo(SIZE);

	cout << "Generate " << SIZE << " random integers (0-100) ... " << endl;
	oo.fillArray();

	char c;
	cin >> c;

	cout << "Here are the integers: ";
	oo.printArray();

	return 0;
}
