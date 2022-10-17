#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

int main() {

	vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	//Test 1
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	cout << endl;

	//Test 2
	vector<int>::iterator itor;
	itor = vec.begin();
	vec.insert(itor+2, 6);

	for (itor = vec.begin(); itor != vec.end(); itor++)
		cout << *itor << " ";

	cout << endl;

	//Test 1

	itor = vec.begin() + 3; //+ plus offset

	vec.erase(itor);

	for (int x : vec)
		cout << x << " ";

	cout << endl;

	return 0;
}

