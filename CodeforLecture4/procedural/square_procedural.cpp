#include<iostream>
using namespace std;

int main(){

	cout << "what is the size of the square (in centimeter)?" << endl;
    double size;
    cin >> size;

    double area;
    
	area = size*size;

	cout << "The area of the square is " << area << " square centimeters" << endl; 

    cout << "what are the length and width of the rectangle (in centimeter)?" << endl;

	double length, width;
	cin >> length >> width;

	area = length * width;

    cout << "The area of the rectangle is " << area << " square centimeters" << endl; 

    cout << "what are the length, width and depth of the cuboid (in centimeter)?" << endl;

	double depth;
	cin >> length >> width >> depth;

	area = length * width * depth;

    cout << "The area of the cuboid is " << area << " square centimeters" << endl; 

}