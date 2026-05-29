#include <iostream>
#include "game.h"

using namespace std;

char board[3][3];
char currentPlayer;

// Initialize board
void initializeBoard() {

    char ch = '1';

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }

    currentPlayer = 'X';
}

// Display board
void displayBoard() {

    cout << "\n";

    for(int i = 0; i < 3; i++) {

        cout << " ";

        for(int j = 0; j < 3; j++) {

            cout << board[i][j];

            if(j < 2)
                cout << " | ";
        }

        cout << "\n";

        if(i < 2)
            cout << "---|---|---\n";
    }

    cout << "\n";
}

// Place mark
bool placeMark(int choice) {

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(board[row][col] == 'X' ||
       board[row][col] == 'O') {

        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

// Switch player
void switchPlayer() {

    if(currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

// Check winner
bool checkWinner() {

    // Rows
    for(int i = 0; i < 3; i++) {

        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2]) {

            return true;
        }
    }

    // Columns
    for(int i = 0; i < 3; i++) {

        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i]) {

            return true;
        }
    }

    // Diagonals
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2]) {

        return true;
    }

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0]) {

        return true;
    }

    return false;
}

// Check draw
bool checkDraw() {

    for(int i = 0; i < 3; i++) {

        for(int j = 0; j < 3; j++) {

            if(board[i][j] != 'X' &&
               board[i][j] != 'O') {

                return false;
            }
        }
    }

    return true;
}

// Main game logic
void playGame() {

    int choice;

    while(true) {

        displayBoard();

        cout << "Player "
             << currentPlayer
             << ", enter your choice (1-9): ";

        cin >> choice;

        // Invalid range
        if(choice < 1 || choice > 9) {

            cout << "Invalid choice! Try again.\n";
            continue;
        }

        // Occupied cell
        if(!placeMark(choice)) {

            cout << "Cell already occupied! Try again.\n";
            continue;
        }

        // Winner check
        if(checkWinner()) {

            displayBoard();

            cout << "Player "
                 << currentPlayer
                 << " wins!\n";

            break;
        }

        // Draw check
        if(checkDraw()) {

            displayBoard();

            cout << "Game Draw!\n";

            break;
        }

        switchPlayer();
    }
}
