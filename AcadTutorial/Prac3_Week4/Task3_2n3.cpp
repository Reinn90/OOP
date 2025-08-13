// Functional implementation for basic Tic Tac Toe game (incomplete)

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void displayBoard(int board[][3]) {
    cout << "   1    2    3" << endl << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1;
        for (int j = 0; j < 3; j++) {
            char playerSymbol = ' ';
            if (board[i][j] == 1)
                playerSymbol = 'X';
            else if (board[i][j] == -1)
                playerSymbol = 'O';
            cout << setw(3) << playerSymbol;
            if (j != 2)
                cout << " |";
        }
        cout << endl;
        if (i != 2)
            cout << " ____|____|____" << endl << "     |    |    " << endl;
    }
    cout << endl;
}

bool isValidMove(int board[][3], int x, int y) {
    if (0 <= x && x <= 2 && 0 <= y && y <= 2 &&
        board[x][y] == 0) // Add your code here)
        return true;
    else {

        cout << "Those coordinates are invalid. Please input new row and "
                "column values. ";
        return false;
    }
}

bool getXOMove(int board[][3], int noOfMoves, int &x, int &y) {

    if (noOfMoves >= 9)
        return false;

    int row, col;
    do {
        cin >> row >> col;
        cout << endl;
    } while (!isValidMove(board, row - 1, col - 1));
    x = row - 1;
    y = col - 1;

    return true;
}

void addMove(int board[][3], int x, int y, int player) { board[x][y] = player; }

int gameStatus(int board[][3], int &noOfMoves) {
    // Write your code here to check if the game has been in a win status or a
    // draw status Check rows for a win

    // Add your code here

    for (int row = 0; row < 3; row++) {
        if (board[row][0] != 0 && (board[row][0] == board[row][1]) &&
            (board[row][1] == board[row][2]))
            return board[row][0];
    }

    // Check columns for a win

    // Add your code here
    for (int col = 0; col < 3; col++) {
        if (board[0][col] != 0 && (board[0][col] == board[1][col]) &&
            (board[1][col] == board[2][col]))
            return board[0][col];
    }

    // Check diagonals for a win

    // Add your code here
    // Top left to bottom right
    if (board[0][0] != 0 && (board[0][0] == board[1][1]) &&
        (board[1][1] == board[2][2])) {
        return board[0][0];
    }

    // Botom left to Top right
    if (board[2][0] != 0 && (board[2][0] == board[1][1]) &&
        (board[1][1] == board[0][2])) {
        return board[0][0];
    }

    if (noOfMoves >= 9)
        return 2;

    return 0;
}

int main() {
    int board[3][3];
    int noOfMoves;

    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = 0;

    noOfMoves = 0;

    int player = 1;

    displayBoard(board);
    int done = 0;
    while (done == 0) {
        char playerSymbol = (player == 1) ? 'X' : 'O';
        cout << "Player " << playerSymbol << " enter move: ";
        int x, y;

        getXOMove(board, noOfMoves, x, y);

        addMove(board, x, y, player);
        noOfMoves++;
        displayBoard(board);

        done = gameStatus(board, noOfMoves);
        if (done == 1) {
            cout << "Player X wins!" << endl;
            return 0;
        } else if (done == -1) {
            cout << "Player O wins!" << endl;
            return 0;
        } else if (done == 2) {
            cout << "Draw game!" << endl;
            return 0;
        }

        if (player == 1)
            player = -1;
        else
            player = 1;
    }

    return 0;
}
