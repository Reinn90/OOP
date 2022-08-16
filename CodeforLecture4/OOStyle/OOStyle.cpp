#include<iostream>
using namespace std;

class Prac1_1 {
public:
	void run() {
		cout << "Welcome to OOP class." << endl;
	}
};

class Prac1_3 {
public:
	void run() {
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++)
				cout << i << "*" << j << "=" << i * j << " ";
			cout << endl;
		}
	}
};

int main() {
	Prac1_1 task1;
	task1.run();

	cout << endl;

	Prac1_3 task3;
	task3.run();
	return 0;
}
