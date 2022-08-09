#include<iostream>

using namespace std;

int main() {
     int num;
     
     cout << "Input an integer";
     cin >> num;
     if (num > 0)
         {
           cout << "Your input is a positive number.";
           cout << "which is " << num;
         }
     else
         {
           cout << "Your input is a non-positive number.";
           cout << "which is " << num;
         }
     return 0;
}
