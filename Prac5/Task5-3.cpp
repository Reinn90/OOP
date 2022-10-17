#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;      // Name of the student
    int numUnits;     // records how many units the student is currently erolled in
    string *unitList; // pointer to dynamic allocated arrat to store the names of the units that the student is enrolled in

public:
    Student(string, int); // constructor
    void getInput();
    void displayInfo();
    ~Student(); // destructor
};

Student::Student(string studentName, int num)
{

    name = studentName;
    numUnits = num;

    // create an array of strings using dynamic memory allocation
    unitList = new string[num];
}

void Student::getInput()
{
    cout << "Enter " << numUnits << " unit names." << endl;
    for (int i = 0; i < numUnits; i++)
        cin >> unitList[i];

    cout << endl;
}

void Student::displayInfo(){

    cout << name << " is enrolled in the following units: " << endl;
    
    for (int i = 0; i < numUnits; i++)
        cout << unitList[i] << endl;
}

Student::~Student(){

    delete[] unitList;
}

int main()
{
    string name;
    int num;
    
    cout << "what's your name? \n";
    cin >> name;
    cout << "Enter how many units the student is enrolled in? " << endl;
    cin >> num;

    Student s(name,num);
    s.getInput();
    s.displayInfo();
    return 0;
}