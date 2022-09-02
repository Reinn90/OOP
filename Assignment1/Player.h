#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <iomanip>
#include <string>

#include "Board.h"

using namespace std;

class Player
{

private:
    Board board;

public:
    void getMove(int &player, int &r, int &c);
};

void Player::getMove(int &player, int &r, int &c)
{

    int row, col; // player input

    string playerTitle = (player == 1) ? "Passer" : "Eater";

    cout << playerTitle << "'s move." << endl;
    do
    {
        // take in row and column inputs from user
        cout << "Row: ";
        cin >> row;
        cout << endl;
        cout << "Column: ";
        cin >> col;
        cout << endl;

    } while (!board.isValidInput(player, row - 1, col - 1));

    // add your code here to update x, y
    // input - 1 for array index and returns its reference
    r = row - 1;
    c = col - 1;

    // swap players after a move is complete

    if (player == 1) // if Player X is finished, swap to Player O
        player = -1;
    else // else if player O is finished, swap to player X
        player = 1;
}

#endif