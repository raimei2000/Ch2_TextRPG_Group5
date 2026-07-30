#include "game_manager.h"

#include <iostream>

#include "character.h"
#include "monster.h"
#include "random_number_generator.h"

// 플레이어 레벨 기반 몬스터 생성
Monster* GameManager::GenerateMonster(int player_level) {

}

void GameManager::Battle(Character* player) {
  system("cls");
  // 몬스터 생성
  Monster* monster = GenerateMonster(player->level());

  // 전투 루프
  while (player->hp() > 0 && monster->health() > 0) {
    // 플레이어 행동 선택 [0: 공격, 1: 아이템 사용]
    int player_behavior = RandomNumberGenerator::RandomInteger(0, 1);
    // 플레이어 행동
    switch (player_behavior) {
    case 0: {
      //player->Attack(monster);
      std::cout << "Player Attack!" << std::endl;
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

    // 몬스터 행동
    //monster->Attack(player);
  }

  // 전투 루프 종료. 승리 판정
  // 플레이어 승
  if (player->hp() > 0) {
    player->GainExp(50);
    //player->GainGold(RandomNumberGenerator::RandomInteger(10, 20));
    
    // 아이템 획득
  }
  // 몬스터 승
  else if (monster->health() > 0) {

  }
  // 동시에 죽는 경우? 혹시 몰라서 
  else {
    std::cout << "비정상 동작. 플레이어와 몬스터 동시에 사망" << std::endl;
  }
  
  delete monster;
}

void GameManager::DisplayInventory(Character* player) {

}

GameManager* GameManager::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = new GameManager();
  }
  return instance_;
}

GameManager* GameManager::instance_ = nullptr;