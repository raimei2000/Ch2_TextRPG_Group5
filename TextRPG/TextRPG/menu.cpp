#include "menu.h"
#include "input_utils.h"
#include "shop.h"

#include <Windows.h>

void Menu(Character* player) {
	int choice = 0;
	bool isEndGame = false;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	while ( !isEndGame ) {
		std::cout << "┌──────────────────────────────────────────┐" << std::endl;

		std::cout << "│           ";
		SetConsoleTextAttribute(hConsole, 3);
		std::cout << "🎊​🎊​ 안전지대 🎊​🎊​";
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << "             │" << std::endl; 
		std::cout << "├──────────────────────────────────────────┤" << std::endl;
		std::cout << "│▶ 1. 다음 구역으로 이동 ▶ 2. 인벤토리     │" << std::endl;
		std::cout << "│▶ 3. 스탯               ▶ 4. 무인 상점    │" << std::endl;
		std::cout << "│▶ 5. 기록               ";
		SetConsoleTextAttribute(hConsole, 8);
		std::cout << "▶ 0. 게임 종료";
		SetConsoleTextAttribute(hConsole, 7);
		std::cout << "    │" << std::endl;
		std::cout << "└──────────────────────────────────────────┘" << std::endl;
		std::cout << player->name( ) << "은(는) 무엇을 할까?" << std::endl;
		choice = InputValidator(0, 5);
		switch ( choice ) {
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
			Shop( );
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
			isEndGame = true;
			break;
		}
		}
	}
}

