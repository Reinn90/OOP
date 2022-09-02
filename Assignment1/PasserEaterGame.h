#ifndef PASSEREATERGAME
#define PASSEREATERGAME

#include <iostream>
#include <iomanip>
#include <string>

#include "Board.h"
#include "Player.h"

using namespace std;

class PasserEaterGame
{

private:
    Board board;
    Player player;

public:
    void play();
};

void PasserEaterGame::play()
{

    int done = 0;

    while (done == 0)
    {
        int r1, c1, r2, c2;

        board.displayBoard();
        player.getMove(board.player, r1, c1); // passer
        board.addMove(board.player, r1, c1);

        player.getMove(board.player, r2, c2); // Eater
        board.addMove(board.player, r2, c2);
    }
}

#endif