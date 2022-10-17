/*
 * destructors.cpp
 *
 *      Author: dongmo
 */


#include <iostream>
using namespace std;

//Test 1 & 2
class FooBase {
public:
    ~FooBase() { std::cout << "Destructor of FooBase" << std::endl; }
};

class Foo : public FooBase {
public:
    ~Foo() { std::cout << "Destructor of Foo" << std::endl; }
};

//Test 3
class BarBase {
public:
    virtual ~BarBase() { std::cout << "Destructor of BarBase" << std::endl; }
};

class Bar : public BarBase {
public:
    ~Bar() { std::cout << "Destructor of Bar" << std::endl; }
};

int main() {
    //Test 1
	cout<<"Test 1:" << endl;
	{ Foo fooObj;}

	cout<<"Test 2:" << endl;
    FooBase *foo = new Foo;
    delete foo; // deletes only FooBase-part of Foo-object;

	cout<<"Test 3:" << endl;
    BarBase * bar = new Bar;
    delete bar; // deletes complete object

    return 0;
}

