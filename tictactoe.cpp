
#include <iostream>
using namespace std;

// Function to display the game board
void displayBoard(char board[]) {
    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
    cout << "     |     |     \n\n";
}

// Function to check winning condition
bool checkWinner(char board[], char player) {

    int winPatterns[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        if (board[winPatterns[i][0]] == player &&
            board[winPatterns[i][1]] == player &&
            board[winPatterns[i][2]] == player) {
            return true;
        }
    }

    return false;
}

// Function to check whether board is full
bool isDraw(char board[]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;
}

// Main function
int main() {

    char board[9] = {'1','2','3','4','5','6','7','8','9'};

    char currentPlayer = 'X';
    int position;

    cout << "================================\n";
    cout << "       TIC TAC TOE GAME\n";
    cout << "================================\n";

    cout << "Player 1: X\n";
    cout << "Player 2: O\n";

    displayBoard(board);

    while (true) {

        cout << "Player " << currentPlayer;
        cout << ", enter position (1-9): ";
        cin >> position;

        // Validate input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a number.\n";
            continue;
        }

        if (position < 1 || position > 9) {
            cout << "Invalid position! Choose between 1 and 9.\n";
            continue;
        }

        // Check whether position is already occupied
        if (board[position - 1] == 'X' ||
            board[position - 1] == 'O') {
            cout << "Position already occupied! Try again.\n";
            continue;
        }

        // Place player's symbol
        board[position - 1] = currentPlayer;

        displayBoard(board);

        // Check winner
        if (checkWinner(board, currentPlayer)) {
            cout << "Congratulations! Player "
                 << currentPlayer << " wins!\n";
            break;
        }

        // Check draw
        if (isDraw(board)) {
            cout << "Game Draw!\n";
            break;
        }

        // Switch player
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    cout << "\nThank you for playing Tic Tac Toe!\n";

    return 0;
}
