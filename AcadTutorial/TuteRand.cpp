// OOP Tutorial Student callout randomiser
// Author: Kevin Reyes

#include <iostream>

using namespace std;

int main() {
    cout << "How many students are attending the tutorial? \n";
    int attendees;

    cin >> attendees;

    for (int i = 0; i < 70; i++) {
        cout << "#";
    }

    cout << "\n\tWelcome to Object Oriented Programming in C++ (Tutorial)\n";
    cout << "\t\t\tAll " << attendees << " of you.\n";

    for (int i = 0; i < 70; i++) {
        cout << "#";
    }
    return 0;
}
