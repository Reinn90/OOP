#include <cmath>
#include <iostream>


int main() {
  const double Pi = 3.14159;
  double radius, volume;

  std::cout << "Please enter the radius of a sphere:";
  std::cin >> radius;

  volume = 4.0 / 3.0 * Pi * pow(radius, 3.0);
  std::cout << "The volume of the sphere is: \n" << volume << "\n";

  system("pause");
  return 0;
}
