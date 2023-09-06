#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

int main() {
	double cArray[5] = {3.5, 2.3, 5.7, 2.1, 0.1};
	vector<double> stlArray(cArray, cArray + 5); 

	ostream_iterator<double> output(cout, " "); //this is output stream iterator
	cout << "The original array: " << endl;
	copy(stlArray.begin(), stlArray.end(), output); //copy is STL algorithm
	cout << endl;

	cout << "Sorted array: " <<endl;
	sort(stlArray.begin(), stlArray.end());  //sort is STL algorithm
	copy(stlArray.begin(), stlArray.end(), output);
	cout << endl;

	vector<double>::iterator pos;
	pos = find(stlArray.begin(), stlArray.end(), 2.1);
	
	if (pos == stlArray.end())
		cout << "The number  was not found  "<< endl;
	else 
		cout << "The number was found at the position " 
		     << pos-stlArray.begin() << endl;

	cout << "The sum of the elements is " << accumulate(stlArray.begin(), stlArray.end(), 0) << endl;
	return 0;
}
