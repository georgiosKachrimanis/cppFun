/*
    This is a simple game of Tic-Tac-Toe.
    It was created as a training during my learning of C++.
    Feel free to make any comments. I am really looking forward to hearing from you.
    G.Kachrimanis.
*/

#include <iostream>
#include <string>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void runGame();
void initGameBoard(string gameBoard[ROWS][COLS]);
void printBoard(string gameBoard[ROWS][COLS]);
void playerInput(string player, string gameBoard[ROWS][COLS]);
string checkForWinner(string player, string gameBoard[ROWS][COLS]);
bool isCellFilled(int row, int col, string gameBoard[ROWS][COLS]);
bool isBoardFilled(string gameBoard[ROWS][COLS]);

int main()
{
    runGame();
    return 0;
}

void runGame()
{
    string winner = "";

    // Games start for PLayer X
    bool xTurn = true;
    string player = "X";

    // Creation of the game board.
    string gameBoard[ROWS][COLS];
    initGameBoard(gameBoard);
    printBoard(gameBoard);

    while (winner == "")
    {
        if (xTurn)
        {
            player = "X";
        }
        else
        {
            player = "O";
        }

        playerInput(player, gameBoard);
        printBoard(gameBoard);

        winner = checkForWinner(player, gameBoard);

        // The following check is in the chance that while the board is filled there is also a winner.
        if (isBoardFilled(gameBoard) && winner == "")
        {
            cout << "Nobody wins, play another game!" << endl;
            break;
        }

        xTurn = !xTurn; // Change the player.
    }

    if (winner != "")
    {
        cout << "Congratulations player " << winner << "! You won." << endl;
    }
}

void initGameBoard(string gameBoard[ROWS][COLS])
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            gameBoard[row][col] = " ";
        }
    }
}

void printBoard(string gameBoard[ROWS][COLS])
{

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << gameBoard[i][j];
            if (j < 2)
            {
                cout << " | ";
            }
        }
        cout << endl;

        if (i < 2)
        {
            cout << "- - - - -" << endl;
        }
    }
}

string checkForWinner(string player, string gameBoard[ROWS][COLS])
{
    // Check Rows
    for (int j = 0; j < COLS; j++)
    {
        if (gameBoard[0][j] == player && gameBoard[1][j] == player && gameBoard[2][j] == player)
        {
            return player;
        }
    }

    // Check Columns
    for (int i = 0; i < ROWS; i++)
    {
        if (gameBoard[i][0] == player && gameBoard[i][1] == player && gameBoard[i][2] == player)
        {
            return player;
        }
    }

    // Diagonal
    if ((gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player) || (gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player))
    {
        return player;
    }

    return "";
}

void playerInput(string player, string gameBoard[ROWS][COLS])
{

    int row = -1;
    int col = -1;

    cout << "It is player's " << player << " turn to play." << endl;
    cout << "Please enter the row and THEN the column, each from 0, 1, or 2, separated by a space!" << endl;
    cin >> row;
    cin >> col;
    cout << "The Row: " << row << endl;
    cout << "The Col: " << col << endl;

    // check for out of bounds input and for inout targeting an already filled cell.
    if (row >= 0 && row <= 2 && col >= 0 && col <= 2)
    {

        if (isCellFilled(row, col, gameBoard))
        {
            cout << "The move you declared is not valid. The cell is already filled! " << endl;
            cout << "Please try with another move!" << endl;
            playerInput(player, gameBoard);
        }
        else
        {
            gameBoard[row][col] = player;
        }
    }
    else
    {
        cout << "Please provide a valid input between 0 and 2." << endl;
        playerInput(player, gameBoard);
    }
}

bool isCellFilled(int row, int col, string gameBoard[ROWS][COLS])
{
    if (gameBoard[row][col] == " ")
    {
        return false;
    }
    return true;
}

// This function will check if there is any empty cell on the game board. If there is it will return false, otherwise will return true.
bool isBoardFilled(string gameBoard[ROWS][COLS])
{

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (gameBoard[i][j] == " ")
            {
                return false;
            }
        }
    }

    return true;
}