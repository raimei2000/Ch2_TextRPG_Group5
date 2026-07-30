#include <iostream>
#include <string>

#include "character.h"
#include "monster.h"
#include "item.h"
#include "game_manager.h"
#include "logger.h"

int main() {
  GameManager* game_manager = GameManager::GetInstance( );
  Logger* logger = Logger::GetInstance( );

  // 플레이어 이름 입력 & 플레이어 객체 생성
  std::string player_name;
  std::cout << "플레이어 이름을 입력해주세요: ";
  std::cin >> player_name;
  Character* player = new Character(player_name, logger);
  //player->PrintCreationLog(); // 캐릭터 Hero 생성 완료! 레벨: 1, 체력: 100, 공격력: 10

  // 전투
  
  game_manager->Battle(player);


  return 0;
}