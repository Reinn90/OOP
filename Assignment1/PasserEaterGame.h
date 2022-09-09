#ifndef PASSEREATERGAME
#define PASSEREATERGAME

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "Board.h"
#include "Player.h"

class PasserEaterGame
{
    Board *board;
    Player *player[2];

public:
    PasserEaterGame(Board *b, Player *p1, Player *p2)
    {
        board = b;
        player[0] = p1;
        player[1] = p2;
    }

    ~PasserEaterGame()
    {
        delete player[0];
        delete player[1];
    }

    void play()
    {
        board->displayBoard();
        bool done = false;
        int playerInt = 1;

        while (!done)
        {
            // adjust for indexing
            int x = -1;
            int y = -1;

            if (playerInt == 1)
            {
                player[0]->getMove(board, x, y);
                board->addMove(playerInt, x, y);
                cout << "Passer makes a move (" << (x + 1) << "," << (y + 1) << ") "
                     << endl;
                done = checkWin(playerInt, board);
                playerInt = -1;
            }
            else
            {
                player[1]->getMove(board, x, y);
                board->addMove(playerInt, x, y);
                cout << "Eater makes a move (" << (x + 1) << "," << (y + 1) << ") "
                     << endl;
                done = checkWin(playerInt, board);
                playerInt = 1;
            }
            board->displayBoard();
        }
    }

    bool checkWin(int playerInt, Board *board)
    {
        int gStatus = board->gameStatus();

        if (gStatus == 1)
        {
            cout << "Passer wins!" << endl;
            return true;
        }
        else if (gStatus == -1)
        {
            cout << "Eater wins!" << endl;
            return true;
        }
        else
            return false;
    }
};

#endif