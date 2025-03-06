#include<iostream>
#include<string>
using namespace std;

class Employee {
	string firstName, lastName;
public:
	Employee(string f, string l) {firstName = f; lastName = l;}
	void print() const {
	    cout<<"Empolyee "<<fullName()<<endl;
     }
	string fullName() const { return firstName +' '+ lastName; }
};

class Manager: public Employee {
	int level;
public:
	Manager(string f, string l):Employee(f,l){}
	void setLevel(int l) {level = l;}
	void print() const {
	    cout<<"Manager "<<fullName()<<" at level"<<level<<endl;
//		Employee::print();
//		cout<<" at level"<<level<<endl;
     }
};

int main() {
	Employee E1("John", "Smith");
	Manager M1("Peter", "Wang");
	M1.setLevel(2);
    E1.print();
    M1.print();

 //     E1 = M1;


//
//	Manager* pm;
//   pm = static_cast<Manager*>(&E1);
//	pm->setLevel(3);
//	pm->print();
	return 0;
}
