#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <iostream>

class Board {

public:
    /**
     * Board constructor that initailzes the array board consisting of 6 rows and 7
     * 7 columns;
     */
    Board();

    /**
     * Board destructor that frees the array board
     */
    ~Board();

    /**
     * Function that sets the bottom most avaliable position on the board, in the column specified
     * by col, to the character as given by player.
     */
    void set(char player, int col);

    /**
     * Function that prints out the current Connect 4 game baord.
     */
    void printBoard();

    /**
     * Function that return the int value for the left most column number, that has any available
     * spaces.
     */
    int leftMostAvailable();

    /**
     * Function that checks the current board for any downward diagonal patterns char player.
     * It returns true if it finds a downward diagonal pattern with the same four
     * characters, player, in a row.
     */
    bool downwardDiagonal(char player);

    /**
     * Function that checks the current board for any upward diagonal patterns of char player.
     * It returns true if it finds a downward diagonal pattern with the same four
     * characters, player, in a row and false if otherwise.
     */
    bool upwardDiagonal(char player);

    /**
     * Function that checks the current board for any diagonal patterns of char player.
     * It returns true if it finds a diagonal pattern with the same four
     * characters, player, in a row and false if otherwise.
     */
    bool diagonalWin(char player);

    /**
     * Function that checks the current board for any horizontal patterns of char player.
     * It returns true if it finds a horizontal pattern with the same four
     * characters, player, in a row and false if otherwise.
     */
    bool horizontalWin(char player);

    /**
     * Function that checks the current board for any vertical patterns of the char player.
     * It returns true if it finds a vertical pattern with the same four
     * characters, player, in a row and false if otherwise.
     */
    bool verticalWin(char player);

    /**
     * Function that checks if the current board has any available space marked by the '_'
     * character, with no avaliable space being held by any other character.
     * Returns true if there is available space and false if otherwise.
     */
    bool draw();

    /**
     * Function that checks if the character, as given by player, has at least one consecutive
     * pattern of four on the board. It returns true if the char has Connected 4 or false if
     * otherwise.
     */
    bool won(char player);

private:
    char ** board; // game board of that holds all the characters.
};

#endif
