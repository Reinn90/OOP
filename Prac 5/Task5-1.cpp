#include <iostream>
using namespace std;

int main( )
{
    int row, col;
    cout << "Enter the row and column dimensions of the array:\n";
    cin >> row >> col;

    int **grid = new int*[row];

    for (int i = 0; i < row; i++)
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

    for (int i = 0; i < row; i++)
        delete[] grid[i];

    delete[] grid;

    return 0;
}
