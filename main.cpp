#include <iostream>
#include "game.h"

using namespace std;

int main() {

    char replay;

    do {
        initializeBoard();
        playGame();

        cout << "\nDo you want to play again? (y/n): ";
        cin >> replay;

    } while(replay == 'y' || replay == 'Y');

    cout << "Thanks for playing!\n";

    return 0;
}
