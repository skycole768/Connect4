#ifndef SIMPLECOMPUTERPLAYER_H
#define SIMPLECOMPUTERPLAYER_H

#include "Player.h"
#include <iostream>
#include "Board.h"

class SimpleComputerPlayer : public Player {

public:

    /**
     * Default constructor of SimpleComputerPlayer that prints out the
     * prompt an the User's name, Zoey.
     */
    SimpleComputerPlayer();

    /**
     * Function that sets the char player to left most
     * avaliable space on the board.
     */
    void play(char player, Board &board);
};

#endif
