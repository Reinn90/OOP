//Created by Dr Dongmo Zhang
#include<iostream>
#include<string>
using namespace std;

class Employee {
	string firstName, lastName;
	char middleInitial;
public:
	Employee(string fn, string ln, char mi) 
		{firstName = fn; lastName = ln; middleInitial = mi;}
	void print() const ;
protected:
	string fullName() const 
		{ return firstName+' '+middleInitial+' '+lastName; }
};

void Employee::print() const {
	cout << "Empolyee " << fullName() << endl;
}

class Manager: public Employee {
	int level;
public:
	Manager(string fn, string ln, char mi):Employee(fn,ln,mi){}
	void setLevel(int l) {level = l;}
	void print() const ;
};


void Manager::print() const {
	cout << "Manager "<< fullName() << " at level " << level << endl ;// but cannot use lastName,                     
                                             //it is private
}

int main() {
	Employee staff1("John", "Smith", 'D');
	Manager staff2("Peter", "Wang",' ');
	staff2.setLevel(2);

	staff1.print();
	staff2.print();
    cout<<endl;
	
	//upcasting: one way
//	staff1 = staff2;
//	staff1.print(); // Object slicing

    //upcasting: a better way
//	Employee *ep;
//	ep = &staff2;
//	ep->print();

//    staff2 = staff1; //illegal
	
	Manager* pm;
	
	//downcasting: one way
    pm = static_cast<Manager*>(&staff1);
	
	//downcasting: another way (more C)
	pm = (Manager*) &staff1;
	
	pm->setLevel(3);
	pm->print();

	return 0;
}
