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
    // Take in user input to dynamically set the boardsize
    cout << "Welcome to Passer vs Eater game.\n"
         << endl;
    cout << "What board game size do you want to play with? (Hint: Enter an integer between 3-15)" << endl;

    int boardSize;
    cin >> boardSize;

    if (boardSize < 3 || boardSize > 15){
        cout << "That value is invalid. Defaulting to a 5x5 board."<< endl << endl;
        boardSize = 5;
    }

    // debugger
    cout << boardSize << endl;

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