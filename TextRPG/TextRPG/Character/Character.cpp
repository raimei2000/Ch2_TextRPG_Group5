#include "character.h"

Character::Character(const std::string& name) {
    name_ = name;
    level_ = 1;
    max_level_ = 10;

    hp_ = 100;
    max_hp_ = 100;
    power_ = 10;
    defence_ = 5;

    exp_ = 0;
    max_exp_ = 100;
}

int Character::hp() const {
    return hp_;
}

//체력이 0보다 작거나 최대 체력보다 커지는 현상 방지
void Character::set_hp(int new_hp) {
    if (new_hp < 0) {
        hp_ = 0;
    }
    else if (new_hp > max_hp_) {
        hp_ = max_hp_;
    }
    else {
        hp_ = new_hp;
    }
}

void Character::set_name(const std::string& new_name) {
    name_ = new_name;
}

int Character::power() const{
    return power_;
}

int Character::defence() const{
    return defence_;
}


void Character::GainExp(int amount) {
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

        //레벨업 후 최대 체력까지 회복
        hp_ = max_hp_;
    }
    //최대 레벨에서는 경험치를 더 이상 보유하지 않음
    if (level_ == max_level_) {
        exp_ = 0;
    }
}