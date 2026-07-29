#include "Character.h"

Player::Player(std::string name, int hp, int power, int exp) {
    name_ = name;
    hp_ = hp;
    power_ = power;

    level_ = 1;
    max_level_ = 10;
    exp_ = 0;
    max_exp_ = 100;
}

int Player::GetHP() {
    return hp_;
}

void Player::SetHP(int new_hp) {
    hp_ = new_hp;
}

void Player::SetName(const std::string& new_name) {
    name_ = new_name;
}

int Player::GetPower() {
    return power_;
}