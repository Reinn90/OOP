#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

int main() {

	int array[5] = {1,2,3,4,5};

	for (int x: array)
		cout << x << "  ";

	cout << endl;

	vector<double> vec;
	vec.push_back(1.01);
	vec.push_back(2.02);
	vec.push_back(3.03);
	vec.push_back(4.04);
	vec.push_back(5.05);
    //vector<int>::iterator itor;
	for(double x: vec)
		cout << x << " ";

	cout <<endl;


	return 0;
}


