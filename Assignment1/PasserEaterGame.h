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

        int done = 0;
        int playerInt = 1;

        while (done == 0)
        {
            int x1, y1, x2, y2;

            // Passer's move
            player[0]->getMove(board, x1, y1);
            playerInt = -1;

            // Eater's move
            player[1]->getMove(board, x2, y2);
            playerInt = 1;

            cout << player[0]->getName() << " makes a move (" << (x1 + 1) << "," << (y1 + 1) << ") "
                 << endl;
            cout << player[1]->getName() << " makes a move (" << (x2 + 1) << "," << (y2 + 1) << ") "
                 << endl;

            // Add both moves to the board
            board->addMove(x1, y1, x2, y2);

            // update the board display
            board->displayBoard();

            // check the game status
            done = board->gameStatus();

            if (done == 1)
                cout << player[0]->getName() << " wins!" << endl;
            else if (done == -1)
                cout << "No winning line. " << player[1]->getName() << " wins!\n"
                     << endl;
        }

        cout << "-----GAME OVER-----" << endl;
    }
};

#endif