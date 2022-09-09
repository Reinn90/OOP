#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

#include "PasserEaterGame.h"
#include "HumanPlayer.h"

int main()
{

    // Take in user input to dynamically set the boardsize
    cout << "Welcome to Passer vs Eater game.\n"
         << endl;
    cout << "What board game size do you want to play with? (Hint: Enter an integer between 3-15)" << endl;

    int boardSize;
    cin >> boardSize;

    if (boardSize < 3 || boardSize > 15)
    {
        cout << "That value is invalid. Defaulting to a 5x5 board." << endl
             << endl;
        boardSize = 5;
    }

    Board *board = new Board(boardSize); // construct the board

    Player *passerPlayer = new HumanPlayer(1);
    Player *eaterPlayer = new HumanPlayer(-1);

    PasserEaterGame game(board, passerPlayer, eaterPlayer);

    game.play();

    return 0;
}