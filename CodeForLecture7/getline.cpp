#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	
	cout << "Input your student id" << endl;
	cin >> n;
	//improvement
	string line;
	cout << "Input your name" << endl;
	getline(cin, line, '?'); // ? signifies the end of the input
	cout << line << endl;

	return 0;
}
