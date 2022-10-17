#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Student {
    private:
    
    int studentId, courseNo;
    string studentName;
    char enrolmentStatus;

    public:

    Student() {
        studentId = 20658133;
        courseNo = 3769;
        studentName = "Kevin Reyes";
        enrolmentStatus = 'Y';

    }
    void display();

};

void Student::display(){
    cout << studentId << endl
        << studentName << endl
        << courseNo << endl
        << "Enrolled: " << enrolmentStatus << endl;
}

#endif 