#include "menu.h"
#include "input_utils.h"
#include "shop.h"

void Menu(Character* player) {
	int choice_ = 0;
	bool isEndGame_ = false;
	while ( !isEndGame_ ) {
		std::cout << "============================\n";
		std::cout << "      *** 메인 메뉴 ***\n";
		std::cout << "============================\n";
		std::cout << "1. 전투 2. 인벤토리 3. 스탯\n";
		std::cout << "4. 상점 5. 통계    0. 게임 종료\n";
		std::cout << "============================\n";
		choice_ = InputValidator(0, 5);
		switch ( choice_ ) {
		case 1: {
			GameManager* game_manager = GameManager::GetInstance( );
			game_manager->Battle(player);
			break;
		}
		case 2: {
			player->DisplayInventory( );
			break;
		}
		case 3: {
			player->status( );
			break;
		}
		case 4: {
			Shop( );
			break;
		}
		case 5: {
			Logger* logger = Logger::GetInstance( );
			logger->Log( );
			break;
		}
		case 0: {
			isEndGame_ = true;
			break;
		}
		}
	}
}
