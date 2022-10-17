#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

class OneDArray
{
private:
    const static int DECLARED_SIZE = 10;
    int arr[DECLARED_SIZE];
    int numberUsed;

public:
    void fillArray();
    void search();
    void calculateMin();
};

void OneDArray::fillArray()
{

    cout << "Enter up to " << DECLARED_SIZE << " nonnegative integers.\n"
         << "Mark the end of the list with a negative number.\n";

    int next, index = 0;

    cin >> next;
    while ((next >= 0) && (index < DECLARED_SIZE-1))
    {
        arr[index] = next;
        index++;
        cin >> next;
    }

    numberUsed = index + 1;
    cout << numberUsed; // delete
}

void OneDArray::search()
{

    int result, target;
    cout << "Enter a number to search for: ";
    cin >> target;

    int index = 0;
    bool found = false;
    while ((!found) && (index < numberUsed))
        if (target == arr[index])
            found = true;
        else
            index++;

    if (found)
        cout << target << " is stored in array position " << index << endl
             << "(Remember: The first position is 0.)\n";
    else
        cout << target << " is not on the list.\n";
}

void OneDArray::calculateMin()
{

    int smallest = arr[0]; // initial value to be the smallest number
    int smallestIndex = 0;     // initialise index position

    // loop through the array and
    for (int index = 0; index < numberUsed; index++)
    {

        // if the consequent values are smaller than the previous, change the 'smallest' value
        if (arr[index] < smallest)
        {
            smallest = arr[index];
            smallestIndex = index; // record the index of the 'new' smallest number
        }
    }

    cout << "The smallest number in the array is " << smallest << ", and is stored in array position "
         << smallestIndex << endl;
}