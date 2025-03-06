#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    // Initiate variables
    int theNumber, playerNum;
    int attempt = 3; // counter for number of attempts
    char response;

    // Create seed for the program using the system time that assigns different number 
    // every tim the code is ran
    srand(time(0));

    // Get a random number between 1-15
    theNumber = rand() % 15 + 1;

    // ask the user for their guess
    cout << "Guess the number between 1-15. You have " << attempt << " attempts. \n";
    cin >> playerNum;

    // If the user inputs an invalid number (outside of range), throw an error message.
    while (playerNum < 1 || playerNum > 15)
    {
        cout << "Guess a number between 1-15 only! Try again. \n";
        break;
    }

    // Loop that display certain error messages when the player incorrectly guesses the number
    // and lets the player know how many attempts they have left
    while (playerNum != theNumber && attempt > 1)
    {
        // if the guess is too low
        if (playerNum < theNumber)
        {
            cout << "You guessed too low. Try again. You have " << attempt - 1 << " attempts left." << endl;
            cout << "Enter a number: \n";
            cin >> playerNum;
        }

        // if the guess is too high
        else
        {
            cout << "You guessed too high. Try again. You have " << attempt - 1 << " attempts left." << endl;
            cout << "Enter a number: \n";
            cin >> playerNum;
        }

        attempt--; // update the attempt counter
    }

    // if the player guessed the number correctly, display the "win" message and 
    // check if the player wants to play again
    if (playerNum == theNumber)
    {
        cout << "Congratulations! You guessed the number correctly! The number was " << playerNum << "." << endl;
        cout << "Do you want to play again? (Y/N)";
        cin >> response;

        // if they do, restart the function
        if (response == 'Y' || response == 'y')
        {
            main();
        }
    }

    // if all three guesses were wrong, display the random number and check 
    // whether the user wants to restart the game
    else
    {
        cout << "You guessed wrong and have " << attempt - 1 << " attempts remaining.\n";
        cout << "You lost. The random number was " << theNumber << "." << endl;
        cout << "Do you want to play again? (Y/N)";
        cin >> response;

        // restart the game based on player's response
        if (response == 'Y' || response == 'y')
        {
            main();
        }
    }

    return 0;
}