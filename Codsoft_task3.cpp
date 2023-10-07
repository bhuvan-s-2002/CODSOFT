#include <iostream>
#include <vector>

using namespace std;

// Function to initialize the game board
void InitializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        vector<char> row(3, ' ');
        board.push_back(row);
    }
}

// Function to display the game board
void DisplayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
    cout << endl;
}

// Function to check if a player has won
bool CheckWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;  // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;  // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;  // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;  // Diagonal win (top-right to bottom-left)
    }
    return false;
}

// Function to check if the game is a draw
bool CheckDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;  // Empty cell found, game is not a draw
            }
        }
    }
    return true;  // All cells are filled, game is a draw
}

int main() {
    vector<vector<char>> board;
    char currentPlayer = 'X';
    bool gameIsOver = false;

    InitializeBoard(board);

    while (!gameIsOver) {
        DisplayBoard(board);

        // Get player's move
        int row, col;
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (CheckWin(board, currentPlayer)) {
                DisplayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameIsOver = true;
            }
            // Check for a draw
            else if (CheckDraw(board)) {
                DisplayBoard(board);
                cout << "It's a draw!" << endl;
                gameIsOver = true;
            }
            else {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    // Ask if players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        InitializeBoard(board);
        gameIsOver = false;
        currentPlayer = 'X';
    }
    else {
        cout << "Thanks for playing! Goodbye." << endl;
    }

    return 0;
}
