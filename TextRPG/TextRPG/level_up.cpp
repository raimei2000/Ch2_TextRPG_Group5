#include "character.h"

#include <iostream>

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
  //레벨업 전 수치 저장
  const int prev_level = level_;
  const int prev_max_hp = max_hp_;
  const int prev_power = power_;
  const int prev_defence = defence_;

  //레벨상승
  ++level_;

  //상승한 레벨을 기준으로 능력치 상승
  max_hp_ += level_ * 20;
  power_ += level_ * 5;
  defence_ += level_ * 5;

  //레벨업 후 최대체력까지 회복
  hp_ = max_hp_;

  // 다음 레벨업에 필요한 경험치 증가
  max_exp_ += 50;

  // 최대 레벨에서는 더 이상 레벨업하지 않음
  if (level_ >= max_level_) {
      level_ = max_level_;
  }
  //레벨업 결과 출력
  std::cout << std::endl << "===== ★★★★★ 레벨 업! ★★★★★ =====" << std::endl;
  std::cout << "레벨: " << prev_level << " -> " << level_ << std::endl;
  std::cout << "최대 체력: " << prev_max_hp << " -> " << max_hp_ << std::endl;
  std::cout << "공격력: " << prev_power << " -> " << power_ << std::endl;
  std::cout << "방어력: " << prev_defence << " -> " << defence_ << std::endl;
  std::cout << "체력이 최대치까지 회복되었습니다." << std::endl;
  std::cout << std::endl << "================================" << std::endl;
}