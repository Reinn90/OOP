#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int firstNum, secondNum;
    float average;

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

    for (int i = firstNum + 1; i < secondNum; i++)
    {
        if ((i % 2) == 0)
            cout << i << "\n";
    }

    // calculate the average


    average = (firstNum + secondNum) / (double)2;
    cout << "The average of your two inputs is: " << average << endl;

    system("pause");
    return 0;
}