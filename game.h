#ifndef GAME_H
#define GAME_H

extern char board[3][3];
extern char currentPlayer;

void initializeBoard();
void displayBoard();
bool placeMark(int choice);
void switchPlayer();
bool checkWinner();
bool checkDraw();
void playGame();

#endif
