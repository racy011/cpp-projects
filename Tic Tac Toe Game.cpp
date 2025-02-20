#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    int move;
    char currentPlayer = 'X';
    bool gameWon = false;

    while(!gameWon && !isBoardFull()) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        // Validate move
        if(move < 1 || move > 9 || board[row][col]=='X' || board[row][col]=='O') {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if(checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameWon = true;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    if(!gameWon)
        cout << "The game is a tie!" << endl;

    return 0;
}
