/*
 * Nowell Kevin Reyes - 20658133
 */
#ifndef BOARD
#define BOARD

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

class Board
{
    int dim;       // dimension of the board grid
    int noOfMoves; // number of moves
    int maxMove;   // when board is full
    int **board;   // dynamic board pointer
    int **grid;

    string passerName;
    string eaterName;

public:
    Board(); // default constructor
    // Constructor
    Board(int size, string P, string E)
    {

        dim = size;
        passerName = P;
        eaterName = E;
        maxMove = dim * dim;

        // initiate pointer of pointer variable of user input size
        board = new int *[dim];

        // create dynamic 2D array
        for (int i = 0; i < dim; i++)
            board[i] = new int[dim];

        // fill the array with zeroes to specify that a cell is empty
        for (int row = 0; row < dim; row++)
            for (int col = 0; col < dim; col++)
                board[row][col] = 0;

        noOfMoves = 0;
    }

    // Destructor
    ~Board()
    {
        for (int i = 0; i < dim; i++)
            delete[] board[i];

        delete[] board;
    }

    // Copy Constructor - taken from Lecture slides
    Board(const Board &cboard)
    {
        dim = cboard.dim;

        grid = new int *[dim];

        for (int i = 0; i < dim; i++)
            grid[i] = new int[dim];

        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
                grid[i][j] = cboard.grid[i][j];
        }

        noOfMoves = cboard.noOfMoves;
    }

    int getGrid(int i, int j) { return board[i][j]; }; // taken from PASS practical code

    int getDim() { return dim; }

    bool isFull() { return noOfMoves >= dim * dim; }; // maximum No of moves is the dimesion squared

    void displayBoard() const;

    bool isValidInput(int playerInt, int x, int y) const;

    void addMove(int x1, int y1, int x2, int y2);

    int gameStatus();

    bool checkWin(int x, int y);

    int threatenLevel(int playerInt);

    vector<int> getEmptyPositions();

    
};

bool Board::checkWin(int x, int y)
{
    if (x >= 0 && x < dim && y >= 0 && y < dim && board[x][y] == 1)
    {

        if (x >= dim - 1 && board[x][y] == 1) //if it gets to the bottom row
            return true;

        if (checkWin(x + 1, y - 1))
            return true; // bottom left
        if (checkWin(x + 1, y + 1))
            return true; // bottom right
        if (checkWin(x + 1, y))
            return true; // bottom
    }
    return false;
}

int Board::gameStatus()
{
    // Passer win condition - recursion technique
    for (int col = 0; col < dim; col++)
    {
        if (checkWin(0, col) == true) return 1;    //checks every column of the top row
    }

    // Eater win condition - when board is full
    if (noOfMoves >= maxMove)  return -1;
    

    return 0; // continue the game
}

void Board::displayBoard() const
{
    // column index display
    cout << " ";
    for (int i = 0; i < dim; i++)
        cout << setw(4) << i + 1;
    cout << endl;

    // top divider
    cout << setw(3);
    for (int i = 0; i < dim * 4; i++)
        cout << "-";
    cout << "-" << endl;

    // grid board display
    for (int i = 0; i < dim; i++)
    {
        // row indexes
        cout << i + 1;
        if (i < 9)
            cout << " |";
        else
            cout << "|"; // re-allign vertical grid for board > 10 boardSize

        for (int j = 0; j < dim; j++)
        {
            char playerSymbol = ' ';

            if (board[i][j] == 1) // Passer has occupied the cell
                playerSymbol = 'P';

            else if (board[i][j] == -1) // Eater has occupied the cell
                playerSymbol = 'E';

            // cout << setw(2) << playerSymbol << setw(2);
            cout << setw(2) << playerSymbol << setw(2);

            if (j != dim) // display the two middle vertical dividers
                cout << "|";
        }

        if (i != dim - 1)
            cout << endl
                 << endl;
    }

    // bottom divider
    cout << endl
         << setw(3);
    for (int i = 0; i < dim * 4; i++)
        cout << "-";
    cout << "-" << endl;
}

bool Board::isValidInput(int playerInt, int row, int col) const
{

    if (0 <= row && row <= (dim - 1) && 0 <= col && col <= (dim - 1) && board[row][col] == 0)
        return true;
    else
    {
        if ((passerName == "Passer(Human)" && eaterName == "Eater(Human)") )
        {
            string playerString;
            playerString = (playerInt == 1) ? "Passer" : "Eater";
            cout << "Those coordinates are out of bounds or cell already occupied. Please enter an integer between "
                 << "1-" << dim << " to play.\n"
                 << endl;
            cout << "Please enter " << playerString << " move coordinates: ";
            return false;
        }
        else
            return false;
    }
}

void Board::addMove(int x1, int y1, int x2, int y2)
{
    board[x1][y1] = 1; // passer move

    // if eater move is the same, overwrite it and only 1 move is counted
    if (x2 == x1 && y2 == y1)
    {
        board[x1][y1] = -1;
        noOfMoves--;
    }
    else
        board[x2][y2] = -1;

    noOfMoves++;
    noOfMoves++; // count two moves
}

/*
 * Methods below this line are repurposed
 * from PASS practical code + lecture slides
 * Created on: 24 Jul 2020
 * Author: dongmo
 */

vector<int> Board::getEmptyPositions()
{
    vector<int> emptyCells;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (board[i][j] == 0)
                emptyCells.push_back(i * dim + j);
        }
    }
    random_shuffle(emptyCells.begin(), emptyCells.end());

    return emptyCells;
}

int Board::threatenLevel(int playerInt)
{
    int max = 0;
    int opponent = (playerInt == 1) ? -1 : 1;
    for (int row = 0; row < dim; row++)
    {
        int counter = 0;
        for (int col = 0; col < dim; col++)
        {
            if (board[row][col] == playerInt)
            {
                counter = 0;
                break;
            }
            else if (board[row][col] == opponent)
                counter++;
        }
        if (counter > max)
            max = counter;
    }

    for (int col = 0; col < dim; col++)
    {
        int counter = 0;
        for (int row = 0; row < dim; row++)
        {
            if (board[row][col] == playerInt)
            {
                counter = 0;
                break;
            }
            else if (board[row][col] == opponent)
                counter++;
        }
        if (counter > max)
            max = counter;
    }

    int counter = 0;
    for (int k = 0; k < dim; k++)
    {
        if (board[k][k] == playerInt)
        {
            counter = 0;
            break;
        }
        else if (board[k][k] == opponent)
            counter++;
    }
    if (counter > max)
        max = counter;

    counter = 0;
    for (int k = 0; k < dim; k++)
    {
        if (board[k][2 - k] == playerInt)
        {
            counter = 0;
            break;
        }
        else if (board[k][2 - k] == opponent)
            counter++;
    }
    if (counter > max)
        max = counter;

    return max;
}

#endif