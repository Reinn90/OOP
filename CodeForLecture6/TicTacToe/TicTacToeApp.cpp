/*
 * TicTacToeApp.cpp
 *
 *  Created on: 23 Jul. 2020
 *      Author: dongmo
 */

#include <iostream>
#include <ctime>

using namespace std;

#include "TicTacToe.h"

int main()
{
	srand(time(0));
	//	TicTacToe board;
	//	board.play();

	// TicTacToe *board;
	// board = new TicTacToe;
	// board->play();

	TicTacToe firstBoard;
	firstBoard.addMove('X', 1, 2);
	firstBoard.displayBoard();

	// TicTacToe secondBoard;
	// secondBoard.displayBoard();

	// secondBoard = firstBoard;
	// secondBoard.displayBoard();

	TicTacToe *thirdBoardPtr = new TicTacToe(firstBoard);
	thirdBoardPtr->displayBoard();

	return 0;
}
