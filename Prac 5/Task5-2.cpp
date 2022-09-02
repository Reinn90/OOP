#include <iostream>
using namespace std;

class TwoD {
private:
	int row;
	int col;
	int** grid;
public:
	TwoD(int, int);
	void fillArray();
	void printArray();
	~TwoD();
};

TwoD::TwoD(int r, int c) {
	row = r;
	col = c;
	grid = new int*[row];

	for (int i = 0; i < row; i++)
		grid[i] = new int[col];
}

TwoD::~TwoD() {
	for (int i = 0; i < row; i++)
		delete[] grid[i];

	delete[] grid;
}

void TwoD::fillArray() {
	//Add your code here
}

void TwoD::printArray() {
	//Add your code here
}

int main() {
	int row, col;
	cout << "Enter the row and column dimensions of the array:\n";
	cin >> row >> col;

	TwoD td(row,col);
	td.fillArray();
	td.printArray();

	return 0;
}
