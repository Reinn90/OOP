//Created by Dongmo

#include <iostream>
using namespace std;

class objectCounter {
  int static counter;
public:
  objectCounter();// { counter++;} 
  int getCounter() {return counter;}
};

int objectCounter:: counter = 0;

objectCounter::objectCounter() {
  counter++;
}

int main() {
  objectCounter o1;
  cout << o1.getCounter() << endl;
  
  objectCounter o2;
  cout << o2.getCounter() << endl;

  objectCounter o3;
  cout << o3.getCounter() << endl;

  return 0;
} 
