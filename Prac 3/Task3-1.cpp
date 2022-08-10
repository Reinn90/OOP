// Searches a partially filled array of nonnegative integers.
#include <iostream>

using namespace std;

const int DECLARED_SIZE = 10;

void fillArray(int a[], int size, int &numberUsed)
{
    cout << "Enter up to " << size << " nonnegative integers.\n"
         << "Mark the end of the list with a negative number.\n";

    int next, index = 0;
    cin >> next;
    while ((next >= 0) && (index < size))
    {
        a[index] = next;
        index++;
        cin >> next;
    }

    numberUsed = index;
}

int search(const int a[], int numberUsed, int target)
{
    int index = 0;
    bool found = false;
    while ((!found) && (index < numberUsed))
        if (target == a[index])
            found = true;
        else
            index++;

    if (found)
        return index;
    else
        return -1;
}

// function to find the smallest number and the position of the smallest number

int calculateMin(const int array[], int size, int &position)
{

    int smallest = array[0]; // initial value to be the smallest number
    int index;               // initialise index position

    // loop through the array and
    for (index = 1; index < size; index++)
    {

        // if the consequent values are smaller than the previous, change the 'smallest' value
        if (array[index] < smallest)
        {
            smallest = array[index];
            position = index; // record the index of the 'new' smallest number
        }
    }

    return smallest;
}

int main()
{
    int arr[DECLARED_SIZE], listSize, target, position;


    fillArray(arr, DECLARED_SIZE, listSize);

    int result;
    cout << "Enter a number to search for: ";
    cin >> target;

    result = search(arr, listSize, target);
    if (result == -1)
        cout << target << " is not on the list.\n";
    else
        cout << target << " is stored in array position " << result << endl
             << "(Remember: The first position is 0.)\n";

    
    
    // Function to locate the smallest value in the array
    int min = calculateMin(arr, DECLARED_SIZE, position);

    cout << "The smallest number in the array is " << min << ", and is stored in array position "
         << position << endl;
    cout << "End of program.\n";
    return 0;
}