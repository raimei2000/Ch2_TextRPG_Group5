#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

#include "character.h"
#include "monster.h"
#include "item.h"
#include "game_manager.h"
#include "logger.h"
#include "menu.h"
#include "prologue.h"
#include "epilogue.h"

int main() {
  // 인코딩 관련
  SetConsoleCP(CP_UTF8);        // 입력용 
  SetConsoleOutputCP(CP_UTF8);  // 출력용

  GameManager* game_manager = GameManager::GetInstance( );
  Logger* logger = Logger::GetInstance( );

  // 플레이어 이름 입력 & 플레이어 객체 생성
  std::string player_name;
  std::cout << "플레이어 이름을 입력해주세요: ";
  std::cin >> player_name;
  std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
  Character* player = new Character(player_name, logger);
  if ( player_name == "손지협" ) {
    player->Status( );

    std::cout << "손지협 모드 적용 완료! Enter키를 눌러 프롤로그를 시작하세요.";
    std::cin.get( );
  }
  
  system("cls");
  PrintPrologue(player_name);

  // 첫 전투
  game_manager->Battle(player);

  // 메인루프
  Menu(player);

  // 플레이어 사망으로 게임 종료
  if ( player->hp( ) <= 0 ) {
    std::cout << "Game Over.." << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Enter 키를 눌러 게임을 종료합니다.";

  while ( _getch( ) != '\r' ) {
  }
  delete player;
  return 0;
}
