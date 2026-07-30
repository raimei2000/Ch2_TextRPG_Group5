#include "character.h"
#include <iostream>

Character::Character(const std::string& name)
  : name_(name),
  level_(1),
  max_level_(10),
  hp_(200),
  max_hp_(200),
  power_(30),
  defence_(30),
  exp_(0),
  max_exp_(100) {
}

const std::string& Character::name() const {
  return name_;
}

int Character::level() const {
  return level_;
}

int Character::hp() const {
  return hp_;
}

int Character::max_hp() const {
  return max_hp_;
}

int Character::power() const {
  return power_;
}

int Character::defence() const {
  return defence_;
}

int Character::exp() const {
  return exp_;
}

int Character::max_exp() const {
  return max_exp_;
}

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

void Character::set_power(int new_power) {
  if (new_power < 0){
    power_ = 0;
  }
  else {
    power_ = new_power;
  }
}

void Character::set_name(const std::string& new_name) {
  name_ = new_name;
}


void Character::status() const {
  //캐릭터 스테이터스 표시
  std::cout << "===== Character Status =====" << std::endl;
  std::cout << "Name    : " << name_ << std::endl;
  std::cout << "Lovel   : " << level_ << "/" << max_level_ << std::endl;
  std::cout << "HP      : " << hp_ << "/" << max_hp_ << std::endl;
  std::cout << "Power   : " << power_ <<std::endl;
  std::cout << "Defernce: " << defence_ <<std::endl;
  std::cout << "Exp     : " << exp_ << "/" << max_exp_ << std::endl;
  std::cout << "============================" << std::endl;
}