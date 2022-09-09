/*
 * HumanPlayer.h
 *
 *  Created on: 22 Mar. 2019
 *      Author: dongmo
 *
 * Repurposed for this assignment by
 * Kevin Reyes - 20658133
 */

#ifndef HUMANPLAYER
#define HUMANPLAYER

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "Player.h"
#include "Board.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer(int p) : Player(p){};
    ~HumanPlayer(){};

    void getMove(Board *board, int &x, int &y)
    {
        if (player == 1)
            cout << "Passer's move." << endl;
        else
            cout << "Eater's move." << endl;

        do
        {
            // take in row and column inputs from user
            cout << "Row: ";
            cin >> x;
            cout << endl;
            cout << "Column: ";
            cin >> y;
            cout << endl;

            x = x - 1;
            y = y - 1;

        } while (!board->isValidInput(x, y));

        return;
    }
};

#endif