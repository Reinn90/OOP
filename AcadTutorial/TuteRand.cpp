// OOP Tutorial Student callout randomiser
// Author: Kevin Reyes

#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    srand(time(0));

    cout << "How many students are attending the tutorial? \n";
    int attendees;

    cin >> attendees;

    for (int i = 0; i < 70; i++) {
        cout << "#";
    }

    cout << "\n\tWelcome to Object Oriented Programming in C++ (Tutorial)\n";
    cout << "\t\tAll " << attendees << " of you. Let's have some fun coding.\n";
    cout << "\n\t\t   *No Vibe-Coding allowed here*\n";

    for (int i = 0; i < 70; i++) {
        cout << "#";
    }

    int num;
    num = rand() % attendees + 1;

    cout << endl;
    cout << "\nIt's student " << num << "'s turn.";
    return 0;
}
