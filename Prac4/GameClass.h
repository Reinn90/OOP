#ifndef GAME
#define GAME

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "TicTacToeClass.h"

class Game
{

private:
    TicTacToe board;

public:
    void play();
    void getMove(int player, int &r, int &c);

    void getXMove(int player, int &r, int &c);
    void getOMove(int player, int &r, int &c);
};

void Game::play()
{

    int done = 0; // begin the game

    while (done == 0) // while the game is not finished yet
    {

        // if player == 1, random computer plays

        board.playerSymbol = (board.player == 1) ? 'X' : 'O'; // initialise the players, since player is 1, X starts

        // if it's the human player's turn

        int r, c; // player coordinates

        getMove(board.player, r, c);

        board.addMove(board.player, r, c); // display the player move

        board.noOfMoves++; // number of moves get's closer to the end of the game

        board.displayBoard(); // update the board

        done = board.gameStatus(); // determines the winner of if it's a draw

        if (done == 1)
        {
            cout << "Player X wins!" << endl;
        }
        else if (done == -1)
        {
            cout << "Player O wins!" << endl;
        }
        else if (done == 2)
        {
            cout << "Draw game!" << endl;
        }

        // swap players after a move is complete

        if (board.player == 1) // if Player X is finished, swap to Player O
            board.player = -1;
        else // else if player O is finished, swap to player X
            board.player = 1;
    }
}

void Game::getMove(int player, int &r, int &c)
{

    if (player == 1) // random computer
    {
        getXMove(player, r, c);
    }
    else
    {
        // human player
        getOMove(player, r, c);
    }
}


// Randomised computer player
void Game::getXMove(int player, int &r, int &c)
{

    int row, col; // initialise input

    // check to see if the input coordinates are valid, i.e. is the cell already occupied or if the inputs are out of bounds
    do
    {
        // randomizsed computer input
        srand(time(0));

        // take in random integers from 0-2 which are the array index
        row = rand() % 3;
        col = rand() % 3;

        if (board.isValidMove(player, row, col))
        {
            cout << "Player " << board.playerSymbol << " made a move on " << row + 1 << " " << col + 1 << endl;
        }

        // check if the move
    } while (!board.isValidMove(player, row, col));

    r = row;
    c = col;
}

// Human player
void Game::getOMove(int player, int &r, int &c)
{
    cout << "Player " << board.playerSymbol << " enter move: "; // display instructions

    int row, col; // player input

    // check to see if the input coordinates are valid, i.e. is the cell already occupied or if the inputs are out of bounds
    do
    {
        cin >> row >> col; // take in row and column inputs from user
        cout << endl;

        // convert user input into array indexes and then check
        // if isValidMove FALSE, !IsValidMove returns TRUE and the while loop of asking for user input continues
    } while (!board.isValidMove(player, row - 1, col - 1));

    // add your code here to update x, y
    // input - 1 for array index and returns its reference
    r = row - 1;
    c = col - 1;
}
#endif
