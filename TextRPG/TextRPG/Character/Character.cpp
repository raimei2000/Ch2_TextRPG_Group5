#include "Character.h"

Player::Player(std::string name, int hp, int power, int defence, int exp) {
    name_ = name;
    hp_ = hp;
    max_hp_ = hp; //캐릭터 생성 시 캐릭터의 최대 체력
    power_ = power;
    defence_ = defence;

    level_ = 1;
    max_level_ = 10;
    exp_ = exp;
    max_exp_ = 100;
}

int Player::get_hp() const {
    return hp_;
}

void Player::set_hp(int new_hp) {
    hp_ = new_hp;
}

void Player::set_name(const std::string& new_name) {
    name_ = new_name;
}

int Player::get_power() const{
    return power_;
}

int Player::get_defence() const{
    return defence_;
}

void Player::gain_exp(int amount) {
    if (level_ >= max_level_) {
        return;
    }
    exp_ += amount;

    while (exp_ >= max_exp_ && level_ < max_level_) {
        exp_ -= max_exp_;
        ++level_;

        max_hp_ += level_ * 20;
        power_ += level_ * 5;
        defence_ += level_ * 5;

        hp_ = max_hp_;
    }
    //최대 레벨이 됐을 때 경험치 오르지 않도록 0으로 고정
    if (level_ == max_level_) {
        exp_ = 0;
    }
}