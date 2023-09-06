
#include <iostream>

using namespace std;

void change(int *fvar) {
	*fvar = 5;
}

int main() {

	int var = 3;

	int *varPtr;

	varPtr = &var;

	cout << " the value of var is " << *varPtr << endl;

	change(varPtr);

	cout << " the value of var is " << *varPtr << endl;

	return 0;
}
