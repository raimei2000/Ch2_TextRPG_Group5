#include "bossogre.h"

#include <iostream>

#include "character.h"
#include "random_number_generator.h"

//임시 스텟
BossOgre::BossOgre( )
  : Monster("오우거", 1500, 280) {
}

//공격 문구 (HP 50% 미만일경우 대사 변경)
void BossOgre::Attack(Character* character) {
  int damage_ = attack_;

  //체력 50% 이하 분노 문구
  if ( health( ) <= 500 / 2 && !is_angry_) {
    std::cout << "============================\n";
    std::cout << " ( 위험 ) 보스 체력이 \n 50% 이하로 분노합니다.!\n";
    is_angry_ = true;
  }
  //체력 50% 이하 (공격력 20추가)
  if ( is_angry_) {
    damage_ += 20;
    std::cout << "============================\n";
    std::cout << "꼰대 오우거의\n";
    std::cout << "🔥 『정신교육』 !\n";
    std::cout << "(" << damage_ << "의 피해)\n";
    std::cout << "거봐, 내 말 맞잖아!\n";
  }
  //기본 상태
  else {
    std::cout << "============================\n";
    std::cout << "꼰대 오우거의\n";
    std::cout << "📢 『잔소리 폭격』 !\n";
    std::cout << "(" << damage_ << "의 피해)\n";
    std::cout << "\"내가 젊었을 때는 말이야!!!\"\n";
  }
  character->TakeDamage(damage_);
  //30% 확률로 한번 더 때리기
    if ( RandomNumberGenerator::RandomInteger(1, 10) <= 3 ) {
    std::cout << "꼰대 오우거의\n";
    std::cout << "📢 『보너스 어택』 !\n";
    std::cout << "(" << damage_ << "의 피해)\n";
    std::cout << "아직 말 안 끝났어! 어디가!\n";
    character->TakeDamage(damage_);
  }
}
//몬스터 출현 문구
void BossOgre::SpawnMessage( ) const {
  std::cout << "====================================\n";
  std::cout << "👴 꼰대 오우거 (보스) 등장했다!\n";
  std::cout << "HP : " << health_ << "  공격력 : " << attack_ << '\n';
  std::cout << "< 요즘 젊은 것들은 버릇이 없어!>\n";
  std::cout << "====================================\n";
}
//몬스터 사망 문구
void BossOgre::DeathMessage( ) const {
  std::cout << "====================================\n";
  std::cout << "👴 꼰대 오우거 (보스) 를 처치했다!\n";
  std::cout << "<...요즘 애들이 더 무섭구만...>\n";
  std::cout << "====================================\n";
}