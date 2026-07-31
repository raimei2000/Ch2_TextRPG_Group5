#include "troll.h"

#include <iostream>

#include "random_number_generator.h"
#include "character.h"

//플레이어 레벨에 비례한 랜덤 스탯으로 트롤 생성
Troll::Troll(int player_level)
  : Monster(
    "트롤",
    RandomNumberGenerator::RandomInteger(
      player_level * 50, player_level * 70),
    RandomNumberGenerator::RandomInteger(
      player_level * 20, player_level * 30)) {
}

//공격 문구
void Troll::Attack(Character* character) {
  std::cout << "헬창 트롤의 덤벨 던지기!\n";
  character->TakeDamage(attack_);
}
//몬스터 출현 문구
void Troll::SpawnMessage( ) const {
  std::cout << "============================\n";
  std::cout << "💪 헬창 트롤이 등장했다!\n";
  std::cout << "< 오늘도 단백질 300g 먹었다...헤헤>\n";
  std::cout << "============================\n";
}
//몬스터 사망 문구
void Troll::DesthMessage( ) const {
  std::cout << "============================\n";
  std::cout << "💪 헬창 트롤을 처치했다!\n";
  std::cout << "< 근... 손실만은...>\n";
  std::cout << "============================\n";
}