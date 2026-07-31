#include "goblin.h"

#include <iostream>

#include "random_number_generator.h"
#include "character.h"

//플레이어 레벨에 비례한 랜덤 스탯으로 고블린 생성
Goblin::Goblin(int player_level)
  : Monster(
    "고블린",
    RandomNumberGenerator::RandomInteger(
      player_level * 20, player_level * 30),
    RandomNumberGenerator::RandomInteger(
      player_level * 5, player_level * 10)) {
}

//공격 문구
void Goblin::Attack(Character* character) {
  std::cout << "악취 고블린의 입냄새 공격!\n";
  character->TakeDamage(attack_);
}
//몬스터 출현 문구
void Goblin::SpawnMessage( ) const {
std::cout << "============================\n";
std::cout << "🤢 야생에서 악취 고블린이 나타났다!\n";
std::cout << "< 강력한 악취가 주변을 뒤덮는다... >\n";
std::cout << "============================\n";
}
//몬스터 사망 문구
void Goblin::DesthMessage( ) const {
  std::cout << "============================\n";
  std::cout << "🤢 악취 고블린을 처치했다!\n";
  std::cout << "< 양치... 할걸...>\n";
  std::cout << "============================\n";
}