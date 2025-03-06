#include <string>
#include <iomanip>
#include <iostream>

#include "Task4-1.h"

using namespace std;

int main() {

	OneDArray arr;
	arr.fillArray();


	arr.search();

    arr.calculateMin();

    cout << "End of program.";
	return 0;
}