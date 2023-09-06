#include<iostream>
using namespace std;

const double PI=3.14159;

class Circle {
	protected:
  		double radius;
	public:
  		Circle(double r = 1.0) : radius(r) {} 
  		double calVal();
};

double Circle::calVal(void)   // this calculate the area of the circle
{
  	return(PI * radius * radius);
}

// class declaration for the derived class
class Cylinder : public Circle {
	protected:
  		double length;     // add one additl data member and
	public:                   // two additional function members
  		Cylinder(double r=1.0,double l=1.0): Circle(r),length(l) {}
  		double calVal();  //calVal for cylinder class
};


// class implementation for Cylinder�
double Cylinder::calVal(void)
{
  	return (length * Circle::calVal());
}


int main() {
  Circle circle_1, circle_2(2);  // create two Circ obj
  Cylinder cylinder_1(3,4);      // create one Cyl obj
  cout << "The area of circle_1 is " << circle_1.calVal() << endl;
  cout << "The area of circle_2 is " << circle_2.calVal() << endl;
  cout << "The volume of cylinder_1 is " << cylinder_1.calVal()
          << endl;
 // circle_2 = cylinder_1;
  // assign a cyl to a Circle
  //cout << "\nThe area of circle_2 is now "  << circle_2.calVal() << endl;
  return 0;
}
