/*
 * SmartPlayer.h
 *
 *  Created on: 24 Jul. 2020
 *      Author: dongmo
 *
 * Repurposed for this Assignment by
 * Kevin Reyes - 20658133
 */

#ifndef SMARTPLAYER
#define SMARTPLAYER

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

#include "Player.h"
#include "Board.h"

class SmartPlayer : public Player
{
public:
    SmartPlayer(int p, string n) : Player(p, n){};
    ~SmartPlayer(){};

    void getMove(Board *board, int &x, int &y)
    {
        vector<int> emptyCells = board->getEmptyPositions();
        if (emptyCells.empty())
            return;

        for (int index : emptyCells)
        {
            int i = index / board->getDim(); // passer
            int j = index % board->getDim();

            int m = index / board->getDim(); // eater
            int n = index % board->getDim();

            // Board* tempBoard = new Board(board);
            Board tempBoard(board->getDim(), "passer", "eater");
            x = i;
            y = j;

            int x2 = m;
            int y2 = n;

            tempBoard.addMove(x, y, x2, y2);
            if (tempBoard.gameStatus() == player)
            {
                return;
            }

            if (tempBoard.threatenLevel(player) == 2)
                continue;
        }

        return;
    }
};

#endif /* SMARTPLAYER*/
