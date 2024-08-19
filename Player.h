#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include <string>

class Player {

public:
    /**
     * Default constructor for player that sets the player's name
     * to Zoey.
     */
    Player();

    /**
     * Default destructor for player that clears the player's name.
     */
    virtual ~Player();

    /**
     * Function that allows a player to interact with the Board board
     * by placing the character player on
     * different positions on the board.
     */
    virtual void play(char player, Board &board);

    /**
     * Function the returns the name of the player object.
     */
    virtual std::string getName();

    /**
     * Function the sets the name of the player object
     * to playerName.
     */
    void setName(std::string playerName);

    /**
     * Function that checks to see if the char player
     * has won on the board.
     * it returns true if the player has Connected 4 on the board
     * and false if otherWise;
     */
    bool won(char player, Board &board);

protected:
    std::string name; // name of the player
};

#endif
