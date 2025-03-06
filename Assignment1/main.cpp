/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the code
has been written/produced for me by another person or copied from any
other source.

I hold a copy of this assignment that I can produce if the original is
lost or damaged.

* Nowell Kevin Reyes - 20658133
**************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

#include "PasserEaterGame.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "NovicePlayer.h"
#include "SmartPlayer.h"

int main()
{
    srand(time(0));

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

    cout << "\nSelect Gameplay Option: " << endl;
    cout << "**********Passer************Eater**********" << endl;
    cout << "1:        Human      vs     Human        :1" << endl;
    cout << "2:  Straight Line    vs     Human        :2" << endl;
    cout << "3:       Random      vs     Random       :3" << endl;
    cout << "4:        Smart      vs     Random       :4" << endl;
    cout << "5:       Random      vs     Smart        :5" << endl;
    cout << "6:        Human      vs     Smart        :6" << endl;

    int option;
    cout << "What mode do you want to play? " << endl;
    cin >> option;

    while (option <= 0 || option > 6)
    {
        cout << "Please select a number between 1-6. " << endl;
        cin >> option;
    }

    if (option != 7)
    {
        Player *passerPlayer, *eaterPlayer;

        if (option == 1)
        {
            passerPlayer = new HumanPlayer(1, "Passer(Human)");
            eaterPlayer = new HumanPlayer(-1, "Eater(Human)");
        }

        if (option == 2)
        {
            passerPlayer = new NovicePlayer(1, "Passer(Novice)");
            eaterPlayer = new HumanPlayer(-1, "Eater(Human)");
        }

        if (option == 3)
        {
            passerPlayer = new RandomPlayer(1, "Passer(Random)");
            eaterPlayer = new RandomPlayer(-1, "Eater(Random)");
        }

        if (option == 4)
        {
            passerPlayer = new SmartPlayer(1, "Passer(Smart)");
            eaterPlayer = new RandomPlayer(-1, "Eater(Random)");
        }

        if (option == 5)
        {
            passerPlayer = new RandomPlayer(1, "Passer(Random)");
            eaterPlayer = new SmartPlayer(-1, "Eater(Smart)");
        }

        if (option == 6)
        {
            passerPlayer = new HumanPlayer(1, "Passer(Human)");
            eaterPlayer = new SmartPlayer(-1, "Eater(Smart)");
        }

        Board *board = new Board(boardSize, passerPlayer->getName(), eaterPlayer->getName()); // construct the board

        PasserEaterGame game(board, passerPlayer, eaterPlayer);

        game.play();

        delete passerPlayer;
        delete eaterPlayer;
        delete board;

        cout << "Would you like to play again? (Y/N)" << endl;
        char response;
        cin >> response;

        if (response == 'Y' || response == 'y')
            main();

        system("pause");
        return 0;
    }
}