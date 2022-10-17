#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

int main() {
	double cArray[] = {3.5, 2.3, 5.7, 2.1, 0.1};
	vector<double> stlArray(cArray, cArray + 5);

	cout << "The original array: " << endl;
	for(int i=0;i<stlArray.size(); i++)
		cout << stlArray[i] << " ";

	cout << endl;


	sort(stlArray.begin(), stlArray.end());  //sort is STL algorithm
	cout << "Sorted array: " <<endl;
	for(int i=0;i<stlArray.size(); i++)
		cout << stlArray[i] << " ";


	stlArray.erase(stlArray.begin()+3);

	cout <<"\nThe array after deletion" << endl;

	for(double element: stlArray)
		cout << element << " ";

	cout << endl;

	cout << "The sum of the elements is " << accumulate(stlArray.begin(), stlArray.end(), 0.0) << endl;
	return 0;
}
