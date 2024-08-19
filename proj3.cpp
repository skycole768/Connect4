#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "SimpleComputerPlayer.h"
#include <iostream>

using namespace std;

/**
 * Function that makes the Connect 4 game loop consisting of player1 playing
 * first on the board, followed player2 playing on the board. It will continue
 * on until player1 connects 4 X's, player2 connects 4 O's, or their is a draw between
 * the 2 players on the board.
 */
void gameLoop(Player * player1, Player * player2, Board &game);


/**
 * Function that prints the message if player1 wins.
 */
void player1Won(Player * player1);


/**
 * Function that prints the message if player2 wins.
 */
void player2Won(Player * player2);


/**
 * Function that prints the message if there is a draw between the two players.
 */
void isDraw(Board &game);

/**
 * Connect four game that is played by dropping X's(player1) or O's down
 * on a board.
 * If the command line arguments given are
 * -h or -c, will create a HumanPlayer or SimpleComputerPlayer, respectively.
 * It will do this for two players.
 * HumanPlayers can input where they would like their piece to go and
 * SimpleComputerPlayer players will pick the left most column with available space.
 * Game will continue until player1 or player2 have connected 4 with their characters
 * or if there is a draw, and no more space is available on the board.
 */
int main(int argc, char *argv[]) {
    Board game = Board();
    Player * player1;
    Player * player2;
    string response = argv[1];
    string response2 = argv[2];

    if(response == "-h")
        player1 = new HumanPlayer();
    else
        player1 = new SimpleComputerPlayer();

    if(response2 == "-h")
        player2 = new HumanPlayer();
    else
        player2 = new SimpleComputerPlayer();

    gameLoop(player1, player2, game);

    if(player1 -> won('X', game)){
        player1Won(player1);
    } else if(player2 -> won('O', game)){
        player2Won(player2);
    } else {
        if(game.draw())
            isDraw(game);
    }
    delete player1;
    delete player2;
    return 0;
}

void gameLoop(Player * player1, Player * player2, Board &game){
    while(!player1 -> won('X', game) && !player2 -> won('O', game) && !game.draw()) {
        player1 -> play('X', game);
        game.printBoard();

        if(!player1 -> won('X', game)) {
            player2 -> play('O', game);
            game.printBoard();
        }
    }

    cout << endl;
}

void player1Won(Player * player1){
    cout << player1 -> getName() << " Connected Four and Wins!" << endl;

}

void player2Won(Player * player2){
    cout << player2 -> getName() << " Connected Four and Wins!" << endl;

}

void isDraw(Board &game){
    cout << "The board is full, it is a draw!" << endl;
}
