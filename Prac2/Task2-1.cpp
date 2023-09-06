#include <iostream>
#include <cmath>
using namespace std;

// Part C - print even numbers between 2 interger inputs
void evenNumbers(int firstNum, int secondNum)
{
    for (int i = firstNum + 1; i < secondNum; i++)
    {
        if ((i % 2) == 0)
            cout << i << "\n";
    }
}

// Part D - print average of the two numbers
float averageNum(int firstNum, int secondNum)
{
    float average = (firstNum + secondNum) / (double)2;
    return average;
}

int main()
{

    int firstNum, secondNum;

    // Take in user input
    cout << "Please enter your first number: \n";
    cin >> firstNum;
    cout << "Please enter your second number: \n";
    cin >> secondNum;

    // Check to see if firstNum is smaller than secondNum. if not, retry user input for firstNum
    while (firstNum >= secondNum)
    {
        cout << "Please enter your first number again. (Make sure it is smaller than your second number): \n";
        cin >> firstNum;
    }

    cout << "The even numbers between your inputs are: \n";

    // print even numbers between the inputs

    evenNumbers(firstNum, secondNum);

    // calculate the average
    
    cout << "The average of your two inputs is: " << averageNum(firstNum, secondNum) << endl;

    system("pause");
    return 0;
}