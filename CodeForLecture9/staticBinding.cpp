#include <iostream>
#include <cmath>

using namespace std;

class One
{
public:
	// take in any integer and double it
	float f1(float num) { return num * 2; }
};

// inheriting from class one
class Two : public One
{
public:
	// triple input
	// same function name, diff implementation - polmorphism
	float f1(float num) { return num * 3; }
};

int main()
{
	One one;
	Two two;
	cout << one.f1(10) << endl;
	cout << two.f1(10) << endl;
}
