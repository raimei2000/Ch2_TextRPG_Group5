#include "orc.h"

#include <iostream>

#include "random_number_generator.h"
#include "character.h"



// 플레이어 레벨에 비례한 랜덤 스탯으로 오크 생성
Orc::Orc(int player_level)
  : Monster(
    "Orc",
    RandomNumberGenerator::RandomInteger(
      player_level * 40, player_level * 60),
    RandomNumberGenerator::RandomInteger(
      player_level * 10, player_level * 20)) {
}

// 공격 문구
void Orc::Attack(Character* character) {
  std::cout << "Orc Attack!\n";
  character->TakeDamage(attack( ));
}