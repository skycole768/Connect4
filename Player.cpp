#include "Player.h"

using namespace std;

string name;

Player::Player(){
    name = "Zoey";
}
Player::~Player() {
    name.clear();
}

void Player::play(char player, Board &board){};
string Player::getName() {
    return name;
}
void Player::setName(string playerName){
    name = playerName;
}
bool Player::won(char player, Board &board){
    return board.won(player);
}
