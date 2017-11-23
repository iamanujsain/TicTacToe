#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Game {

private:
    char board[3][3];
    bool gameActive;

public:
    // Game constructor
    Game() {
        gameActive = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    // Draws the board
    void drawBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                    printf("%c", board[i][j]);
                if (j == 1 || j == 0) {
                    printf("  | ");
                }
            }
            if (i == 0 || i == 1) {
                cout << "\n-------------" << endl;
            }
        }
    }

    // Checks if any box in the grid is empty or not and return true if it's empty otherwise returns false.ndes
    bool isEmpty(int row, int col) {
        if (board[row-1][col-1] == ' ') {
            return true;
        } else {
            return false;
        }
    }

    void setGameActive(bool b) {
        gameActive = b;
    }

    // Checks if any move made by the player is whether valid or not and return true or false respectively.
    bool notValid(int row, int col) {
        if (row > 3 || row < 1 || col < 1 || col > 3 || !isEmpty(row, col)) {
            cout << "This place is not valid.\n";
            return true;
        } else {
            return false;
        }
    }

    bool makeMove(char player, int row, int col) {
        board[row-1][col-1] = player;
    }

    void askPlayer(char player) {
        int row, col;
        do {
            printf("\n\nPlayer %c, enter a row: ", player);
            scanf("%d", &row);
            printf("\n\n\nPlayer %c, enter a column: ", player);
            scanf("%d", &col);
        } while(notValid(row, col));
        if (!notValid(row,col)) {
            makeMove(player, row, col);
        }
    }

    bool nv(int i) {
        if (i > 3 || i < 1) {
            return true;
        } else {
            return false;
        }
    }

    void checkForWinner() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ' && gameActive) {
                cout << "\nPlayer " << board[i][0] <<" has won the game!" << endl;
                setGameActive(false);
            }
            if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ' && gameActive) {
                cout << "\nPlayer " << board[0][i] << " has won the game!" << endl;
                setGameActive(false);
            }
        }
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ' && gameActive) {
            printf("\nThe winner is player %c!\n", board[0][0]);
            setGameActive(false);
        }
        if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ' && gameActive) {
            printf("\nThe winner is player %c!\n", board[0][2]);
            setGameActive(false);
        }
    }

    void onePlayer() {
        int counter = 0;
        while(gameActive) {
            system("cls");
            drawBoard();
            if (counter % 2 == 0) {
                askPlayer('X');
            } else {
                askPlayer('O');
            }
            drawBoard();
            counter++;
            checkForWinner();
            if (counter == 9 && gameActive) {
                cout << "\nThe match is a tie." << endl;
            }
        }
    }
};


int main() {
    Game f;
    f.onePlayer();
    return 0;
}
