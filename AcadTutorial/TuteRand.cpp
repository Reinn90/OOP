// OOP Tutorial Student callout randomiser
// Author: Kevin Reyes

#include <cstdlib>
#include <iostream>

using namespace std;

int getStudentAttendance() {

    cout << "How many students are attending the tutorial? \n";
    int attendees;

    cin >> attendees;
    while (attendees < 0) {

        cout << "You're an eedjot, no such thing as negative student "
                "attendance. Try again.\n";
        cin >> attendees;
    }

    return attendees;
}

void printWelcomeBanner(int n) {

    for (int i = 0; i < 70; i++) {
        cout << "#";
    }

    cout << "\n\tWelcome to Object Oriented Programming in C++ (Tutorial)\n";
    cout << "\t\tAll " << n << " of you. Let's have some fun coding.\n";
    cout << "\n\t\t   *No Vibe-Coding allowed here*\n";

    for (int i = 0; i < 70; i++) {
        cout << "#";
    }
}

void randomiseCall(int stnum) {

    if (stnum != 0) {
        int n = rand() % stnum + 1;

        cout << endl;
        cout << "\nIt's student " << n << "'s turn.";
    } else {
        cout << "\n\nForever alone.";
    }
}

int main() {
    srand(time(0));

    int stnum = getStudentAttendance();

    printWelcomeBanner(stnum);
    randomiseCall(stnum);

    return 0;
}
