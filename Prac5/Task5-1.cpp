#include <iostream>
using namespace std;

int main( )
{
    int row, col;
    cout << "Enter the row and column dimensions of the array:\n";
    cin >> row >> col;

    int **grid = new int*[row]; // initialise a pointer of pointers named grid, containing a pointer of dynamic, array size 'row'

    for (int i = 0; i < row; i++) // loop to initialise each row to contain a new array size 'col' to create a 2d matrix
        grid[i] = new int[col];

    cout << "Enter " << row << " rows of "
         << col << " integers each:\n";

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> grid[i][j];

    cout << "Echoing the 2 dimensional array:\n";
    for (int i = 0; i < row; i++)   {
        for (int j = 0; j < col; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < row; i++) // creating dynamic memory required freeing up said memory be deleting the array
        delete[] grid[i];

    delete[] grid;

    return 0;
}
