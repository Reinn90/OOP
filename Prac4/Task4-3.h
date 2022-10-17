#ifndef TICTACTOE
#define TICTACTOE

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class TicTacToe
{
private:
    int board[3][3]; // standard 3*3 board size
    int noOfMoves;
    int player;
    int r,c; // move coordinates
public:
    TicTacToe()
    {

        // fill the array with zeroes to specify that a cell is empty
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
                board[row][col] = 0;

        noOfMoves = 0; 

        player = 1; // player X starts
    }

    void displayBoard();
    bool getXOMove(int player, int& r, int& c);
    bool isValidMove(int r, int c);
    void addMove(int player, int r, int c);
    int gameStatus();
    void play();

};

void TicTacToe::displayBoard(){

    cout << "   1    2    3" << endl
		 << endl; // top column index identifiers

	for (int i = 0; i < 3; i++) // loop through the matrix's rows
	{

		cout << i + 1; // display row index identifiers

		for (int j = 0; j < 3; j++) // loop through the matrix's columns
		{

			char playerSymbol = ' '; // empty space symbol for when the cell is empty

			if (board[i][j] == 1) // player X has occupied the cell
				playerSymbol = 'X';

			else if (board[i][j] == -1) // player O (-1) has occupied the cell
				playerSymbol = 'O';

			cout << setw(3) << playerSymbol; // fill grid with empty spaces

			if (j != 2) // display the two middle vertical dividers
				cout << " |";
		}

		cout << endl;

		if (i != 2) // display the two middle horizontal dividers
			cout << " ____|____|____" << endl
				 << "     |    |    " << endl;
	}

	cout << endl;

}

bool TicTacToe::getXOMove(int player, int &r, int &c)
{
	// if the board is filled and no more moves left
	if (noOfMoves >= 9)
		return false;

	int row, col; // player input

	// check to see if the input coordinates are valid, i.e. is the cell already occupied or if the inputs are out of bounds
	do
	{
		cin >> row >> col; // take in row and column inputs from user
		cout << endl;

		// convert user input into array indexes and then check
		// if isValidMove FALSE, !IsValidMove returns TRUE and the while loop of asking for user input continues
	} while (!isValidMove(row - 1, col - 1));

	// add your code here to update x, y
	// input - 1 for array index and returns its reference
	r = row - 1;
	c = col - 1;

	return true;
}

bool TicTacToe::isValidMove(int r, int c)
{

	// board[r][c] == 0 : if the coordinate on the board is empty
	// (r >= 0 && c >= 0) && (r < row_max && c < col_max): checking the pair to check if within boundary
		if ( ((r >= 0 && c >= 0) && (r < 3 && c < 3)) && board[r][c] == 0)
		return true;
	else
		cout << "Those coordinates are out of bounds. Please enter an integer between 1-3 to play." << endl;
		cout << "Please enter move coordinates: "; 
	return false;
}

void TicTacToe::addMove(int player, int r, int c)
{
	board[r][c] = player; // add 1 or -1 to the matrix that will determine what is displayed
}

int TicTacToe::gameStatus()
{
	// Write your code here to check if the game has been in a win status or a draw status

	// Check rows for a win
	// check every row cell
	for (int row = 0; row < 3; row++)
	{
		// check whether the top row line has a value and it's equal to the middle row and bottom row
		if (board[row][0] != 0 && (board[row][0] == board[row][1]) && board[row][1] == board[row][2])
		{
			return board[row][0]; // return the value, whether it be -1 or 1
		}
	}

	// Check columns for a win
	// check every column cell
	for (int col = 0; col < 3; col++)
	{
		// check whether the left column line has a value and it's equal to the middle column and right column
		if (board[0][col] != 0 && (board[0][col] == board[1][col]) && (board[1][col] == board[2][col]))
		{
			// return the value in that cell
			return board[0][col];
		}
	}

	// Check diagonals for a win
	// if the top left is not empty and its 'value' is equal to the middle and bottom right
	if (board[0][0] != 0 && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
	{

		// return that value : either 1 for player X or -1 for player O
		return board[0][0];
	}

	// if the top right is not empty and its 'value' is equal to the middle and bottom left
	if (board[0][2] != 0 && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
	{

		// return that value : either 1 for player X or -1 for player O
		return board[0][2];
	}

	// If it's a draw
	if (noOfMoves >= 9)
		return 2;

	return 0;
}

void TicTacToe::play(){
    TicTacToe game;

    game.displayBoard();

    int done = 0; // begin the game

	while (done == 0) // while the game is not finished yet
	{
		char playerSymbol = (player == 1) ? 'X' : 'O'; // initialise the players, since player is 1, X starts

		cout << "Player " << playerSymbol << " enter move: "; // display instructions

        int r, c; //player coordinates
		game.getXOMove(player, r, c); // check where the player input is displayed

		game.addMove(player, r, c); // display the player move

		noOfMoves++; // number of moves get's closer to the end of the game
		game.displayBoard(); // update the board

		done = game.gameStatus(); // determines the winner of if it's a draw

		if (done == 1)
		{
			cout << "Player X wins!" << endl;
			
		}
		else if (done == -1)
		{
			cout << "Player O wins!" << endl;
			
		}
		else if (done == 2)
		{
			cout << "Draw game!" << endl;
			
		}

		// swap players after a move is complete

		if (player == 1) // if Player X is finished, swap to Player O
			player = -1;
		else	// else if player O is finished, swap to player X
			player = 1;
	}

}


#endif