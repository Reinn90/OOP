#ifndef BOARD
#define BOARD

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Board
{
    int noOfMoves; // number of moves
    int **board;  // dynamic board pointer
public:
    int dim; // dimension of the board grid

    // int player;
    // char playerSymbol;
    // int r, c;

    Board(); // default constructor
    // Constructor
    Board(int size)
    {

        dim = size;

        // initiate pointer of pointer variable of user input size
        board = new int *[size];

        // create dynamic 2D array
        for (int i = 0; i < size; i++)
            board[i] = new int[size];

        // fill the array with zeroes to specify that a cell is empty
        for (int row = 0; row < size; row++)
            for (int col = 0; col < size; col++)
                board[row][col] = 0;

        noOfMoves = 0;
    }

    // Destructor
    ~Board()
    {
        for (int i = 0; i < dim; i++)
            delete[] board[i];

        delete[] board;
    }

    // Copy Constructor
    Board(const Board &cboard)
    {
        for (int row = 0; row < dim; row++)
            for (int col = 0; col < dim; col++)
                board[row][col] = cboard.board[row][col];

        noOfMoves = cboard.noOfMoves;
    }

    char getGrid(int i, int j) { return board[i][j]; };

    bool isFull() { return noOfMoves >= dim * dim; }; // maximum No of moves is the dimesion squared

    void displayBoard() const;

    bool isValidInput(int x, int y) const;

    void addMove(int playerInt, int x, int y);

    int gameStatus();

    void reStart();

    // int threatenLevel(char playerId);

    // vector<int> getEmptyPositions();
    // void getaRandomMove(int &x, int &y);
};


int Board::gameStatus() {
	//Check rows for a win
	for (int row = 0; row < 3; row++)
		if (board[row][0] != ' ' && (board[row][0] == board[row][1])
				&& (board[row][1] == board[row][2]))
			return board[row][0];

	//Check columns for a win
	for (int col = 0; col < 3; col++)
		if (board[0][col] != ' ' && (board[0][col] == board[1][col])
				&& (board[1][col] == board[2][col]))
			return board[0][col];

	//Check diagonals for a win
	if (board[0][0] != ' ' && (board[0][0] == board[1][1])
			&& (board[1][1] == board[2][2]))
		return board[0][0];

	if (board[2][0] != ' ' && (board[2][0] == board[1][1])
			&& (board[1][1] == board[0][2]))
		return board[2][0];

	if (noOfMoves >= dim*dim)
		return -1; // Eater wins

	return 0; // continu
}

void Board::displayBoard() const
{
    // column index display
    cout << " ";
    for (int i = 0; i < dim; i++)
        cout << setw(4) << i + 1;
    cout << endl;

    // top divider
    cout << setw(3);
    for (int i = 0; i < dim * 4; i++)
        cout << "-";
    cout << "-" << endl;

    // grid board display
    for (int i = 0; i < dim; i++)
    {
        // row indexes
        cout << i + 1;
        if (i < 9)
            cout << " |";
        else
            cout << "|"; // re-allign vertical grid for board > 10 boardSizeension

        for (int j = 0; j < dim; j++)
        {
            char playerSymbol = ' ';
            
             if (board[i][j] == 1) // Passer has occupied the cell
                 playerSymbol = 'P';

             else if (board[i][j] == -1) // Eater has occupied the cell
                 playerSymbol = 'E';
            
             //cout << setw(2) << playerSymbol << setw(2);
             cout << setw(2) << playerSymbol << setw(2);
            
            if (j != dim) // display the two middle vertical dividers
                cout << "|";
        }

        if (i != dim - 1)
            cout << endl
                 << endl;
    }

    // bottom divider
    cout << endl
         << setw(3);
    for (int i = 0; i < dim * 4; i++)
        cout << "-";
    cout << "-" << endl;
}

bool Board::isValidInput(int row, int col) const
{

    if (0 <= row && row <= (dim - 1) && 0 <= col && col <= (dim - 1) && board[row][col] == 0)
        return true;
    else
    {
        cout << "Those coordinates are out of bounds or cell already occupied. Please enter an integer between "
             << "1-" << dim << " to play." << endl;
        cout << "Please enter move coordinates: ";
        return false;
    }

    /*
    if (player == -1) // eater only check for boundaries
    {
        if ((r >= 0 && r < boardSize) && (c >= 0 && c < boardSize))
            return true;
        else
        {
            cout << "Those coordinates are out of bounds or cell already occupied. Please enter an integer between "
                 << "1-" << boardSize << " to play." << endl;
            cout << "Please enter move coordinates: ";
            return false;
        }
    }
    else
    {
        // board[r][c] == 0 : if the coordinate on the board is empty
        // (r >= 0 && c >= 0) && (r < row_max && c < col_max): checking the pair to check if within boundary
        if ((r >= 0 && r < boardSize) && (c >= 0 && c < boardSize) && board[r][c] == 0)
            return true;
        else
        {
            cout << "Those coordinates are out of bounds or cell already occupied. Please enter an integer between "
                 << "1-" << boardSize << " to play." << endl;
            cout << "Please enter move coordinates: ";
            return false;
        }
    }
    */
}

void Board::addMove(int playerInt, int x, int y)
{
    if(!isValidInput(x,y))
        return;
    
    board[x][y] = playerInt;

    noOfMoves++;

    // board[r][c] = player * -1; // add 1 or -1 to the matrix that will determine what is displayed

    // // eater
    // if (player == -1 && board[r][c] == 1)
    // {
    //     board[r][c] = -1;
    // }
}

void Board::reStart() {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = ' ';

	noOfMoves = 0;
}

#endif