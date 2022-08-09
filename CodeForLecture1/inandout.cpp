#include <iostream>
#include <string>

using namespace std;

int main() {

   string name, id;
   short age;

   cout << "Input your name:\n";
   cin >> name;

   cout << "Input your student ID:\n";
   cin >> id;

   cout << "Input your age:\n" ;
   cin >> age;

   cout << "\nMy name is " << name <<". " << endl;
   cout << "My student ID is " << id <<"." << endl;
   cout << "I am " << age << " year old." <<endl;

   return 0;
}
