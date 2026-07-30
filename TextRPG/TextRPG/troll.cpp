#include "troll.h"

#include <iostream>

#include "random_number_generator.h"
#include "character.h"



// 플레이어 레벨에 비례한 랜덤 스탯으로 트롤 생성
Troll::Troll(int player_level)
  : Monster(
    "트롤",
    RandomNumberGenerator::RandomInteger(
      player_level * 50, player_level * 70),
    RandomNumberGenerator::RandomInteger(
      player_level * 20, player_level * 30)) {
}

// 공격 문구
void Troll::Attack(Character* character) {
  std::cout << "트롤 공격!\n";
  character->TakeDamage(attack_);
}