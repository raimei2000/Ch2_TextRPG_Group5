#include "menu.h"
#include "input_utils.h"
#include "shop.h"

void Menu(Character* player) {
	int choice_ = 0;
	bool isEndGame_ = false;
	while ( !isEndGame_ ) {
		std::cout << "==============================================" << std::endl;
		std::cout << "               *** 안전지대 ***" << std::endl;
		std::cout << "==============================================" << std::endl;
		std::cout << "1. 다음 구역으로 이동 2. 인벤토리 3. 스탯" << std::endl;
		std::cout << "4. 무인 상점          5. 기록     0. 게임 종료" << std::endl;
		std::cout << "==============================================" << std::endl;
		choice_ = InputValidator(0, 5);
		switch ( choice_ ) {
		case 1: {
			//battle 호출
			GameManager* game_manager = GameManager::GetInstance( );
			game_manager->Battle(player);
			break;
		}
		case 2: {
			//인벤토리 호출
			player->DisplayInventory( );
			break;
		}
		case 3: {
			//스탯 호출
			player->Status( );
			break;
		}
		case 4: {
			//상점 호출
			Shop(player);
			break;
		}
		case 5: {
			//로그 호출
			Logger* logger = Logger::GetInstance( );
			logger->Log( );
			break;
		}
		case 0: {
			//게임 종료
			isEndGame_ = true;
			break;
		}
		}
	}
}

