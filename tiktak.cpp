#include <iostream>
using namespace std;

// Global variables for the board and current player
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

// Function to display the board
void displayBoard() {
    cout << "Here’s the current board:\n";
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin() {
    // Check rows for win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }

    // Check columns for win
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }

    // Check diagonals for win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    // If no win conditions are met
    return false;
}

// Function to check for a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // Still spots left
            }
        }
    }
    return true; // No spots left, it’s a draw
}

// Function to switch players
void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

// Function to update the board with the player's move
void updateBoard(int move) {
    if (move == 1) {
        board[0][0] = currentPlayer;
    } else if (move == 2) {
        board[0][1] = currentPlayer;
    } else if (move == 3) {
        board[0][2] = currentPlayer;
    } else if (move == 4) {
        board[1][0] = currentPlayer;
    } else if (move == 5) {
        board[1][1] = currentPlayer;
    } else if (move == 6) {
        board[1][2] = currentPlayer;
    } else if (move == 7) {
        board[2][0] = currentPlayer;
    } else if (move == 8) {
        board[2][1] = currentPlayer;
    } else if (move == 9) {
        board[2][2] = currentPlayer;
    }
}

// Function to check if a move is valid
bool isValidMove(int move) {
    if (move < 1 || move > 9) {
        return false;
    }
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }
    return true;
}

// Function to reset the board
void resetBoard() {
    char count = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = count++;
        }
    }
}

// Main function to play the game
int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";

    char playAgain;

    do {
        resetBoard();
        currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            displayBoard();

            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (!isValidMove(move)) {
                cout << "Invalid move! Try again.\n";
                continue; // Go back to the start of the loop
            }

            updateBoard(move);

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins! Congratulations!\n";
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "It’s a draw! Nobody wins this time.\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing \n";

    return 0;
}
