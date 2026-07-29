#include "game_manager.h"

#include "random_number_generator.h"

#include <iostream>

// 플레이어 레벨 기반 몬스터 생성
Monster* GameManager::GenerateMonster(int player_level) {

}

void GameManager::Battle(Character* player) {
  system("cls");
  // 몬스터 생성
  //Monster* monster = GenerateMonster(player->level());

  // 플레이어 행동 선택 [0: 공격, 1: 아이템 사용]
  int player_behavior = RandomNumberGenerator::RandomInteger(0, 1);

  switch (player_behavior) {
    case 0: {
      // player->Attack(monster);
      std::cout << "Player Attack!" << std::endl;
      break;
    }
    case 1: {
      // player->UseRandomItem();
      std::cout << "Use Random Item" << std::endl;
      break;
    }
    default:
      break;
  }
}

void GameManager::DisplayInventory(Character* player) {

}

GameManager* GameManager::getInstance() {
  if (instance == nullptr) {
    instance = new GameManager();
  }
  return instance;
}

GameManager* GameManager::instance = nullptr;