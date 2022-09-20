/*
 * Kevin Reyes - 20658133
 */

#ifndef NOVICEPLAYER
#define NOVICEPLAYER

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "Player.h"
#include "Board.h"

class NovicePlayer : public Player
{
public:
    NovicePlayer(int p, string n) : Player(p, n){};
    ~NovicePlayer(){};

    void getMove(Board *board, int &x, int &y)
    {
       
        x = -1; // adjust for indexing
        y = 0;
     
        do
        {
            x++;

            if (x >= board->getDim()) // gets to the bottom
            {
                x = -1; // reset the row counter
                
                y++; // go right
                
            }

        } while (!board->isValidInput(player, x, y));

        return;
    }
};

#endif