// Created by Dongmo
#include <iostream>
using namespace std;

class Counted
{
    static int count;
    // int count;
public:
    Counted()
    {
        // count = 0;
        cout << "No " << ++count << " object is created \n";
    }
};

int Counted::count = 0; // initialization of static variable

int main()
{
    Counted c1, c2, c3, c4, c5;

    return 0;
}
