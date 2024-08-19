#include "HumanPlayer.h"

using namespace std;

HumanPlayer::HumanPlayer() {

    cout << "Please enter your name: ";
    string playerName;
    cin >> playerName;
    Player::setName(playerName);
}

string HumanPlayer::getName(){
    return Player::name;
}
void HumanPlayer::play(char player, Board &board){
    int position;
    cout << getName() << "'s turn, Please enter an integer between 1 and 7: ";
    cin >> position;
    board.set(player, position - 1);

}
