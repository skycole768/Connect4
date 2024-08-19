#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <string>
#include "Player.h"
#include "Board.h"
#include <iostream>

class HumanPlayer : public Player {

public:


    /**
     * HumanPlayer constructor that prompts the
     * user for the name and sets the name.
     */
    HumanPlayer();


    /**
     * Function that returns the string name of the HumanPlayer
     * object.
     */
    std::string getName();


    /**
     * Function that prompts the user on where they would
     * place their character player on the board and then places
     * their player in the column, they specified, on the board.
     */
    void play(char player, Board &board);

};

#endif
