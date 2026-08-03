#include "game_manager.h"

#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include <chrono>

#include "character.h"
#include "monster.h"
#include "health_potion.h"
#include "attack_boost.h"
#include "random_number_generator.h"
#include "logger.h"
#include "game_utility.h"

// 몬스터 추가시 해당 몬스터의 헤더 포함
#include "goblin.h"
#include "orc.h"
#include "troll.h"

// 보스 몬스터
#include "bossogre.h"

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
bool GameManager::Battle(Character* player)
{
  bool boss_cleared = false;

  system("cls");

  // 보스전 관련
  bool is_boss_battle = false;
  if ( player->level( ) >= 10 ) is_boss_battle = true;

  // 몬스터 생성
  Monster* monster = nullptr;
  if ( is_boss_battle ) monster = new BossOgre( );      // 보스전이면 보스몹 생성
  else monster = RandomSpawnMonster(player->level( ));  // 아니면 잡몹 생성
  monster->SpawnMessage( );

  bool escape = false;
  // 전투 루프
  while (player->hp() > 0 && monster->health() > 0 && !escape) {
    bool player_turn_end = false;
    while ( !player_turn_end ) {
      // 플레이어 행동 선택 [0: 공격, 1: 아이템 사용]
      //int player_behavior = RandomNumberGenerator::RandomInteger(0, 1); // 랜덤 행동 선택
      int player_behavior;
      std::cout << std::endl;
      std::cout << player->name( ) << "은(는) 무엇을 할까?" << std::endl;
      std::cout << "1. 공격     2. 인벤토리   3. 스탯 확인  4. 도망가기" << std::endl;
      std::cout << ">> ";
      std::cin >> player_behavior;

      system("cls");

      // 플레이어 행동
      switch ( player_behavior ) {
      case 1: { // 공격
        int monster_prev_hp = monster->health( );
        player->Attack(monster);

        player_turn_end = true;
        break;
      }
      case 2: { // 아이템 사용
        player->DisplayInventory( );
        if ( player->inventory_size( ) == 0 ) break;
        bool inventory_close = false;
        while ( !inventory_close ) {
          int choice;
          std::cout << "사용할 아이템 번호(돌아가기: 0)" << std::endl;
          std::cout << ">> ";
          std::cin >> choice;
          system("cls");
          if ( 1 <= choice && choice <= player->inventory_size( ) ) { // 유효한 인덱스 입력시
            player->UseItem(choice - 1);
            inventory_close = true;
          }
          else if ( choice == 0 ) inventory_close = true; // 뒤로 돌아가기
          else {
            std::cout << "잘못된 입력입니다." << std::endl;
          }
        }

        // 플레이어의 아이템 사용을 턴 사용으로 한다면 아래 주석 해제.
        // 아이템 사용 후 공격 등의 행동을 다시 할 수 있다면 그대로.
        //player_turn_end = true;
        break;
      }
      case 3: { // 스탯 확인
        player->Status( );

        break;
      }
      case 4: {
        // 보스전이라면 도망가지 못함.
        if ( is_boss_battle ) {
          std::cout << "물러서지마! 맞서 싸워!!" << std::endl;
          break;
        }
        if ( RandomNumberGenerator::RandomInteger(1, 100) <= 85 ) { // 85% 확률. 도망 실패
          std::cout << "도망가자!!" << std::endl;
          std::cout << "도망..";
          for ( int i = 0; i < 3; i++ ) {
            game_utility::Delay(1);
            std::cout << ".";
          }
          game_utility::Delay(2);
          std::cout << "실패!!" << std::endl;
          std::cout << std::endl;

          player_turn_end = true;
        }
        else { // 15% 확률. 도망 성공
          std::cout << "도망가자!!" << std::endl;
          std::cout << "도망..";
          for ( int i = 0; i < 3; i++ ) {
            game_utility::Delay(1);
            std::cout << ".";
          }
          game_utility::Delay(2);
          std::cout << "성공!!" << std::endl;

          player_turn_end = true;
          escape = true;
        }

        break;
      }
      default: {
        break;
      }
      }
    }
    
    // 플레이어 행동 종료 후 [몬스터 사망] or [도망 성공시] 전투 루프 탈출
    if (monster->health() <= 0 || escape) break;

    // 몬스터 공격
    int player_prev_hp = player->hp( );
    monster->Attack(player);
  }

  //공격력 부스트 사용 전 공격력 저장
  const int boosted_power = player->power( );

  //전투 종료시 효과 제거
  player->ClearTemporaryPowerBonus( );

  //공격력이 변경된 경우에만 출력
  if ( boosted_power != player->power( ) ) {
    std::cout << "전투가 종료되어 공격력이 원래대로 돌아왔습니다... (" << boosted_power << "->" << player->power( ) << ")" << std::endl;
  }

  // 전투 루프 종료. 승리 판정
  // 플레이어 승리
  if ( player->hp( ) > 0 && !escape ) {
    monster->DeathMessage( );
    std::cout << "플레이어 승리!" << std::endl;
    int earned_exp = 50; // 추후 각 몬스터가 갖는 경험치로 대체.
    int earned_gold = RandomNumberGenerator::RandomInteger(10, 20);
    player->GainExp(earned_exp);
    player->GainGold(earned_gold);

    if ( is_boss_battle ) {
      boss_cleared = true;
    }

    // 경험치, 골드 획득 로그
    std::cout << player->name( ) << "이(가) " << earned_exp << " EXP와 " << earned_gold << " 골드를 획득했습니다.\n";
    std::cout << "현재 EXP: " << player->exp( ) << "/" << player->max_exp( ) << ", 골드: " << player->gold( ) << std::endl;
    
    // 로그 기록
    Logger* logger = Logger::GetInstance( );
    if ( logger != nullptr ) logger->RecordMonsterKill(monster->name( ));

    // 아이템 획득
    if ( RandomNumberGenerator::RandomInteger(1, 10) <= 3) { // 30% 확률로 획득
      std::cout << "아이템 획득!" << std::endl;
      // [0: HP포션] [1: 공격력 부스트] 중에서 랜덤 획득
      int item_idx = RandomNumberGenerator::RandomInteger(0, 1);
      switch ( item_idx ) {
      case 0: {
        player->AddItem( std::make_unique<HealthPotion>( ) );

        break;
      }
      case 1: {
        player->AddItem( std::make_unique<AttackBoost>( ) );

        break;
      }
      default: {
          
        break;
      }
      }
    }

    // 안전지대로 이동
    game_utility::EnterToClear("[Enter를 눌러 안전지대로 이동]");
  }
  // 플레이어 패배 (몬스터 승리)
  else if (monster->health() > 0 && !escape) {
    std::cout << player->name() << "이(가) 사망했습니다.." << std::endl;
  }
  // 도망 성공
  else if ( escape ) {
    // 안전지대 자동 이동
    game_utility::AutoReturnToSafeZone(3);
  }
  // 동시에 죽는 경우? 혹시 몰라서 
  else {
    std::cout << "비정상 동작. 플레이어와 몬스터 동시에 사망" << std::endl;
  }

  delete monster;
  return boss_cleared;

}

GameManager* GameManager::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = new GameManager();
  }
  return instance_;
}

GameManager* GameManager::instance_ = nullptr;