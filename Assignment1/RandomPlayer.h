/*
 * HumanPlayer.h
 *
 *  Created on: 22 Mar. 2019
 *      Author: dongmo
 *
 * Repurposed for this assignment by
 * Kevin Reyes - 20658133
 */

#ifndef RANDOMPLAYER
#define RANDOMPLAYER

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

#include "Player.h"
#include "Board.h"

class RandomPlayer : public Player
{
public:
    RandomPlayer(int p, string n) : Player(p, n){};
    ~RandomPlayer(){};

    void getMove(Board *board, int &x, int &y)
    {
        vector<int> emptyCells;

        do
        {
            for (int i = 0; i < board->getDim(); i++)
            {
                for (int j = 0; j < board->getDim(); j++)
                {
                    if (board->getGrid(i, j) == 0 || board->getGrid(i, j) == 1) // Consider the Passer's occupied Cell
                        emptyCells.push_back(i * board->getDim() + j);
                }
            }
            int index = rand() % emptyCells.size();
            x = emptyCells[index] / board->getDim();
            y = emptyCells[index] % board->getDim();

        } while (!board->isValidInput(player, x, y)); // Dont eat move already on the board

        return;
    }
};

#endif