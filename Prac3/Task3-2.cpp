#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

const int ROWS = 3;
const int COLS = 4;

void getUserInput(int &rowIndex, int &colIndex)
{
    int row, col;

    cout << "Using the matrix above, this program will print out what the values adjacent to user input contain." << endl;
    cout << "Enter the row as an integer between 1-3: ";
    cin >> row;
    cout << endl;

    while (row < 1 || row > 3)
    {
        cout << "That value is outside the range. Please enter a value between 1-3: ";
        cin >> row;
        cout << endl;
    }

    cout << "Enter the column as an integer between 1-4: ";
    cin >> col;
    cout << endl;

    while (col < 1 || col > 4)
    {
        cout << "That value is outside the range. Please enter a value between 1-4: ";
        cin >> col;
        cout << endl;
    }

    rowIndex = row - 1;
    colIndex = col - 1;

  
 
}

void findAdjacent(const int table[ROWS][COLS], int rowIndex, int colIndex)
{

    int up, down, right, up_right, down_right;

    if (rowIndex > 0)
    {
        // then there is an up
        // UP = row index - 1
        up = table[rowIndex - 1][colIndex];
        cout << "up: " << up << endl;
    }

    if (rowIndex < ROWS - 1)
    {
        // then there is a down
        // DOWN = row index + 1
        down = table[rowIndex + 1][colIndex];
        cout << "down: " << down << endl;
    }

    if (colIndex < COLS - 1)
    {
        // then there is a right
        // RIGHT = col index + 1
        right = table[rowIndex][colIndex + 1];
        cout << "right: " << right << endl;
    }

    if (rowIndex > 0 and colIndex < COLS - 1)
    {
        // then there is an up_right
        // UP_RIGHT = row index - 1, col index + 1
        up_right = table[rowIndex - 1][colIndex + 1];
        cout << "up right: " << up_right << endl;
    }

    if (rowIndex < ROWS - 1 and colIndex < COLS - 1)
    {
        // then there is a down_right
        // DOWN_RIGHT = row index + 1, col index + 1
        down_right = table[rowIndex + 1][colIndex + 1];
        cout << "down right: " << down_right << endl;
    }
}

int main()
{

    srand(time(0));

    int table[ROWS][COLS];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            table[i][j] = rand() % 3 - 1;
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            cout << setw(3) << table[i][j];

        cout << endl;
    }

    // my code
    int rowIndex, colIndex;
    getUserInput(rowIndex, colIndex);

    findAdjacent(table, rowIndex, colIndex);

    return 0;
}