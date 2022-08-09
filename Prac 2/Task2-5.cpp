#include <iostream>

using namespace std;

// function to swap numbers
void swapNum(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// function to sort 3 input integers from lowest to highest
void sort(int &first, int &second, int &third)
{
    while (first > second || second > third) // while the order is not yet sorted
    {
        // swap the first and third if first is larger than the third
        if (first > third)
        {
            swapNum(first, third);
        }

        // swap the second and third if second is larger than the third
        if (second > third)
        {
            swapNum(second, third);
        }

        // swap the first and second if first is larger than the second
        if (first > second)
        {
            swapNum(first, second);
        }
    }
}

int main()
{

    int first, second, third;

    cout << "Enter 3 numbers:" << endl;
    cin >> first >> second >> third;

    sort(first, second, third);

    cout << "First: " << first << ", Second: " << second << ", Third: " << third << endl;

    return 0;
}