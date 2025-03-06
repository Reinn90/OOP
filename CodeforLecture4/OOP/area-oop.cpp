#include <iostream>
#include "geometry.h"
using namespace std;

int main() {
   Geometry aSquare;
   cout << " Whath is the size of the square?" << endl;
   double size;
   cin >> size;
   cout << " The area of the square is " << aSquare.area(size) << endl;

   Geometry aRectangle;
   cout << " Whath are the length and width of the rectangle?" << endl;
   double length, width;
   cin >> length >> width;

   cout << " The area of the rectangle is " << aRectangle.area(length, width) << endl;

   Geometry aCuboid;

   cout << " Whath are the length, width and depth of the cuboid?" << endl;
   double depth;
   cin >> length >> width >> depth;

   cout << " The volume of the cuboid is " << aCuboid.volume(length, width, depth) << endl;

}
