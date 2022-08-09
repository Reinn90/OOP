#include <iostream>
using namespace std;


int main() {

     int num, total, counter;
     total = 0;

     for (counter =1;counter <= 10; counter++) 
     {
         cout << "Please input a number: \n";
         cin >> num;
         total = total + num;
     }
     
     cout << total;

     return 0;
}

