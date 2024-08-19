#include "SimpleComputerPlayer.h"

using namespace std;

SimpleComputerPlayer::SimpleComputerPlayer() {
    cout << "Please enter your name: " << Player::getName() << endl;
}

void SimpleComputerPlayer::play(char player, Board &board) {

    cout << Player::getName() << "'s turn, Please enter an integer between 1 and 7: ";
    int position = board.leftMostAvailable() + 1;
    cout << position << endl;
    board.set(player, board.leftMostAvailable());
}
