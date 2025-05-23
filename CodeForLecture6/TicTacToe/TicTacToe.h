/*
 * TicTacToe.h
 *
 *  Created on: 23 Jul. 2020
 *      Author: dongmo
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

	enum status {
		WIN, DRAW, CONTINUE
	};


class TicTacToe {

public:
	TicTacToe() { //Default constructor.
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 3; col++) {
				board[row][col] = ' ';
			}

		noOfMoves = 0;
	}

	TicTacToe(const TicTacToe& cboard) { //Copy constructor.
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 3; col++)
				board[row][col] = cboard.board[row][col];
		noOfMoves = cboard.noOfMoves;
	}

	void displayBoard() const;
	//Function to print the board.

	bool isValidMove(int x, int y) const;
	//Function to determine if a move is valid.

	void getXOMove(char moveSymbol, int&, int&);
	//Function to get a move for player X

	bool addMove(char playerSymbol, int, int);

	status gameStatus();

	void play();

private:
	char board[3][3];
	int noOfMoves;
};

void TicTacToe::play() {
	bool done = false;
	char player = 'X';

	displayBoard();

	while (!done) {
		int row, col;
		if (player == 'X')
			getXOMove(player, row, col);
		else
			getXOMove(player, row, col);

		done = addMove(player, row, col);

		displayBoard();

		if (player == 'X')
			player = 'O';
		else
			player = 'X';
	}
}

void TicTacToe::displayBoard() const {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			cout << " " << board[row][col];
			if (col != 2)
				cout << " |";
		}

		cout << endl;

		if (row != 2)
			cout << " -   -   - " << endl;
	}

	cout << endl;
}

bool TicTacToe::isValidMove(int row, int col) const {
	if (0 <= row && row <= 2 && 0 <= col && col <= 2 && board[row][col] == ' ')
		return true;
	else
		return false;
}

void TicTacToe::getXOMove(char playerSymbol, int& row, int& col) {

	do {
		cout << "Player " << playerSymbol << " enter move: ";
		cin >> row >> col;
		cout << endl;
	} while (!isValidMove(row - 1, col - 1));

	row--;
	col--;
}

bool TicTacToe::addMove(char playerSymbol, int row, int col) {
	noOfMoves++;

	board[row][col] = playerSymbol;
//	displayBoard();

	status gStatus = gameStatus();

	if (gStatus == WIN) {
		cout << "Player " << playerSymbol << " wins!" << endl;
		return true;
	} else if (gStatus == DRAW) {
		cout << "This game is a draw!" << endl;
		return true;
	} else if (noOfMoves >= 9) {
		return true;
	} else
		return false;
}

status TicTacToe::gameStatus() {
	//Check rows for a win
	for (int row = 0; row < 3; row++)
		if (board[row][0] != ' ' && (board[row][0] == board[row][1])
				&& (board[row][1] == board[row][2]))
			return WIN;

	//Check columns for a win
	for (int col = 0; col < 3; col++)
		if (board[0][col] != ' ' && (board[0][col] == board[1][col])
				&& (board[1][col] == board[2][col]))
			return WIN;

	//Check diagonals for a win
	if (board[0][0] != ' ' && (board[0][0] == board[1][1])
			&& (board[1][1] == board[2][2]))
		return WIN;

	if (board[2][0] != ' ' && (board[2][0] == board[1][1])
			&& (board[1][1] == board[0][2]))
		return WIN;

	if (noOfMoves < 9)
		return CONTINUE;

	return DRAW;
}

#endif /* TICTACTOE_H_ */
