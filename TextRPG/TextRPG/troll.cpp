#include "troll.h"

#include <iostream>

#include "random_number_generator.h"
#include "character.h"



// 플레이어 레벨에 비례한 랜덤 스탯으로 트롤 생성
Troll::Troll(int player_level)
  : Monster(
    "Troll",
    RandomNumberGenerator::RandomInteger(
      player_level * 50, player_level * 70),
    RandomNumberGenerator::RandomInteger(
      player_level * 20, player_level * 30)) {
}

// 공격 문구
void Troll::Attack(Character* character) {
  std::cout << "Troll Attack!\n";
  character->TakeDamage(attack( ));
}