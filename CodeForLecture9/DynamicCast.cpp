//: C15:DynamicCast.cpp
#include <iostream>
using namespace std;

class Pet {
public:
	virtual ~Pet() {
	}
};
class Dog: public Pet {
};
class Cat: public Pet {
};

int main() {
	Pet* d = new Dog; // Upcast
	// Try to cast it to Dog*:
	Dog* d1 = dynamic_cast<Dog*>(d);
	// Try to cast it to Cat*:
	// Cat* c = dynamic_cast<Cat*>(d);
 Cat* c = static_cast<Cat*>(d);

	if (d1 != 0)
		cout << "d1 = " << d1 << endl;
	else
		cout << "Unable to downcast d1!" << endl;

	if (c != 0)
		cout << "c = " << c << endl;
	else
		cout << "Unable to downcast d!" << endl;

	return 0;
}
