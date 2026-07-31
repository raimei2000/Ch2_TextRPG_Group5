#include "orc.h"

#include <iostream>

#include "random_number_generator.h"
#include "character.h"

//플레이어 레벨에 비례한 랜덤 스탯으로 오크 생성
Orc::Orc(int player_level)
  : Monster(
    "오크",
    RandomNumberGenerator::RandomInteger(
      player_level * 40, player_level * 60),
    RandomNumberGenerator::RandomInteger(
      player_level * 10, player_level * 20)) {
}

//공격 문구
void Orc::Attack(Character* character) {
  std::cout << "============================\n";
  std::cout << "🍺 술취한 오크의 공격!\n";
  std::cout << "(" << attack_ << "의 피해)\n";
  std::cout << "술취한 오크의" << attack_ << "Kg 술통 던지기!\n";
  character->TakeDamage(attack_);
}
//몬스터 출현 문구
void Orc::SpawnMessage( ) const {
  std::cout << "====================================\n";
  std::cout << "🍺 술취한 오크가 비틀거리며 나타났다!\n";
  std::cout << "HP : " << health_ << "  공격력 : " << attack_ << '\n';
  std::cout << "< 술 냄새가 진동한다... >\n";
  std::cout << "====================================\n";
}
//몬스터 사망 문구
void Orc::DeathMessage( ) const {
  std::cout << "============================\n";
  std::cout << "🍺 술취한 오크를 처치했다!\n";
  std::cout << "< ...술은 적당히... >\n";
  std::cout << "============================\n";
}