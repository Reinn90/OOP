#include<iostream>
using namespace std;

int main() {
int *ptr = new int(10);

//*ptr = 20;

cout << *ptr << endl;

delete ptr;
return 0;
}