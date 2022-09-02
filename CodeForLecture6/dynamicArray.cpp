#include<iostream>
using namespace std;

class DynamicArray {
private:
	int* darray;
	int size;
public:
	DynamicArray(int s) {
		size = s;
		darray = new int[size];
	}

	void input() {
		cout << "Input " << size << " integers:" << endl;
		for (int i = 0; i < size; i++)
			cin >> darray[i];
	}

	void output() {
		cout << "Here is the array:" << endl;
		for (int i = 0; i < size; i++)
			cout << darray[i] << endl;
	}

	~DynamicArray() {
		delete[] darray;
	}
};

int main() {
	int size;
	cout << "Please input the size of the array:" << endl;
	cin >> size;


	DynamicArray dArray(size);

	dArray.input();

	dArray.output();

	return 0;
}
