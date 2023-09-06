//Created by Dr Dongmo Zhang
#include<iostream>
#include<string>
using namespace std;

class Employee {
	string firstName, lastName;
	char middleInitial;
public:
	Employee(string fn, string ln, char mi);
};

Employee::Employee(string fn, string ln, char mi) {
	cout << "ctor::Employee" << endl;
	firstName = fn; 
	lastName = ln; 
	middleInitial = mi;
}

class Manager: public Employee {
	int level;
public:
	Manager(string fn, string ln, char mi):Employee(fn,ln,mi)
	{cout << "ctor::Manager" << endl;}

	void setLevel(int l) {level = l;}
};

int main() {
	Manager Peter("Peter", "Wang",' ');
	Peter.setLevel(2);
	return 0;
}
