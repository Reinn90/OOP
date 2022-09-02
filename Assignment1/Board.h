#ifndef BOARD
#define BOARD

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Board
{

private:
    const static int boardSize = 5;
    int board[boardSize][boardSize]; // static board - CHANGE LATER TO DYNAMIC

public:
    int noOfMoves; // number of moves
    int player;
    char playerSymbol;
    int r, c;
    // Constructor
    Board()
    {

        // fill the array with zeroes to specify that a cell is empty
        for (int row = 0; row < boardSize; row++)
            for (int col = 0; col < boardSize; col++)
                board[row][col] = 0;

        noOfMoves = 0;

        player = 1; // Passer starts
    }

    bool isValidInput(int player, int r, int c);
    void addMove(int player, int r, int c);
    void displayBoard();

    
};


void Board::displayBoard()
{
    // column index display
    cout << " ";
    for (int i = 0; i < boardSize; i++)
        cout << setw(4) << i + 1;
    cout << endl;

    // top divider
    cout << setw(3);
    for (int i = 0; i < boardSize * 4; i++)
        cout << "-";
    cout << "-" << endl;

    // grid board display
    for (int i = 0; i < boardSize; i++)
    {
        // row indexes
        cout << i + 1;
        if (i < 9)
            cout << " |";
        else
            cout << "|"; // re-allign vertical grid for board > 10 boardSizeension

        for (int j = 0; j < boardSize; j++)
        {
            playerSymbol = ' ';

            if (board[i][j] == 1) // Passer has occupied the cell
                playerSymbol = 'P';

            else if (board[i][j] == -1) // Eater has occupied the cell
                playerSymbol = 'E';

            cout << setw(2) << playerSymbol << setw(2);

            if (j != boardSize) // display the two middle vertical dividers
                cout << "|";
        }

        if (i != boardSize - 1)
            cout << endl
                 << endl;
    }

    // bottom divider
    cout << endl
         << setw(3);
    for (int i = 0; i < boardSize * 4; i++)
        cout << "-";
    cout << "-" << endl;
}

bool Board::isValidInput(int player, int r, int c)
{

    // board[r][c] == 0 : if the coordinate on the board is empty
    // (r >= 0 && c >= 0) && (r < row_max && c < col_max): checking the pair to check if within boundary
    if (board[r][c] == 0 && (r >= 0 && c >= 0) && (r < boardSize && c < boardSize))
        return true;
    else
        cout << "Those coordinates are out of bounds or cell already occupied. Please enter an integer between "
             << "1-" << boardSize << " to play." << endl;
    cout << "Please enter move coordinates: ";
    return false;
}

void Board::addMove(int player, int r, int c)
{
    board[r][c] = player * -1; // add 1 or -1 to the matrix that will determine what is displayed
}

#endif