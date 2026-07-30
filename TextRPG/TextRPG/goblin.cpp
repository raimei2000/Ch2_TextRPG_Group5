#include "goblin.h"

#include <iostream>

#include "random_number_generator.h"
#include "character.h"



// 플레이어 레벨에 비례한 랜덤 스탯으로 고블린 생성
Goblin::Goblin(int player_level)
  : Monster(
    "고블린",
    RandomNumberGenerator::RandomInteger(
      player_level * 20, player_level * 30),
    RandomNumberGenerator::RandomInteger(
      player_level * 5, player_level * 10)) {
}

// 공격 문구
void Goblin::Attack(Character* character) {
  std::cout << "고블린 공격!\n";
  character->TakeDamage(attack_);
}