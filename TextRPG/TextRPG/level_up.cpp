#include "character.h"

void Character::GainExp(int amount) {
  if (amount <= 0 || level_ >= max_level_) {
      return;
  }

  exp_ += amount;

  while (exp_ >= max_exp_ && level_ < max_level_) {
      exp_ -= max_exp_;
      LevelUp();
  }
}

void Character::LevelUp() {
  ++level_;

  max_hp_ += level_ * 20;
  power_ += level_ * 5;
  defence_ += level_ * 5;

  hp_ = max_hp_;

  // 다음 레벨업에 필요한 경험치 증가
  max_exp_ += 50;

  // 최대 레벨에서는 더 이상 레벨업하지 않음
  if (level_ >= max_level_) {
      level_ = max_level_;
  }
}