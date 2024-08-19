#include "Board.h"

using namespace std;

char **board; // board that holds all of the characters

Board::Board() {

    board = new char*[6];
    for(int i = 0; i < 6; ++i) {
        board[i] = new char[7];
    }
    int row = 6;
    int column = 7;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            board[i][j] = '_';
        }
    }
}

Board::~Board() {

    for (int j = 0; j < 6; j++) {
        delete[] board[j];
    }

    delete[] board;
}

void Board::set(char player, int col){
    int rowMax = 6;
    bool placed = false; // true when 'player' has been placed in the board

    for(int i = rowMax - 1; i >= 0 && placed == false; i--) {
        if (board[i][col] == '_') {
            board[i][col] = player;
            placed = true;
        }
    }
}

void Board::printBoard() {

    int row = 6;
    int column = 7;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {

            cout << "|" << board[i][j] ;

        }
        cout << "|" << endl;
    }
}

bool Board::draw() {
    int rowMax = 6;
    int colMax = 7;
    int count = 0;

    for (int i = 0; i < rowMax; i++) {
        for (int j = 0; j < colMax; j++) {
            if( board[i][j] == '_')
                count++;
        }
    }

    if(count == 0)
        return true;
    else
        return false;
}

int Board::leftMostAvailable() {
    int i = 0;
    int j = 0;

    while (i < 6) {
        while (j < 7) {
            if(board[i][j] == '_') {
                return j;
            }
            j++;
        }
        i++;
    }

    return 0;

}

bool Board::downwardDiagonal(char player){
    bool connecctFour = false; // true when there is a downward diagonal of four 'player's
    int rowMax = 6;
    int colMax = 7;

    for(int i = 0; i < rowMax; i++) {
        int count = 0;
        for(int j = 0; j < colMax && j + i < rowMax; j++) {
            if (board[i +j][j] == player) {
                count++;
            } else {
                count = 0;
            }
            if (count == 4) {
                connecctFour = true;
                return connecctFour;
            }
        }
    }
    return connecctFour;
}

bool Board::upwardDiagonal(char player) {
    bool connecctFour = false; // true when there is a upward diagonal of four 'player's
    int rowMax = 6;
    int colMax = 7;

    for(int i = 0; i < rowMax; i++) {
        int count = 0;
        for (int j = 0, h = rowMax - i - 1; j < colMax && h >= 0; j++, h--) {
            if (board[h][j] == player) {
                count++;
            } else {
                count = 0;
            }
            if (count == 4) {
                connecctFour = true;
                return connecctFour;
            }
        }
    }
    return connecctFour;

}

bool Board::diagonalWin(char player) {
    bool connecctFour = false; // true when there is a diagonal of four 'player's

    if (upwardDiagonal(player) || downwardDiagonal(player)) {
        connecctFour = true;
    }
    return connecctFour;
}

bool Board::horizontalWin(char player) {
    bool connecctFour = false; // true when there is a vertical pattern of four 'player's
    int rowMax = 6;
    int colMax = 7;

    for(int i = 0; i < rowMax; i++) {
        int count = 0;

        for (int j = 0; j < colMax; j++) {

            if (board[i][j] == player) {
                count++;
            } else {
                count = 0;
            }

            if (count == 4) {
                connecctFour = true;
                return connecctFour;
            }
        }
    }
    return connecctFour;
}


bool Board::verticalWin(char player) {
    bool connecctFour = false; // true when there is a horizontal pattern of four 'player's
    int rowMax = 6;
    int colMax = 7;

    for(int i = 0; i < colMax; i++) {
        int count = 0;
        for (int j = 0; j < rowMax; j++) {

            if (board[j][i] == player) {
                count++;
            } else {
                count = 0;
            }

            if (count == 4) {
                connecctFour = true;
                return connecctFour;
            }
        }
    }
    return connecctFour;
}

bool Board::won(char player){
    if(verticalWin(player) || horizontalWin(player) || diagonalWin(player)){
        return true;
    } else {
        return false;
    }
}
