#include "game_manager.h"

#include <iostream>
#include <vector>
#include <functional>

#include "character.h"
#include "monster.h"
#include "health_potion.h"
#include "attack_boost.h"
#include "random_number_generator.h"
#include "logger.h"

// 몬스터 추가시 해당 몬스터의 헤더 포함
#include "goblin.h"
#include "orc.h"
#include "troll.h"

namespace {

using MonsterFactory = std::function<Monster*(int)>;

const std::vector<MonsterFactory>& MonsterRegistry( ) {
  static const std::vector<MonsterFactory> registry = {
    // 몬스터 추가시 람다 추가. 예시)
    // [](int lv) -> Monster* { return new Dragon(lv); },
    [](int lv) -> Monster* { return new Goblin(lv); },
    [](int lv) -> Monster* { return new Orc(lv); },
    [](int lv) -> Monster* { return new Troll(lv); },
  };
  return registry;
}

}

// 플레이어 레벨 기반 랜덤한 종류의 몬스터 생성
Monster* GameManager::RandomSpawnMonster(int player_level) {
  const auto& registry = MonsterRegistry( );
  size_t monster_idx = RandomNumberGenerator::RandomInteger(0, registry.size( ) - 1);

  return registry[monster_idx](player_level);
}

// 전투 진입
void GameManager::Battle(Character* player) {
  system("cls");
  // 몬스터 생성
  Monster* monster = RandomSpawnMonster(player->level());

  // 전투 루프
  while (player->hp() > 0 && monster->health() > 0) {
    // 플레이어 행동 선택 [0: 공격, 1: 아이템 사용]
    int player_behavior = RandomNumberGenerator::RandomInteger(0, 1);
    // 플레이어 행동
    switch (player_behavior) {
    case 0: { // 공격
      int monster_prev_hp = monster->health( );
      player->Attack(monster);
      std::cout << monster->name( ) << "의 HP: " << monster_prev_hp << " -> " << monster->health( ) << std::endl;
      break;
    }
    case 1: {
      //player->UseRandomItem();
      std::cout << "Use Random Item" << std::endl;
      break;
    }
    default: {
      break;
    }
    }

    // 플레이어 행동 종료 후 몬스터 사망시 전투 루프 탈출
    if (monster->health() <= 0) break;

    // 몬스터 공격
    int player_prev_hp = player->hp( );
    monster->Attack(player);
    std::cout << player->name( ) << "의 HP: " << player_prev_hp << " -> " << player->hp( ) << std::endl;
  }

  // 전투 루프 종료. 승리 판정
  // 플레이어 승
  if (player->hp() > 0) {
    std::cout << "플레이어 승리!" << std::endl;
    int earned_exp = 50; // 추후 각 몬스터가 갖는 경험치로 대체.
    int earned_gold = RandomNumberGenerator::RandomInteger(10, 20);
    player->GainExp(earned_exp);
    player->GainGold(earned_gold);

    // 경험치, 골드 획득 로그
    std::cout << player->name( ) << "이(가) " << earned_exp << " EXP와 " << earned_gold << " 골드를 획득했습니다.\n";
    std::cout << "현재 EXP: " << player->exp( ) << "/" << player->max_exp( ) << ", 골드: " << player->gold( ) << std::endl;
    //로그 기록
    Logger* logger = Logger::GetInstance( );
    if ( logger != nullptr )
    {
      logger->RecordMonsterKill(monster->name( ));
    }

    // 아이템 획득
    if ( RandomNumberGenerator::RandomInteger(1, 10) <= 3 ) { // 30% 확률로 획득
      std::cout << "아이템 획득!" << std::endl;
      // [0: HP포션] [1: 공격력 부스트] 중에서 랜덤 획득
      int item_idx = RandomNumberGenerator::RandomInteger(0, 1);
      switch ( item_idx ) {
      case 0: {
        player->AddItem( std::move( std::make_unique<HealthPotion>( ) ) );

        break;
      }
      case 1: {
        player->AddItem( std::move( std::make_unique<AttackBoost>( ) ) );

        break;
      }
      default: {
          
        break;
      }
      }
    }
  }
  // 몬스터 승
  else if (monster->health() > 0) {
    std::cout << player->name() << "이(가) 사망했습니다.." << std::endl;
  }
  // 동시에 죽는 경우? 혹시 몰라서 
  else {
    std::cout << "비정상 동작. 플레이어와 몬스터 동시에 사망" << std::endl;
  }
  
  delete monster;
}

GameManager* GameManager::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = new GameManager();
  }
  return instance_;
}

GameManager* GameManager::instance_ = nullptr;